/****************************************************************************************************************************
  SimpleAuthentication.ino - Simple Arduino web server sample
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license
 ***************************************************************************************************************************************/

#include "defines.h"

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int reqCount = 0;                // number of requests received

WiFiWebServer server(80);

//Check if header is present and correct
bool is_authenticated()
{
  Serial.println(F("Enter is_authenticated"));

  if (server.hasHeader(F("Cookie")))
  {
    Serial.print(F("Found cookie: "));
    String cookie = server.header(F("Cookie"));
    Serial.println(cookie);

    if (cookie.indexOf(F("RTLSESSIONID=1")) != -1)
    {
      Serial.println(F("Authentication Successful"));
      return true;
    }
  }

  Serial.println(F("Authentication Failed"));

  return false;
}

//login page, also called for disconnect
void handleLogin()
{
  String msg;

  if (server.hasHeader(F("Cookie")))
  {
    Serial.print(F("Found cookie: "));

    String cookie = server.header(F("Cookie"));
    Serial.println(cookie);
  }

  if (server.hasArg("DISCONNECT"))
  {
    Serial.println(F("Disconnection"));
    server.sendHeader(F("Location"), F("/login"));
    server.sendHeader(F("Cache-Control"), F("no-cache"));
    server.sendHeader(F("Set-Cookie"), F("RTLSESSIONID=0"));
    server.send(301);
    return;
  }

  if (server.hasArg(F("USERNAME")) && server.hasArg(F("PASSWORD")))
  {
    if (server.arg(F("USERNAME")) == "admin" &&  server.arg(F("PASSWORD")) == "password")
    {
      server.sendHeader(F("Location"), F("/"));
      server.sendHeader(F("Cache-Control"), F("no-cache"));
      server.sendHeader(F("Set-Cookie"), F("RTLSESSIONID=1"));
      server.send(301);
      Serial.println(F("Log in Successful"));
      return;
    }

    msg = F("Wrong username/password! try again.");
    Serial.println(F("Log in Failed"));
  }

  String content = F("<html><body><form action='/login' method='POST'>To log in, please use : admin/password<br>");
  content += F("User:<input type='text' name='USERNAME' placeholder='user name'><br>");
  content += F("Password:<input type='password' name='PASSWORD' placeholder='password'><br>");
  content += F("<input type='submit' name='SUBMIT' value='Submit'></form>");
  content += msg;
  content += F("<br>");
  content += F("You also can go <a href='/inline'>here</a></body></html>");

  server.send(200, F("text/html"), content);
}

#define ORIGINAL_STR_LEN        384

//root page can be accessed only if authentication is ok
void handleRoot()
{
  static String content;
  static uint16_t previousStrLen = ORIGINAL_STR_LEN;

  Serial.println(F("Enter handleRoot"));

  if (!is_authenticated())
  {
    server.sendHeader(F("Location"), F("/login"));
    server.sendHeader(F("Cache-Control"), F("no-cache"));
    server.send(301);

    return;
  }

  content = F("<html><body><H2>Hello, you successfully connected to RTL8720DN on ");
  content += BOARD_NAME;
  content += F("!</H2><br>");

  if (server.hasHeader(F("User-Agent")))
  {
    content += F("the user agent used is : ");
    content += server.header(F("User-Agent"));
    content += F("<br><br>");
  }

  content += F("You can access this page until you <a href=\"/login?DISCONNECT=YES\">disconnect</a></body></html>");

  if (content.length() > previousStrLen)
  {
    WS_LOGERROR3(F("String Len > "), previousStrLen, F(", extend to"), content.length() + 48);

    previousStrLen = content.length() + 48;

    content.reserve(previousStrLen);
  }
  else
  {
    WS_LOGDEBUG1(F("Len ="), content.length());
    server.send(200, F("text/html"), content);
  }
}

//no need authentication
void handleNotFound()
{
  String message = F("File Not Found\n\n");

  message += F("URI: ");
  message += server.uri();
  message += F("\nMethod: ");
  message += (server.method() == HTTP_GET) ? F("GET") : F("POST");
  message += F("\nArguments: ");
  message += server.args();
  message += F("\n");

  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, F("text/plain"), message);
}

void setup(void)
{
  Serial.begin(115200);

  while (!Serial);

  Serial.print(F("\nStarting SimpleAuthentication on "));
  Serial.print(BOARD_NAME);
  Serial.print(F(" with "));
  Serial.println(SHIELD_TYPE);
  Serial.println(WIFI_WEBSERVER_RTL8720_VERSION);

  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println(F("WiFi shield not present"));

    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();

  Serial.print("Current Firmware Version = ");
  Serial.println(fv);

  if (fv != LATEST_RTL8720_FIRMWARE)
  {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    // Connect to WPA/WPA2 network. 2.4G and 5G are all OK
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  server.on(F("/"), handleRoot);
  server.on(F("/login"), handleLogin);

  server.on(F("/inline"), []()
  {
    server.send(200, F("text/plain"), F("This works without need of authentication"));
  });

  server.onNotFound(handleNotFound);

  //here the list of headers to be recorded
  const char * headerkeys[] = {"User-Agent", "Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys) / sizeof(char*);

  //ask server to track these headers
  server.collectHeaders(headerkeys, headerkeyssize);
  server.begin();

  Serial.print(F("HTTP server started @ "));
  Serial.println(WiFi.localIP());
}

void loop(void)
{
  server.handleClient();
}

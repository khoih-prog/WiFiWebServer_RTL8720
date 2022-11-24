/****************************************************************************************************************************
  HTTPBasicAuth.h - Simple Arduino web server sample
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license
 ***************************************************************************************************************************************/

#include "defines.h"

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int reqCount = 0;                // number of requests received

WiFiWebServer server(80);

const char* www_username = "admin";
const char* www_password = "wifinina";

void setup()
{
  Serial.begin(115200);

  while (!Serial);

  Serial.print(F("\nStarting HTTPBasicAuth on "));
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

  server.on(F("/"), []()
  {
    if (!server.authenticate(www_username, www_password))
    {
      return server.requestAuthentication();
    }

    server.send(200, F("text/plain"), F("Login OK"));
  });

  server.begin();

  Serial.print(F("Open http://"));
  Serial.print(WiFi.localIP());
  Serial.println(F("/ in your browser to see it working"));

  Serial.print(F("To login, use Username = "));
  Serial.print(www_username);
  Serial.print(F(", Password = "));
  Serial.println(www_password);
}

void loop()
{
  server.handleClient();
}

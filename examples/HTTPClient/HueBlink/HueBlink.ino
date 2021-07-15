/****************************************************************************************************************************
  HueBlink.ino - Simple Arduino web server sample

  For RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Uses HttpClient to control Philips Hue
  For more on Hue developer API see http://developer.meethue.com

  To control a light, the Hue expects a HTTP PUT request to:

  http://hue.hub.address/api/hueUserName/lights/lightNumber/state

  The body of the PUT request looks like this:
  {"on": true} or {"on":false}

  This example  shows how to concatenate Strings to assemble the
  PUT request and the body of the request.

  modified 15 Feb 2016
  by Tom Igoe (tigoe) to match new API
 *****************************************************************************************************************************/

#include "defines.h"

char hueHubIP[]     = "192.168.2.223";            // IP address of the HUE bridge
String hueUserName  = "huebridgeusername";        // hue bridge username

WiFiClient      client;
WiFiHttpClient  httpClient(client, hueHubIP);

int status = WL_IDLE_STATUS;     // the Wifi radio's status

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(WiFi.localIP());

  Serial.print(F("SSID: "));
  Serial.print(WiFi.SSID());

  // print the received signal strength:
  int32_t rssi = WiFi.RSSI();
  Serial.print(F(", Signal strength (RSSI):"));
  Serial.print(rssi);
  Serial.println(F(" dBm"));
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print(F("\nStarting HueBlink on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(WIFI_WEBSERVER_RTL8720_VERSION);

  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();

  Serial.print("Current Firmware Version = "); Serial.println(fv);
  
  if (fv != LATEST_RTL8720_FIRMWARE) 
  {
    Serial.println("Please upgrade the firmware");
  }
  
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) 
  {
    Serial.print("Attempting to connect to SSID: "); Serial.println(ssid);
    
    // Connect to WPA/WPA2 network. 2.4G and 5G are all OK
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data
  printWifiStatus();
}

void sendRequest(int light, String cmd, String value) 
{
  // make a String for the HTTP request path:
  String request = "/api/" + hueUserName;
  request += "/lights/";
  request += light;
  request += "/state/";

  String contentType = "application/json";

  // make a string for the JSON command:
  String hueCmd = "{\"" + cmd;
  hueCmd += "\":";
  hueCmd += value;
  hueCmd += "}";
  
  // see what you assembled to send:
  Serial.print("PUT request to server: ");
  Serial.println(request);
  Serial.print("JSON command to server: ");

  // make the PUT request to the hub:
  httpClient.put(request, contentType, hueCmd);

  // read the status code and body of the response
  int statusCode = httpClient.responseStatusCode();
  String response = httpClient.responseBody();

  Serial.println(hueCmd);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Server response: ");
  Serial.println(response);
  Serial.println();
}

void loop()
{
  sendRequest(3, "on", "true");   // turn light on
  delay(2000);                    // wait 2 seconds
  sendRequest(3, "on", "false");  // turn light off
  delay(2000);                    // wait 2 seconds
}

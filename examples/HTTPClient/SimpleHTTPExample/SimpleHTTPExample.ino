/****************************************************************************************************************************
  SimpleHTTPExample.ino - Simple Arduino web server sample

  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"

// This example downloads the URL "http://arduino.cc/"
// Name of the server we want to connect to
const char kHostname[] = "arduino.tips";

// Path to download (this is the bit after the hostname in the URL
// that you want to download
const char kPath[] = "/asciilogo.txt";

// Number of milliseconds to wait without receiving any data before we give up
#define NETWORK_TIMEOUT_MS      30000L

// Number of milliseconds to wait if no data is available before trying again
#define NETWORK_RETRY_MS        1000L

WiFiClient      client;
WiFiHttpClient  httpClient(client, kHostname);

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

  Serial.print(F("\nStarting SimpleHTTPExample on "));
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

  // you're connected now, so print out the data
  printWifiStatus();
}

void loop()
{
  int err = 0;

  err = httpClient.get(kPath);

  if (err == 0)
  {
    Serial.println("startedRequest ok");

    err = httpClient.responseStatusCode();

    if (err >= 0)
    {
      Serial.print("Got status code: ");
      Serial.println(err);

      // Usually you'd check that the response code is 200 or a
      // similar "success" code (200-299) before carrying on,
      // but we'll print out whatever response we get

      err = httpClient.skipResponseHeaders();

      if (err >= 0)
      {
        int bodyLen = httpClient.contentLength();
        Serial.print("Content length is: ");
        Serial.println(bodyLen);
        Serial.println();
        Serial.println("Body returned follows:");

        // Now we've got to the body, so we can print it out
        unsigned long timeoutStart = millis();

        // Whilst we haven't timed out & haven't reached the end of the body
        while ( (httpClient.connected() || httpClient.available()) &&
                ((millis() - timeoutStart) < NETWORK_TIMEOUT_MS) )
        {
          if (httpClient.available())
          {
            Serial.print((char) httpClient.read());

            bodyLen--;

            // We read something, reset the timeout counter
            timeoutStart = millis();
          }
          else
          {
            // We haven't got any data, so let's pause to allow some to
            // arrive
            delay(NETWORK_RETRY_MS);
          }
        }
      }
      else
      {
        Serial.print("Failed to skip response headers: ");
        Serial.println(err);
      }
    }
    else
    {
      Serial.print("Getting response failed: ");
      Serial.println(err);
    }
  }
  else
  {
    Serial.print("Connect failed: ");
    Serial.println(err);
  }

  httpClient.stop();

  // And just stop, now that we've tried a download
  while (1);
}

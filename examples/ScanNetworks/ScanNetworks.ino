/****************************************************************************************************************************
  ScanNetworks.ino - Simple Arduino web server sample
  For RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license
  
  This example  prints the Wifi shield's MAC address, and
  scans for available Wifi networks using the Wifi shield.
  Every ten seconds, it scans again. It doesn't actually
  connect to any network, so no encryption scheme is specified.
  
  For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
 ***************************************************************************************************************************************/

#include "defines.h"

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int reqCount = 0;                // number of requests received

void printMacAddress()
{
  // get your MAC address
  byte mac[6];
  WiFi.macAddress(mac);

  // print MAC address
  char buf[20];
  sprintf(buf, "%02X:%02X:%02X:%02X:%02X:%02X", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
  Serial.print("MAC address: ");
  Serial.println(buf);
}

void listNetworks()
{
  // scan for nearby networks
  int numSsid = WiFi.scanNetworks();

  if (numSsid == -1)
  {
    Serial.println(F("Couldn't get a wifi connection"));
    while (true);
  }

  // print the list of networks seen
  Serial.print(F("Number of available networks:"));
  Serial.println(numSsid);

  // print the network number and name for each network found
  for (int thisNet = 0; thisNet < numSsid; thisNet++) 
  {
    Serial.print(thisNet);
    Serial.print(F(") "));
    Serial.print(WiFi.SSID(thisNet));
    Serial.print(F("\tSignal: "));
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(F(" dBm"));

    Serial.print(F("\tEncryption: "));
    printEncryptionType(WiFi.encryptionType(thisNet));
  }
}

void printEncryptionType(int thisType)
{
  // read the encryption type and print out the name
  switch (thisType)
  {
    case AUTH_MODE_WPA_PSK:
      Serial.print(F("WPA_PSK"));
      break;
    case AUTH_MODE_WPA2_PSK:
      Serial.print(F("WPA2_PSK"));
      break;
    case AUTH_MODE_WPA:
      Serial.print(F("WPA"));
      break;
    case AUTH_MODE_WPA2:
      Serial.print(F("WPA2"));
      break;           
    case AUTH_MODE_AUTO:
      Serial.print(F("Auto"));
      break;
    case AUTH_MODE_SHARED_KEY:
      Serial.print(F("Shared Key"));
      break;      
    case AUTH_MODE_OPEN_SYSTEM:
      Serial.print(F("Open"));
      break;
    case AUTH_MODE_INVALID:
      Serial.print(F("Invalid"));
      break;      
  }
  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print(F("\nStarting ScanNetworks on ")); Serial.print(BOARD_NAME);
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

  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(WiFi.localIP());

  // Print WiFi MAC address
  printMacAddress();
}

void loop()
{
  // scan for existing networks
  Serial.println();
  Serial.println(F("Scanning available networks..."));
  listNetworks();
  delay(10000);
}

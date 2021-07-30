## WiFiWebServer_RTL8720

[![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer_RTL8720.svg?)](https://www.ardu-badge.com/WiFiWebServer_RTL8720)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiWebServer_RTL8720.svg)](https://github.com/khoih-prog/WiFiWebServer_RTL8720/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WiFiWebServer_RTL8720/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WiFiWebServer_RTL8720.svg)](http://github.com/khoih-prog/WiFiWebServer_RTL8720/issues)

---
---

## Table of Contents

* [Why do we need this WiFiWebServer_RTL8720 library](#why-do-we-need-this-wifiwebserver_rtl8720-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
* [Changelog](#changelog)
  * [Initial Releases v1.0.0](#initial-releases-v100)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Usage](#usage) 
  * [Class Constructor](#class-constructor) 
  * [Basic Operations](#basic-operations) 
  * [Advanced Options](#advanced-options) 
  * [Other Function Calls](#other-function-calls) 
* [Examples](#examples)
  * [Original Examples](#original-examples) 
    * [ 1. AdvancedWebServer](examples/AdvancedWebServer)
    * [ 2. ConnectWPA](examples/ConnectWPA)
    * [ 3. HelloServer](examples/HelloServer)
    * [ 4. HelloServer2](examples/HelloServer2)
    * [ 5. HttpBasicAuth](examples/HttpBasicAuth)
    * [ 6. **MQTTClient_Auth**](examples/MQTTClient_Auth)
    * [ 7. **MQTTClient_Basic**](examples/MQTTClient_Basic)
    * [ 8. **MQTT_ThingStream**](examples/MQTT_ThingStream)
    * [ 9. PostServer](examples/PostServer)
    * [10. ScanNetworks](examples/ScanNetworks)
    * [11. SimpleAuthentication](examples/SimpleAuthentication)
    * [12. UdpNTPClient](examples/UdpNTPClient)
    * [13. UdpSendReceive](examples/UdpSendReceive)
    * [14. WebClient](examples/WebClient) 
    * [15. WebClientRepeating](examples/WebClientRepeating)
    * [16. WebServer](examples/WebServer)
    * [17. WiFiUdpNtpClient](examples/WiFiUdpNtpClient).
  * [HTTP and WebSocket Client New Examples](#http-and-websocket-client-new-examples) 
    * [ 1. BasicAuthGet](examples/HTTPClient/BasicAuthGet)
    * [ 2. CustomHeader](examples/HTTPClient/CustomHeader)
    * [ 3. DweetGet](examples/HTTPClient/DweetGet)
    * [ 4. DweetPost](examples/HTTPClient/DweetPost)
    * [ 5. HueBlink](examples/HTTPClient/HueBlink)
    * [ 6. node_test_server](examples/HTTPClient/node_test_server)
    * [ 7. PostWithHeaders](examples/HTTPClient/PostWithHeaders)
    * [ 8. SimpleDelete](examples/HTTPClient/SimpleDelete)
    * [ 9. SimpleGet](examples/HTTPClient/SimpleGet)
    * [10. SimpleHTTPExample](examples/HTTPClient/SimpleHTTPExample)
    * [11. SimplePost](examples/HTTPClient/SimplePost)
    * [12. SimplePut](examples/HTTPClient/SimplePut)
    * [13. SimpleWebSocket](examples/HTTPClient/SimpleWebSocket)
* [Example AdvancedWebServer](#example-advancedwebserver)
  * [1. File AdvancedWebServer.ino](#1-file-advancedwebserverino)
  * [2. File defines.h](#2-file-definesh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AdvancedWebServer on Rtlduino RTL8720DN](#1-advancedwebserver-on-rtlduino-rtl8720dn)
  * [2. WebClient on Rtlduino RTL8720DN](#2-webclient-on-rtlduino-rtl8720dn)
  * [3. ScanNetworks on Rtlduino RTL8720DN](#3-scannetworks-on-rtlduino-rtl8720dn)
  * [4. MQTTClient_Auth on Rtlduino RTL8720DN](#4-mqttclient_auth-on-rtlduino-rtl8720dn)
  * [5. MQTT_ThingStream on Rtlduino RTL8720DN](#5-mqtt_thingstream-on-rtlduino-rtl8720dn)
  * [6. WiFiUdpNTPClient on Rtlduino RTL8720DN](#6-wifiudpntpclient-on-rtlduino-rtl8720dn)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [WiFiWebServer_RTL8720 library](https://github.com/khoih-prog/WiFiWebServer_RTL8720)

#### Features

This [WiFiWebServer_RTL8720 library](https://github.com/khoih-prog/WiFiWebServer_RTL8720) is a simple yet complete WebServer library for **Realtek RTL8720DN, RTL8722DM and RTM8722CSM boards**. 

The functions are similar and compatible to those of [`ESP32 WebServer`](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer) and [`ESP8266WebServer`](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer) libraries to make life much easier to port sketches from ESP8266/ESP32.

This [**WiFiWebServer_RTL8720 library**](https://github.com/khoih-prog/WiFiWebServer_RTL8720) also provides high-level **HTTP and WebSocket Client** with the functions are similar and compatible to those of [**ArduinoHttpClient Library**](https://github.com/arduino-libraries/ArduinoHttpClient)

The library provides supports to:

1. WiFi Client, STA and AP mode
2. TCP Server and Client
3. UDP Server and Client
4. HTTP Server and Client
5. HTTP GET and POST requests, provides argument parsing, handles one client at a time.
6. **High-level HTTP (GET, POST, PUT, PATCH, DELETE) and WebSocket Client**.

It is based on and modified from:

1. [Ivan Grokhotkov's ESP8266WebServer](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)
2. [Ivan Grokhotkov's ESP32 WebServer](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer)
3. [ArduinoHttpClient Library](https://github.com/arduino-libraries/ArduinoHttpClient)

The `WiFiWebServer` class found in `WiFiWebServer_RTL8720.h` header, is a simple web server that knows how to handle HTTP requests such as GET and POST and can only support one client at a time.

---

#### Currently Supported Boards

This [**WiFiWebServer_RTL8720 library**](https://github.com/khoih-prog/WiFiWebServer_RTL8720) currently supports these following boards:

1. Realtek **RTL8720DN, RTL8722DM and RTM8722CSM**


---
---

## Changelog


#### Initial Releases v1.0.0

This is simple yet complete WebServer library for `Realtek RTL8720DN, RTL8722DM and RTM8722CSM` boards. **The functions are similar and compatible to ESP8266/ESP32 WebServer libraries** to make life much easier to port sketches from ESP8266/ESP32.

---

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino AmebaD core 3.0.8+`](https://github.com/ambiot/ambd_arduino) for Realtek RTL8720DN, RTL8722DM and RTM8722CSM. [![GitHub release](https://img.shields.io/github/release/ambiot/ambd_arduino.svg)](https://github.com/ambiot/ambd_arduino/releases/latest)

 3. [`Functional-VLPP library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)


---

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for [**WiFiWebServer_RTL8720**](https://github.com/khoih-prog/WiFiWebServer_RTL8720), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer_RTL8720.svg?)](https://www.ardu-badge.com/WiFiWebServer_RTL8720) for more detailed instructions.

### Manual Install

1. Navigate to [**WiFiWebServer_RTL8720**](https://github.com/khoih-prog/WiFiWebServer_RTL8720) page.
2. Download the latest release `WiFiWebServer_RTL8720-main.zip`.
3. Extract the zip file to `WiFiWebServer_RTL8720-main` directory 
4. Copy the whole `WiFiWebServer_RTL8720-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**WiFiWebServer_RTL8720** library](https://platformio.org/lib/show/12562/WiFiWebServer_RTL8720) by using [Library Manager](https://platformio.org/lib/show/12562/WiFiWebServer_RTL8720/installation). Search for **WiFiWebServer_RTL8720** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---


### Usage

#### Class Constructor

```cpp
  WiFiWebServer server(80);
```

Creates the WiFiWebServer class object.

*Parameters:* 
 
host port number: ``int port`` (default is the standard HTTP port 80)

---

#### Basic Operations

**Starting the server**

```cpp
  void begin();
```

**Handling incoming client requests**

```cpp
  void handleClient();
```

**Disabling the server**

```cpp
  void close();
  void stop();
```

Both methods function the same

**Client request handlers**

```cpp
  void on();
  void addHandler();
  void onNotFound();
  void onFileUpload();	
```

Example:

```cpp
  server.on("/", handlerFunction);
  server.onNotFound(handlerFunction);   // called when handler is not assigned
  server.onFileUpload(handlerFunction); // handle file uploads
```

**Sending responses to the client**

```cpp
  void send();
  void send_P();
```

`Parameters:`

`code` - HTTP response code, can be `200` or `404`, etc.

`content_type` - HTTP content type, like `"text/plain"` or `"image/png"`, etc.

`content` - actual content body

---

#### Advanced Options

**Getting information about request arguments**

```cpp
  const String & arg();
  const String & argName();
  int   args();
  bool  hasArg();
```

`Function usage:`

`arg` - get request argument value, use `arg("plain")` to get POST body
	
`argName` - get request argument name
	
`args` - get arguments count
	
`hasArg` - check if argument exist

**Getting information about request headers**

```cpp
  const String & header();
  const String & headerName();
  const String & hostHeader();
  int   headers();
  bool  hasHeader();
``` 
`Function usage:`

`header` - get request header value

`headerName` - get request header name

`hostHeader` - get request host header if available, else empty string
  
`headers` - get header count
	
`hasHeader` - check if header exist

**Authentication**

```cpp
  bool authenticate();
  void requestAuthentication();
```

`Function usage:`

`authenticate` - server authentication, returns true if client is authenticated else false

`requestAuthentication` - sends authentication failure response to the client

`Example Usage:`

```cpp

  if(!server.authenticate(username, password))
  {
    server.requestAuthentication();
  }
```
---

#### Other Function Calls

```cpp
  const String& uri(); // get the current uri
  HTTPMethod    method(); // get the current method 
  WiFiClient    client(); // get the current client
  HTTPUpload&   upload(); // get the current upload
  
  void setContentLength(); // set content length
  void sendHeader(); // send HTTP header
  void sendContent(); // send content
  void sendContent_P(); 
  void collectHeaders(); // set the request headers to collect
  void serveStatic();
  
  size_t streamFile();
```

---
---

### Examples:

#### Original Examples

 1. [AdvancedWebServer](examples/AdvancedWebServer)
 2. [ConnectWPA](examples/ConnectWPA)
 3. [HelloServer](examples/HelloServer)
 4. [HelloServer2](examples/HelloServer2)
 5. [HttpBasicAuth](examples/HttpBasicAuth)
 6. [**MQTTClient_Auth**](examples/MQTTClient_Auth)
 7. [**MQTTClient_Basic**](examples/MQTTClient_Basic)
 8. [**MQTT_ThingStream**](examples/MQTT_ThingStream)
 9. [PostServer](examples/PostServer)
10. [ScanNetworks](examples/ScanNetworks)
11. [SimpleAuthentication](examples/SimpleAuthentication)
12. [UdpNTPClient](examples/UdpNTPClient)
13. [UdpSendReceive](examples/UdpSendReceive)
14. [WebClient](examples/WebClient)
15. [WebClientRepeating](examples/WebClientRepeating)
16. [WebServer](examples/WebServer)
17. [WiFiUdpNtpClient](examples/WiFiUdpNtpClient)


#### HTTP and WebSocket Client New Examples

 1. [BasicAuthGet](examples/HTTPClient/BasicAuthGet)
 2. [CustomHeader](examples/HTTPClient/CustomHeader)
 3. [DweetGet](examples/HTTPClient/DweetGet)
 4. [DweetPost](examples/HTTPClient/DweetPost)
 5. [HueBlink](examples/HTTPClient/HueBlink)
 6. [node_test_server](examples/HTTPClient/node_test_server)
 7. [PostWithHeaders](examples/HTTPClient/PostWithHeaders)
 8. [SimpleDelete](examples/HTTPClient/SimpleDelete)
 9. [SimpleGet](examples/HTTPClient/SimpleGet)
10. [SimpleHTTPExample](examples/HTTPClient/SimpleHTTPExample)
11. [SimplePost](examples/HTTPClient/SimplePost)
12. [SimplePut](examples/HTTPClient/SimplePut)
13. [SimpleWebSocket](examples/HTTPClient/SimpleWebSocket)

---

### Example [AdvancedWebServer](examples/AdvancedWebServer)

#### 1. File [AdvancedWebServer.ino](examples/AdvancedWebServer/AdvancedWebServer.ino)


```cpp
#include "defines.h"

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int reqCount = 0;                // number of requests received

WiFiWebServer server(80);

const int led = 13;

void handleRoot()
{
#define BUFFER_SIZE     500

  digitalWrite(led, 1);
  char temp[BUFFER_SIZE];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  int day = hr / 24;

  hr = hr % 24;

  snprintf(temp, BUFFER_SIZE - 1,
           "<html>\
<head>\
<meta http-equiv='refresh' content='5'/>\
<title>%s</title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<h1>Hello from %s</h1>\
<h3>running WiFiWebServer</h3>\
<h3>on %s</h3>\
<p>Uptime: %d d %02d:%02d:%02d</p>\
<img src=\"/test.svg\" />\
</body>\
</html>", BOARD_NAME, BOARD_NAME, SHIELD_TYPE, day, hr, min % 60, sec % 60);

  server.send(200, F("text/html"), temp);
  digitalWrite(led, 0);
}

void handleNotFound()
{
  digitalWrite(led, 1);

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

  digitalWrite(led, 0);
}

void drawGraph()
{
  String out;
  out.reserve(3000);
  char temp[70];

  out += F("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n");
  out += F("<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"3\" stroke=\"rgb(0, 0, 0)\" />\n");
  out += F("<g stroke=\"blue\">\n");
  int y = rand() % 130;

  for (int x = 10; x < 300; x += 10)
  {
    int y2 = ( rand() ) % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 140 - y, x + 10, 140 - y2);
    out += temp;
    y = y2;
  }
  out += F("</g>\n</svg>\n");

  server.send(200, F("image/svg+xml"), out);
}

void setup(void)
{
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  Serial.begin(115200);
  while (!Serial);

  Serial.print(F("\nStarting AdvancedServer on ")); Serial.print(BOARD_NAME);
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

  server.on(F("/"), handleRoot);
  server.on(F("/test.svg"), drawGraph);
  server.on(F("/inline"), []()
  {
    server.send(200, F("text/plain"), F("This works as well"));
  });

  server.onNotFound(handleNotFound);

  server.begin();

  Serial.print(F("HTTP server started @ "));
  Serial.println(WiFi.localIP());
}

void loop(void)
{
  server.handleClient();
}
```

#### 2. File [defines.h](examples/AdvancedWebServer/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#if !defined(CONFIG_PLATFORM_8721D)
  #error Only for Ameba Realtek RTL8720DN, RTL8722DM and RTM8722CSM platform.
#endif

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             3

#define BOARD_TYPE      "Rtlduino RTL8720DN"

#ifndef BOARD_NAME
  #if defined(ARDUINO_BOARD)
    #define BOARD_NAME    ARDUINO_BOARD
  #elif defined(BOARD_TYPE)
    #define BOARD_NAME    BOARD_TYPE
  #else
    #define BOARD_NAME    "Unknown Board"
  #endif  
#endif

#define SHIELD_TYPE       "RTL8720DN"

#include <WiFiWebServer_RTL8720.h>

char ssid[] = "****";        // your network SSID (name)
char pass[] = "****";        // your network password

#endif    //defines_h
```

---
---

### Debug Terminal Output Samples

#### 1. AdvancedWebServer on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**AdvancedWebServer**](examples/AdvancedWebServer) on **Rtlduino RTL8720DN**

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiWebServer_RTL8720/blob/main/pics/AdvancedWebServer.png">
</p>

```

Starting AdvancedServer on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.0.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
HTTP server started @ 192.168.2.152
```

---

#### 2. WebClient on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**WebClient**](examples/WebClient) on **Rtlduino RTL8720DN**


```
Starting WebClient on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.0.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
You're connected to the network, IP = 192.168.2.152
SSID: HueNet_5G, Signal strength (RSSI):-26 dBm

Starting connection to server...
Connected to server
HTTP/1.1 200 OK
Server: nginx/1.4.2
Date: Thu, 15 Jul 2021 01:46:26 GMT
Content-Type: text/plain
Content-Length: 2263
Last-Modified: Wed, 02 Oct 2013 13:46:47 GMT
Connection: close
Vary: Accept-Encoding
ETag: "524c23c7-8d7"
Accept-Ranges: bytes


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;  
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:  
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;   
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;    
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:     
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;;       
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;   
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;  
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;  
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;  
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;  
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;   

Disconnecting from server...
```

---

#### 3. ScanNetworks on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**ScanNetworks**](examples/ScanNetworks) on **Rtlduino RTL8720DN**

```
Starting ScanNetworks on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.0.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
You're connected to the network, IP = 192.168.2.152
MAC address: 69:4E:06:60:C9:94

Scanning available networks...
Number of available networks:19
0) HueNet	Signal: -26 dBm	Encryption: WPA2_PSK
1) HueNet_5G	Signal: -32 dBm	Encryption: WPA2_PSK
2) HueNetTek	Signal: -32 dBm	Encryption: WPA2_PSK
3) HueNetTek_5G	Signal: -33 dBm	Encryption: WPA2_PSK
4) HueNet1	Signal: -36 dBm	Encryption: WPA2_PSK
5) HueNet2	Signal: -58 dBm	Encryption: WPA2_PSK
6) HueNet2_5G	Signal: -60 dBm	Encryption: WPA2_PSK
7) guest_24	Signal: -64 dBm	Encryption: WPA2_PSK
8) bacau	Signal: -65 dBm	Encryption: WPA2_PSK
9) guest_5	Signal: -77 dBm	Encryption: WPA2_PSK
10) pitesti	Signal: -77 dBm	Encryption: WPA2_PSK 
```

---

#### 4. MQTTClient_Auth on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**MQTTClient_Auth**](examples/MQTTClient_Auth) on **Rtlduino RTL8720DN**


```
Starting MQTTClient_Auth on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.0.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
Connected! IP address: 192.168.2.152
Attempting MQTT connection to broker.emqx.io...connected
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on Rtlduino RTL8720DN with RTL8720DN
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on Rtlduino RTL8720DN with RTL8720DN
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on Rtlduino RTL8720DN with RTL8720DN
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on Rtlduino RTL8720DN with RTL8720DN
```

---

#### 5. MQTT_ThingStream on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**MQTT_ThingStream**](examples/MQTT_ThingStream) on **Rtlduino RTL8720DN**


```
Start MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.0.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
Connected! IP address: 192.168.2.152
***************************************
STM32_Pub
***************************************
Attempting MQTT connection to broker.emqx.io
...connected
Published connection message successfully!
Subcribed to: STM32_Sub
MQTT Message Send : STM32_Pub => Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message receive [STM32_Pub] Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message Send : STM32_Pub => Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message receive [STM32_Pub] Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message Send : STM32_Pub => Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message receive [STM32_Pub] Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message Send : STM32_Pub => Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
MQTT Message receive [STM32_Pub] Hello from MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
```

---

#### 6. WiFiUdpNTPClient on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**WiFiUdpNTPClient**](examples/WiFiUdpNTPClient) on **Rtlduino RTL8720DN**


```
Starting WiFiUdpNTPClient on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.0.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
Connected! IP address: 192.168.2.152
SSID: HueNet1, Signal strength (RSSI):-39 dBm
Starting connection to server...
Listening on port 2390
packet received
Seconds since Jan 1 1900 = 3835239949
Unix time = 1626251149
The UTC time is 8:25:49
packet received
Seconds since Jan 1 1900 = 3835239960
Unix time = 1626251160
The UTC time is 8:26:00
packet received
Seconds since Jan 1 1900 = 3835239971
Unix time = 1626251171
The UTC time is 8:26:11
```

---
---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _WIFI_LOGLEVEL_ to 0

```cpp
// Use this to output debug msgs to Serial
#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             1
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, applying Libraries' Patches, Packages' Patches or this library latest version.


---
---


## Releases

#### Initial Releases v1.0.0

This is simple yet complete WebServer library for `Realtek RTL8720DN, RTL8722DM and RTM8722CSM` boards. **The functions are similar and compatible to ESP8266/ESP32 WebServer libraries** to make life much easier to port sketches from ESP8266/ESP32.

---
---

This [WiFiWebServer_RTL8720 library](https://github.com/khoih-prog/WiFiWebServer_RTL8720) currently supports these following boards:

1. Realtek **RTL8720DN, RTL8722DM and RTM8722CSM**

---

The library provides supports to:

1. WiFi Client, STA and AP mode
2. TCP Server and Client
3. UDP Server and Client
4. HTTP Server and Client
5. HTTP GET and POST requests, provides argument parsing, handles one client at a time.
6. **High-level HTTP (GET, POST, PUT, PATCH, DELETE) and WebSocket Client**.

---
---

### Issues

Submit issues to: [WiFiWebServer_RTL8720 issues](https://github.com/khoih-prog/WiFiWebServer_RTL8720/issues)

---

### TO DO
1. Bug Searching and Killing
2. Add SSL/TLS Client


### DONE

 1. Add support to Realtek RTL8720DN, RTL8722DM and RTM8722CSM
 2. Add **High-level HTTP (GET, POST, PUT, PATCH, DELETE) and WebSocket Client**


---
---

## Contributions and Thanks

1. Based on and modified from [**Ivan Grokhotkov's ESP8266WebServer**](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)
2. [Adrian McEwen](https://github.com/amcewen) for [HttpClient Library](https://github.com/amcewen/HttpClient) on which the [ArduinoHttpClient Library](https://github.com/arduino-libraries/ArduinoHttpClient) and this [EthernetWebServer library](https://github.com/khoih-prog/EthernetWebServer) are relied.

<table>
  <tr>
    <td align="center"><a href="https://github.com/igrr"><img src="https://github.com/igrr.png" width="100px;" alt="igrr"/><br /><sub><b>⭐️⭐️ Ivan Grokhotkov</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/amcewen"><img src="https://github.com/amcewen.png" width="100px;" alt="amcewen"/><br /><sub><b>⭐️ Adrian McEwen</b></sub></a><br /></td>
  </tr> 
</table>

---

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/WiFiWebServer_RTL8720/blob/main/LICENSE)

---

## Copyright

Copyright 2021- Khoi Hoang



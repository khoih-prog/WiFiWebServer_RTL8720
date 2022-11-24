## WiFiWebServer_RTL8720 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer_RTL8720.svg?)](https://www.ardu-badge.com/WiFiWebServer_RTL8720)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiWebServer_RTL8720.svg)](https://github.com/khoih-prog/WiFiWebServer_RTL8720/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WiFiWebServer_RTL8720/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WiFiWebServer_RTL8720.svg)](http://github.com/khoih-prog/WiFiWebServer_RTL8720/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>
<a href="https://profile-counter.glitch.me/khoih-prog/count.svg" title="Total khoih-prog Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog/count.svg" style="height: 30px;width: 200px;"></a>
<a href="https://profile-counter.glitch.me/khoih-prog-WiFiWebServer_RTL8720/count.svg" title="WiFiWebServer_RTL8720 Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog-WiFiWebServer_RTL8720/count.svg" style="height: 30px;width: 200px;"></a>


---
---

## Table of Contents

* [Why do we need this WiFiWebServer_RTL8720 library](#why-do-we-need-this-wifiwebserver_rtl8720-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For RTL8720DN boards using AmebaD core](#1-for-rtl8720dn-boards-using-amebad-core)
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

This [WiFiWebServer_RTL8720 library](https://github.com/khoih-prog/WiFiWebServer_RTL8720) is a simple yet complete WebServer library for **Realtek RTL8720DN, RTL8722DM and RTL8722CSM boards**. 

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

1. Realtek **RTL8720DN, RTL8722DM and RTL8722CSM**

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AmebaD core 3.1.4+`](https://github.com/ambiot/ambd_arduino) for Realtek RTL8720DN, RTL8722DM and RTL8722CSM. [![GitHub release](https://img.shields.io/github/release/ambiot/ambd_arduino.svg)](https://github.com/ambiot/ambd_arduino/releases/latest)
 3. [`Functional-Vlpp library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)


---
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

### Packages' Patches

#### 1. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.1.4. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/ambd/avr/pgmspace.h`


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

https://github.com/khoih-prog/WiFiWebServer_RTL8720/blob/74723f4d6f07671dc33d9d6421eea8f537bf01af/examples/AdvancedWebServer/AdvancedWebServer.ino#L40-L245


#### 2. File [defines.h](examples/AdvancedWebServer/defines.h)


https://github.com/khoih-prog/WiFiWebServer_RTL8720/blob/74723f4d6f07671dc33d9d6421eea8f537bf01af/examples/AdvancedWebServer/defines.h#L11-L42


---
---

### Debug Terminal Output Samples

#### 1. AdvancedWebServer on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**AdvancedWebServer**](examples/AdvancedWebServer) on **Rtlduino RTL8720DN**

<p align="center">
    <img src="https://github.com/khoih-prog/WiFiWebServer_RTL8720/raw/main/pics//AdvancedWebServer.png">
</p>

```cpp
Starting AdvancedServer on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
interface 0 is initialized
interface 1 is initialized
Initializing WIFI ...
WIFI initialized
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet1
RTL8721D[Driver]: set ssid [HueNet1] 
RTL8721D[Driver]: rtw_set_wpa_ie[1160]: AuthKeyMgmt = 0x2 
RTL8721D[Driver]: rtw_restruct_sec_ie[4225]: no pmksa cached 
RTL8721D[Driver]: start auth to 68:7f:74:94:f4:a5
RTL8721D[Driver]: auth alg = 2
RTL8721D[Driver]: 
OnAuthClient:algthm = 0, seq = 2, status = 0, sae_msg_len = 11
RTL8721D[Driver]: auth success, start assoc
RTL8721D[Driver]: association success(res=1)
RTL8721D[Driver]: ClientSendEAPOL[1624]: no use cache pmksa 
RTL8721D[Driver]: ClientSendEAPOL[1624]: no use cache pmksa 
RTL8721D[Driver]: set pairwise key to hw: alg:4(WEP40-1 WEP104-5 TKIP-2 AES-4)
RTL8721D[Driver]: set group key to hw: alg:2(WEP40-1 WEP104-5 TKIP-2 AES-4) keyid:1
Interface 0 IP address : 192.168.2.117
[INFO] Listen socket successfully
[INFO] Socket conntect successfully 
HTTP server started @ 192.168.2.117
[INFO] Accept connection successfully
A client connected to this server :
[PORT]: 36912
[IP]:192.168.2.30
[INFO] Accept connection successfully
A client connected to this server :
[PORT]: 36914
[IP]:192.168.2.30

[WIFI] String Len = 0, extend to 2048
[INFO] Accept connection successfully
```

---

#### 2. WebClient on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**WebClient**](examples/WebClient) on **Rtlduino RTL8720DN**


```cpp
Starting WebClientRepeating on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
interface 0 is initialized
interface 1 is initialized
Initializing WIFI ...
WIFI initialized
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet1
RTL8721D[Driver]: set ssid [HueNet1] 
RTL8721D[Driver]: rtw_set_wpa_ie[1160]: AuthKeyMgmt = 0x2 
RTL8721D[Driver]: rtw_restruct_sec_ie[4225]: no pmksa cached 
RTL8721D[Driver]: start auth to 68:7f:74:94:f4:a5
RTL8721D[Driver]: auth alg = 2
RTL8721D[Driver]: 
OnAuthClient:algthm = 0, seq = 2, status = 0, sae_msg_len = 11
RTL8721D[Driver]: auth success, start assoc
RTL8721D[Driver]: association success(res=1)
RTL8721D[Driver]: ClientSendEAPOL[1624]: no use cache pmksa 
RTL8721D[Driver]: ClientSendEAPOL[1624]: no use cache pmksa 
RTL8721D[Driver]: set pairwise key to hw: alg:4(WEP40-1 WEP104-5 TKIP-2 AES-4)
RTL8721D[Driver]: set group key to hw: alg:2(WEP40-1 WEP104-5 TKIP-2 AES-4) keyid:1
Interface 0 IP address : 192.168.2.117You're connected to the network, IP = 192.168.2.117
SSID: HueNet1, Signal strength (RSSI):-26 dBm
[INFO]server_drv.cpp:  start_client
[INFO] Create socket successfully
[INFO] Connect to Server successfully!
Connecting...
HTTP/1.1 200 OK
Date: Thu, 28 Apr 2022 02:46:07 GMT
Content-Type: text/plain
Content-Length: 2263
Connection: close
x-amz-id-2: 0v2VZitmKPb1GvH/Of2rACgGVIyluvsMCTX1kbkYKmtOMZMLlHXAT1n7wdAcMiFQ6LPQ1Qy2tSg=
x-amz-request-id: 72CSXT4AMDTCDJYE
Last-Modified: Wed, 23 Feb 2022 14:56:42 GMT
ETag: "667cf48afcc12c38c8c1637947a04224"
CF-Cache-Status: DYNAMIC
Report-To: {"endpoints":[{"url":"https:\/\/a.nel.cloudflare.com\/report\/v3?s=vdeduIIMRyhO44T972z7Z0qfco3T5svA5zYhyMJqQE5hTNGvTxTg%2B8S8e90uedVsSDo5oj73gg%2BxEoPfXW1%2FUCfu6XkFt6oLuf9zjLCo%2BSe58OLsZhr25mZ3MxPD%2ByY%3D"}],"group":"cf-nel","max_age":604800}
NEL: {"success_fraction":0,"report_to":"cf-nel","max_age":604800}
Server: cloudflare
CF-RAY: 702c77389848b671-YWG
alt-svc: h3=":443"; ma=86400, h3-29=":443"; ma=86400


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
```

---

#### 3. ScanNetworks on Rtlduino RTL8720DN

The following are debug terminal output and screen shot when running example [**ScanNetworks**](examples/ScanNetworks) on **Rtlduino RTL8720DN**

```cpp
Starting ScanNetworks on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
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


```cpp
Starting MQTTClient_Auth on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
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


```cpp
Start MQTT_ThingStream on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
Connected! IP address: 192.168.2.152
***************************************
STM32_Pub
***************************************
Attempting MQTT connection to broker.emqx.io
...connected
Published connection message successfully!
Subscribed to: STM32_Sub
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


```cpp
Starting WiFiUdpNTPClient on Rtlduino RTL8720DN with RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
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

This [WiFiWebServer_RTL8720 library](https://github.com/khoih-prog/WiFiWebServer_RTL8720) currently supports these following boards:

1. Realtek **RTL8720DN, RTL8722DM and RTL8722CSM**

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

 1. Add support to Realtek RTL8720DN, RTL8722DM and RTL8722CSM
 2. Add **High-level HTTP (GET, POST, PUT, PATCH, DELETE) and WebSocket Client**
 3. Fix bug related to usage of Arduino String
 4. Optimize library code and examples by using **reference-passing instead of value-passing**.
 5. Change from `arduino.cc` to `arduino.tips` in examples
 6. Add astyle using `allman` style. Restyle the library


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

Copyright (c) 2021- Khoi Hoang



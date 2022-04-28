/****************************************************************************************************************************
  defines.h
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license
 ***************************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if !defined(CONFIG_PLATFORM_8721D)
  #error Only for Ameba Realtek RTL8720DN, RTL8722DM and RTL8722CSM platform.
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

char ssid[] = "YOUR_SSID";        // your network SSID (name)
char pass[] = "12345678";        // your network password

#endif    //defines_h

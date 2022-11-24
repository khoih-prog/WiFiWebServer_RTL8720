/**************************************************************************************************************************************
  WiFiDebug.h - Dead simple web-server.
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.1.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTL8722CSM
  1.0.1   K Hoang      07/08/2021 Fix version typo
  1.1.0   K Hoang      26/12/2021 Fix bug related to usage of Arduino String. Optimize code
  1.1.1   K Hoang      26/12/2021 Fix authenticate issue caused by libb64
  1.1.2   K Hoang      27/04/2022 Change from `arduino.cc` to `arduino.tips` in examples
 ***************************************************************************************************************************************/

#pragma once

#include <stdio.h>

#ifdef DEBUG_WIFI_WEBSERVER_PORT
  #define WS_DEBUG_OUTPUT DEBUG_WIFI_WEBSERVER_PORT
#else
  #define WS_DEBUG_OUTPUT Serial
#endif

// Change _WIFI_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WIFI_LOGLEVEL_
  #define _WIFI_LOGLEVEL_       0
#endif

///////////////////////////////////////

const char WWS_MARK[]  = "[WIFI] ";
const char WWS_SPACE[] = " ";
const char WWS_LINE[]  = "========================================\n";

#define WWS_PRINT_MARK   WWS_PRINT(WWS_MARK)
#define WWS_PRINT_SP     WWS_PRINT(WWS_SPACE)
#define WWS_PRINT_LINE   WWS_PRINT(WWS_LINE)

#define WWS_PRINT        WS_DEBUG_OUTPUT.print
#define WWS_PRINTLN      WS_DEBUG_OUTPUT.println

///////////////////////////////////////

#define WS_LOGERROR(x)         if(_WIFI_LOGLEVEL_>0) { WWS_PRINT_MARK; WWS_PRINTLN(x); }
#define WS_LOGERROR0(x)        if(_WIFI_LOGLEVEL_>0) { WWS_PRINT(x); }
#define WS_LOGERROR1(x,y)      if(_WIFI_LOGLEVEL_>0) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINTLN(y); }
#define WS_LOGERROR2(x,y,z)    if(_WIFI_LOGLEVEL_>0) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINTLN(z); }
#define WS_LOGERROR3(x,y,z,w)  if(_WIFI_LOGLEVEL_>0) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINT(z); WWS_PRINT_SP; WWS_PRINTLN(w); }

///////////////////////////////////////

#define WS_LOGWARN(x)          if(_WIFI_LOGLEVEL_>1) { WWS_PRINT_MARK; WWS_PRINTLN(x); }
#define WS_LOGWARN0(x)         if(_WIFI_LOGLEVEL_>1) { WWS_PRINT(x); }
#define WS_LOGWARN1(x,y)       if(_WIFI_LOGLEVEL_>1) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINTLN(y); }
#define WS_LOGWARN2(x,y,z)     if(_WIFI_LOGLEVEL_>1) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINTLN(z); }
#define WS_LOGWARN3(x,y,z,w)   if(_WIFI_LOGLEVEL_>1) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINT(z); WWS_PRINT_SP; WWS_PRINTLN(w); }

///////////////////////////////////////

#define WS_LOGINFO(x)          if(_WIFI_LOGLEVEL_>2) { WWS_PRINT_MARK; WWS_PRINTLN(x); }
#define WS_LOGINFO0(x)         if(_WIFI_LOGLEVEL_>2) { WWS_PRINT(x); }
#define WS_LOGINFO1(x,y)       if(_WIFI_LOGLEVEL_>2) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINTLN(y); }
#define WS_LOGINFO2(x,y,z)     if(_WIFI_LOGLEVEL_>2) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINTLN(z); }
#define WS_LOGINFO3(x,y,z,w)   if(_WIFI_LOGLEVEL_>2) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINT(z); WWS_PRINT_SP; WWS_PRINTLN(w); }

///////////////////////////////////////

#define WS_LOGDEBUG(x)         if(_WIFI_LOGLEVEL_>3) { WWS_PRINT_MARK; WWS_PRINTLN(x); }
#define WS_LOGDEBUG0(x)        if(_WIFI_LOGLEVEL_>3) { WWS_PRINT(x); }
#define WS_LOGDEBUG1(x,y)      if(_WIFI_LOGLEVEL_>3) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINTLN(y); }
#define WS_LOGDEBUG2(x,y,z)    if(_WIFI_LOGLEVEL_>3) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINTLN(z); }
#define WS_LOGDEBUG3(x,y,z,w)  if(_WIFI_LOGLEVEL_>3) { WWS_PRINT_MARK; WWS_PRINT(x); WWS_PRINT_SP; WWS_PRINT(y); WWS_PRINT_SP; WWS_PRINT(z); WWS_PRINT_SP; WWS_PRINTLN(w); }


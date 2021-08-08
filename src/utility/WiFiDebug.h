/**************************************************************************************************************************************
  WiFiDebug.h - Dead simple web-server.
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTL8722CSM
  1.0.1   K Hoang      07/08/2021 Fix version typo
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

#define WS_LOGERROR(x)         if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGERROR0(x)        if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print(x); }
#define WS_LOGERROR1(x,y)      if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGERROR2(x,y,z)    if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(z); }
#define WS_LOGERROR3(x,y,z,w)  if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(z); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(w); }

///////////////////////////////////////

#define WS_LOGWARN(x)          if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGWARN0(x)         if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print(x); }
#define WS_LOGWARN1(x,y)       if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGWARN2(x,y,z)     if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(z); }
#define WS_LOGWARN3(x,y,z,w)   if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(z); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(w); }

///////////////////////////////////////

#define WS_LOGINFO(x)          if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGINFO0(x)         if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print(x); }
#define WS_LOGINFO1(x,y)       if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGINFO2(x,y,z)     if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(z); }
#define WS_LOGINFO3(x,y,z,w)   if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(z); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(w); }

///////////////////////////////////////

#define WS_LOGDEBUG(x)         if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGDEBUG0(x)        if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print(x); }
#define WS_LOGDEBUG1(x,y)      if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGDEBUG2(x,y,z)    if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(z); }
#define WS_LOGDEBUG3(x,y,z,w)  if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(z); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(w); }


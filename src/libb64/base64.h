/****************************************************************************************************************************
  base64.h - c source to a base64 encoding algorithm implementation

  For RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTM8722CSM
 *****************************************************************************************************************************/
 
#pragma once

// Reintroduce to prevent duplication compile error if other lib/core already has LIB64
// pragma once can't prevent that
#ifndef base64_h
#define base64_h

int base64_encode(const unsigned char* aInput, int aInputLen, unsigned char* aOutput, int aOutputLen);


#endif    // base64_h

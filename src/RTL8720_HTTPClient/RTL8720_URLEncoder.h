/****************************************************************************************************************************
  RTL8720_URLEncoder.h - Dead simple HTTP WebClient.
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
 *****************************************************************************************************************************/

// Library to simplify HTTP fetching on Arduino
// (c) Copyright Arduino. 2019
// Released under Apache License, version 2.0

#pragma once

#ifndef RTL8720_URLEncoder_h
#define RTL8720_URLEncoder_h

#include <Arduino.h>

#include "utility/WiFiDebug.h"


class WiFiURLEncoderClass
{
  public:
    WiFiURLEncoderClass();
    virtual ~WiFiURLEncoderClass();

    static String encode(const char* str);
    static String encode(const String& str);

  private:
    static String encode(const char* str, int length);
};

extern WiFiURLEncoderClass WiFiURLEncoder;

#endif    // RTL8720_URLEncoder_h

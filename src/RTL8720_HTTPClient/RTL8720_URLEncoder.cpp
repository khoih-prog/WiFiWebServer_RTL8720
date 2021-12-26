/****************************************************************************************************************************
  RTL8720_URLEncoder.cpp - Dead simple HTTP WebClient.
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.1.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTL8722CSM
  1.0.1   K Hoang      07/08/2021 Fix version typo
  1.1.0   K Hoang      26/12/2021 Fix bug related to usage of Arduino String. Optimize code
 *****************************************************************************************************************************/

// Library to simplify HTTP fetching on Arduino
// (c) Copyright Arduino. 2019
// Released under Apache License, version 2.0

#define _WIFI_LOGLEVEL_     0

#include "utility/WiFiDebug.h"
#include "RTL8720_HTTPClient/RTL8720_URLEncoder.h"

WiFiURLEncoderClass::WiFiURLEncoderClass()
{
}

WiFiURLEncoderClass::~WiFiURLEncoderClass()
{
}

String WiFiURLEncoderClass::encode(const char* str)
{
  return encode(str, strlen(str));
}

String WiFiURLEncoderClass::encode(const String& str)
{
  return encode(str.c_str(), str.length());
}

String WiFiURLEncoderClass::encode(const char* str, int length)
{
  String encoded;

  encoded.reserve(length);

  for (int i = 0; i < length; i++) 
  {
    char c = str[i];

    const char HEX_DIGIT_MAPPER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (isAlphaNumeric(c) || (c == '-') || (c == '.') || (c == '_') || (c == '~')) 
    {
      encoded += c;
    } 
    else 
    {
      char s[4];

      s[0] = '%';
      s[1] = HEX_DIGIT_MAPPER[(c >> 4) & 0xf];
      s[2] = HEX_DIGIT_MAPPER[(c & 0x0f)];
      s[3] = 0;

      encoded += s;
    }
  }

  return encoded;
}

WiFiURLEncoderClass WiFiURLEncoder;

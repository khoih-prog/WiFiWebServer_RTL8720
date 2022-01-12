/**************************************************************************************************************************************
  RingBuffer.cpp - Dead simple web-server.
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.1.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTL8722CSM
  1.0.1   K Hoang      07/08/2021 Fix version typo
  1.1.0   K Hoang      26/12/2021 Fix bug related to usage of Arduino String. Optimize code
  1.1.1   K Hoang      26/12/2021 Fix authenticate issue caused by libb64
 ***************************************************************************************************************************************/

#include "RingBuffer.h"

#include <Arduino.h>

WiFi_RingBuffer::WiFi_RingBuffer(unsigned int size)
{
  _size = size;
  // add one char to terminate the string
  ringBuf = new char[size + 1];
  ringBufEnd = &ringBuf[size];
  init();
}

WiFi_RingBuffer::~WiFi_RingBuffer() {}

void WiFi_RingBuffer::reset()
{
  ringBufP = ringBuf;
}

void WiFi_RingBuffer::init()
{
  ringBufP = ringBuf;
  memset(ringBuf, 0, _size + 1);
}

void WiFi_RingBuffer::push(char c)
{
  *ringBufP = c;
  ringBufP++;
  
  if (ringBufP >= ringBufEnd)
    ringBufP = ringBuf;
}

bool WiFi_RingBuffer::endsWith(const char* str)
{
  int findStrLen = strlen(str);

  // b is the start position into the ring buffer
  char* b = ringBufP - findStrLen;
  
  if (b < ringBuf)
    b = b + _size;

  char *p1 = (char*)&str[0];
  char *p2 = p1 + findStrLen;

  for (char *p = p1; p < p2; p++)
  {
    if (*p != *b)
      return false;

    b++;
    
    if (b == ringBufEnd)
      b = ringBuf;
  }

  return true;
}

void WiFi_RingBuffer::getStr(char * destination, unsigned int skipChars)
{
  //int len = ringBufP-ringBuf-skipChars;
  unsigned int len = ringBufP - ringBuf - skipChars;

  // copy buffer to destination string
  strncpy(destination, ringBuf, len);

  // terminate output string
  //destination[len]=0;
}

void WiFi_RingBuffer::getStrN(char * destination, unsigned int skipChars, unsigned int num)
{
  //int len = ringBufP-ringBuf-skipChars;
  unsigned int len = ringBufP - ringBuf - skipChars;

  if (len > num)
    len = num;

  // copy buffer to destination string
  strncpy(destination, ringBuf, len);

  // terminate output string
  //destination[len]=0;
}

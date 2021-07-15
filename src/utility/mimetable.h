/**************************************************************************************************************************************
  mimetable.h - Dead simple web-server.
  For RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTM8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTM8722CSM
 ***************************************************************************************************************************************/

#pragma once

namespace mime
{

enum type
{
  html,
  htm,
  css,
  txt,
  js,
  json,
  png,
  gif,
  jpg,
  ico,
  svg,
  ttf,
  otf,
  woff,
  woff2,
  eot,
  sfnt,
  xml,
  pdf,
  zip,
  gz,
  appcache,
  none,
  maxType
};

struct Entry
{
  const char endsWith[16]; 
  const char mimeType[32];
};

// Table of extension->MIME strings stored in PROGMEM, needs to be global due to GCC section typing rules
const Entry mimeTable[maxType] = 
{
    { ".html",      "text/html" },
    { ".htm",       "text/html" },
    { ".css",       "text/css" },
    { ".txt",       "text/plain" },
    { ".js",        "application/javascript" },
    { ".json",      "application/json" },
    { ".png",       "image/png" },
    { ".gif",       "image/gif" },
    { ".jpg",       "image/jpeg" },
    { ".ico",       "image/x-icon" },
    { ".svg",       "image/svg+xml" },
    { ".ttf",       "application/x-font-ttf" },
    { ".otf",       "application/x-font-opentype" },
    { ".woff",      "application/font-woff" },
    { ".woff2",     "application/font-woff2" },
    { ".eot",       "application/vnd.ms-fontobject" },
    { ".sfnt",      "application/font-sfnt" },
    { ".xml",       "text/xml" },
    { ".pdf",       "application/pdf" },
    { ".zip",       "application/zip" },
    { ".gz",        "application/x-gzip" },
    { ".appcache",  "text/cache-manifest" },
    { "",           "application/octet-stream" } 
};
//extern const Entry mimeTable[maxType];
}


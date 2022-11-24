/**************************************************************************************************************************************
  WiFiRequestHandlerImpl.h - Dead simple web-server.
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

#include "RequestHandler.h"
#include "mimetable.h"

class FunctionRequestHandler : public RequestHandler
{
  public:

    FunctionRequestHandler(WiFiWebServer::THandlerFunction fn, WiFiWebServer::THandlerFunction ufn, const String &uri,
                           HTTPMethod method)
      : _fn(fn)
      , _ufn(ufn)
      , _uri(uri)
      , _method(method)
    {
    }

    bool canHandle(const HTTPMethod& requestMethod, const String& requestUri) override
    {
      if (_method != HTTP_ANY && _method != requestMethod)
        return false;

      if (requestUri == _uri)
        return true;

      if (_uri.endsWith("/*"))
      {
        String _uristart = _uri;
        _uristart.replace("/*", "");

        if (requestUri.startsWith(_uristart))
          return true;
      }

      return false;
    }

    bool canUpload(const String& requestUri) override
    {
      if (!_ufn || !canHandle(HTTP_POST, requestUri))
        return false;

      return true;
    }

    bool handle(WiFiWebServer& server,  const HTTPMethod& requestMethod, const String& requestUri) override
    {
      WFW_UNUSED(server);

      if (!canHandle(requestMethod, requestUri))
        return false;

      _fn();
      return true;
    }

    void upload(WiFiWebServer& server, const String& requestUri, const HTTPUpload& upload) override
    {
      WFW_UNUSED(server);
      WFW_UNUSED(upload);

      if (canUpload(requestUri))
        _ufn();
    }

  protected:
    WiFiWebServer::THandlerFunction _fn;
    WiFiWebServer::THandlerFunction _ufn;
    String _uri;
    HTTPMethod _method;
};

class StaticRequestHandler : public RequestHandler
{
  public:

    bool canHandle(const HTTPMethod& requestMethod, const String& requestUri) override
    {
      if (requestMethod != HTTP_GET)
        return false;

      if ((_isFile && requestUri != _uri) || !requestUri.startsWith(_uri))
        return false;

      return true;
    }

#if USE_NEW_WEBSERVER_VERSION

    static String getContentType(const String& path)
    {
      using namespace mime;
      char buff[sizeof(mimeTable[0].mimeType)];

      // Check all entries but last one for match, return if found
      for (size_t i = 0; i < sizeof(mimeTable) / sizeof(mimeTable[0]) - 1; i++)
      {
        strcpy(buff, mimeTable[i].endsWith);

        if (path.endsWith(buff))
        {
          strcpy(buff, mimeTable[i].mimeType);
          return String(buff);
        }
      }

      // Fall-through and just return default type
      strcpy(buff, mimeTable[sizeof(mimeTable) / sizeof(mimeTable[0]) - 1].mimeType);
      return String(buff);
    }

#else

    static String getContentType(const String& path)
    {
      if (path.endsWith(".html"))
        return "text/html";
      else if (path.endsWith(".htm"))
        return "text/html";
      else if (path.endsWith(".css"))
        return "text/css";
      else if (path.endsWith(".txt"))
        return "text/plain";
      else if (path.endsWith(".js"))
        return "application/javascript";
      else if (path.endsWith(".png"))
        return "image/png";
      else if (path.endsWith(".gif"))
        return "image/gif";
      else if (path.endsWith(".jpg"))
        return "image/jpeg";
      else if (path.endsWith(".ico"))
        return "image/x-icon";
      else if (path.endsWith(".svg"))
        return "image/svg+xml";
      else if (path.endsWith(".ttf"))
        return "application/x-font-ttf";
      else if (path.endsWith(".otf"))
        return "application/x-font-opentype";
      else if (path.endsWith(".woff"))
        return "application/font-woff";
      else if (path.endsWith(".woff2"))
        return "application/font-woff2";
      else if (path.endsWith(".eot"))
        return "application/vnd.ms-fontobject";
      else if (path.endsWith(".sfnt"))
        return "application/font-sfnt";
      else if (path.endsWith(".xml"))
        return "text/xml";
      else if (path.endsWith(".pdf"))
        return "application/pdf";
      else if (path.endsWith(".zip"))
        return "application/zip";
      else if (path.endsWith(".gz"))
        return "application/x-gzip";
      else if (path.endsWith(".appcache"))
        return "text/cache-manifest";

      return "application/octet-stream";
    }

#endif

  protected:

    String _uri;
    String _path;
    String _cache_header;
    bool _isFile;
    size_t _baseUriLength;
};


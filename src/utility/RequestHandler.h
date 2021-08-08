/**************************************************************************************************************************************
  WiFiRequestHandler.h - Dead simple web-server.
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

#ifndef WFW_UNUSED
  #define WFW_UNUSED(x) (void)(x)
#endif


class RequestHandler
{
  public:

    virtual ~RequestHandler() { }

    virtual bool canHandle(HTTPMethod method, String uri)
    {
      WFW_UNUSED(method);
      WFW_UNUSED(uri);
      
      return false;
    }

    virtual bool canUpload(String uri)
    {
      WFW_UNUSED(uri);
      
      return false;
    }

    virtual bool handle(WiFiWebServer& server, HTTPMethod requestMethod, String requestUri)
    {
      WFW_UNUSED(server);
      WFW_UNUSED(requestMethod);
      WFW_UNUSED(requestUri);
      
      return false;
    }

    virtual void upload(WiFiWebServer& server, String requestUri, HTTPUpload& upload) 
    {
      WFW_UNUSED(server);
      WFW_UNUSED(requestUri);
      WFW_UNUSED(upload);
    }

    RequestHandler* next()
    {
      return _next;
    }

    void next(RequestHandler* r)
    {
      _next = r;
    }

  private:

    RequestHandler* _next = nullptr;
};

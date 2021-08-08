/**************************************************************************************************************************************
  WiFiWebServer_RTL8720-impl.h - Dead simple web-server.
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

#ifndef WiFiWebServer_RTL8720_Impl_h
#define WiFiWebServer_RTL8720_Impl_h

#include <Arduino.h>
#include <libb64/cencode.h>

#include "utility/RequestHandlersImpl.h"
#include "utility/WiFiDebug.h"
#include "utility/mimetable.h"

const char * AUTHORIZATION_HEADER = "Authorization";

WiFiWebServer::WiFiWebServer(int port)
  : _server(port)
  , _currentMethod(HTTP_ANY)
  , _currentVersion(0)
  , _currentHandler(nullptr)
  , _firstHandler(nullptr)
  , _lastHandler(nullptr)
  , _currentArgCount(0)
  , _currentArgs(nullptr)

#if USE_NEW_WEBSERVER_VERSION
  ,_currentUpload(nullptr)
  ,_postArgs(nullptr)
#endif
  , _headerKeysCount(0)
  , _currentHeaders(nullptr)
  , _contentLength(0)
  , _chunked(false)
{
}

WiFiWebServer::~WiFiWebServer() 
{
  if (_currentHeaders)
    delete[]_currentHeaders;
    
  _headerKeysCount = 0;
  RequestHandler* handler = _firstHandler;
  
  while (handler) 
  {
    RequestHandler* next = handler->next();
    delete handler;
    handler = next;
  }
  
  close();
}

void WiFiWebServer::begin() 
{
  _currentStatus = HC_NONE;
  _server.begin();
  
  if (!_headerKeysCount)
    collectHeaders(0, 0);
}

bool WiFiWebServer::authenticate(const char * username, const char * password) 
{
  if (hasHeader(AUTHORIZATION_HEADER)) 
  {
    String authReq = header(AUTHORIZATION_HEADER);
    
    if (authReq.startsWith("Basic")) 
    {
      authReq = authReq.substring(6);
      authReq.trim();
      char toencodeLen = strlen(username) + strlen(password) + 1;
      char *toencode = new char[toencodeLen + 1];
      
      if (toencode == NULL) 
      {
        authReq = String();
        return false;
      }
      
      char *encoded = new char[base64_encode_expected_len(toencodeLen) + 1];
      
      if (encoded == NULL) 
      {
        authReq = String();
        delete[] toencode;
        return false;
      }
      
      sprintf(toencode, "%s:%s", username, password);
      
      if (base64_encode_chars(toencode, toencodeLen, encoded) > 0 && authReq.equals(encoded)) 
      {
        authReq = String();
        delete[] toencode;
        delete[] encoded;
        return true;
      }
      
      delete[] toencode;
      delete[] encoded;
    }
    
    authReq = String();
  }
  
  return false;
}

void WiFiWebServer::requestAuthentication() 
{
  sendHeader("WWW-Authenticate", "Basic realm=\"Login Required\"");
  send(401);
}

void WiFiWebServer::on(const String &uri, WiFiWebServer::THandlerFunction handler) 
{
  on(uri, HTTP_ANY, handler);
}

void WiFiWebServer::on(const String &uri, HTTPMethod method, WiFiWebServer::THandlerFunction fn) 
{
  on(uri, method, fn, _fileUploadHandler);
}

void WiFiWebServer::on(const String &uri, HTTPMethod method, WiFiWebServer::THandlerFunction fn, WiFiWebServer::THandlerFunction ufn) 
{
  _addRequestHandler(new FunctionRequestHandler(fn, ufn, uri, method));
}

void WiFiWebServer::addHandler(RequestHandler* handler) 
{
  _addRequestHandler(handler);
}

void WiFiWebServer::_addRequestHandler(RequestHandler* handler) 
{
  if (!_lastHandler) 
  {
    _firstHandler = handler;
    _lastHandler = handler;
  }
  else 
  {
    _lastHandler->next(handler);
    _lastHandler = handler;
  }
}

//KH
#if USE_NEW_WEBSERVER_VERSION

void WiFiWebServer::handleClient() 
{
  if (_currentStatus == HC_NONE) 
  {
    WiFiClient client = _server.available();
    
    if (!client) 
    {
      //WS_LOGDEBUG(F("handleClient: No Client"));
      return;
    }

    WS_LOGDEBUG(F("handleClient: New Client"));

    _currentClient = client;
    _currentStatus = HC_WAIT_READ;
    _statusChange = millis();
  }

  bool keepCurrentClient = false;
  bool callYield = false;

  if (_currentClient.connected() || _currentClient.available()) 
  {
    switch (_currentStatus) 
    {
    case HC_NONE:
      // No-op to avoid C++ compiler warning
      break;
    case HC_WAIT_READ:
      // Wait for data from client to become available
      if (_currentClient.available()) 
      {
        if (_parseRequest(_currentClient)) 
        {
          _currentClient.setTimeout(HTTP_MAX_SEND_WAIT);
          _contentLength = CONTENT_LENGTH_NOT_SET;
          _handleRequest();

          if (_currentClient.connected()) 
          {
            _currentStatus = HC_WAIT_CLOSE;
            _statusChange = millis();
            keepCurrentClient = true;
          }
        }
      } 
      else 
      { // !_currentClient.available()
        if (millis() - _statusChange <= HTTP_MAX_DATA_WAIT) 
        {
          keepCurrentClient = true;
        }
        
        callYield = true;
      }
      break;
    case HC_WAIT_CLOSE:
      // Wait for client to close the connection
      if (millis() - _statusChange <= HTTP_MAX_CLOSE_WAIT) 
      {
        keepCurrentClient = true;
        callYield = true;
      }
    }
  }

  if (!keepCurrentClient) 
  {
    WS_LOGDEBUG(F("handleClient: Don't keepCurrentClient"));
    _currentClient = WiFiClient();
    _currentStatus = HC_NONE;
    // KH
    //_currentUpload.reset();
  }

  if (callYield) 
  {
    // KH, tempo for RTL8720
    //yield();
    delay(1);
  }  
  
  // KH, fix bug relating to New NINA FW 1.4.0. Have to close the connection
  _currentClient.stop();
  WS_LOGDEBUG(F("handleClient: Client disconnected"));
}
 
#else

void WiFiWebServer::handleClient() 
{
  if (_currentStatus == HC_NONE) 
  {
    WiFiClient client = _server.available();
    
    if (!client) 
    {
      return;
    }

    WS_LOGDEBUG(F("handleClient: New Client"));

    _currentClient = client;
    _currentStatus = HC_WAIT_READ;
    _statusChange = millis();
  }
  
  if (!_currentClient.connected()) 
  {
    _currentClient = WiFiClient();
    _currentStatus = HC_NONE;
    return;
  }

  // Wait for data from client to become available
  if (_currentStatus == HC_WAIT_READ) 
  {
    WS_LOGDEBUG(F("handleClient: _currentStatus = HC_WAIT_READ"));
    
    if (!_currentClient.available()) 
    {
      WS_LOGDEBUG(F("handleClient: Client not available"));
      
      if (millis() - _statusChange > HTTP_MAX_DATA_WAIT) 
      {
        WS_LOGDEBUG(F("handleClient: HTTP_MAX_DATA_WAIT Timeout"));

        _currentClient = WiFiClient();
        _currentStatus = HC_NONE;
      }
      
      yield();
      return;
    }

    WS_LOGDEBUG(F("handleClient: Parsing Request"));

    if (!_parseRequest(_currentClient)) 
    {
      WS_LOGDEBUG(F("handleClient: Can't parse request"));

      _currentClient = WiFiClient();
      _currentStatus = HC_NONE;
      return;
    }

    _currentClient.setTimeout(HTTP_MAX_SEND_WAIT);
    _contentLength = CONTENT_LENGTH_NOT_SET;

    //WS_LOGDEBUG(F("handleClient _handleRequest"));
    _handleRequest();

    if (!_currentClient.connected()) 
    {
      WS_LOGINFO(F("handleClient: Connection closed"));

      _currentClient = WiFiClient();
      _currentStatus = HC_NONE;
      return;
    } 
    else 
    {
      _currentStatus = HC_WAIT_CLOSE;
      _statusChange = millis();
      return;
    }
  }

  if (_currentStatus == HC_WAIT_CLOSE) 
  {
    if (millis() - _statusChange > HTTP_MAX_CLOSE_WAIT) 
    {
      _currentClient = WiFiClient();
      _currentStatus = HC_NONE;

      WS_LOGDEBUG(F("handleClient: HTTP_MAX_CLOSE_WAIT Timeout"));

      yield();
    } 
    else 
    {
      yield();
      return;
    }
  }
  
  // KH, fix bug relating to New NINA FW 1.4.0. Have to close the connection
  _currentClient.stop();
  WS_LOGDEBUG(F("handleClient: Client disconnected"));
}

#endif

void WiFiWebServer::close() 
{
  // TODO: Write close method for WIFI library and uncomment this
  //_server.close();
}

void WiFiWebServer::stop() 
{
  close();
}

void WiFiWebServer::sendHeader(const String& name, const String& value, bool first) 
{
  String headerLine = name;
  headerLine += ": ";
  headerLine += value;
  headerLine += "\r\n";

  if (first) 
  {
    _responseHeaders = headerLine + _responseHeaders;
  }
  else 
  {
    _responseHeaders += headerLine;
  }
}

void WiFiWebServer::setContentLength(size_t contentLength) 
{
  _contentLength = contentLength;
}

void WiFiWebServer::_prepareHeader(String& response, int code, const char* content_type, size_t contentLength) 
{
  response = "HTTP/1." + String(_currentVersion) + " ";
  response += String(code);
  response += " ";
  response += _responseCodeToString(code);
  response += "\r\n";

  using namespace mime;
  
  if (!content_type)
      content_type = mimeTable[html].mimeType;

  sendHeader("Content-Type", content_type, true);
  
  if (_contentLength == CONTENT_LENGTH_NOT_SET) 
  {
    sendHeader("Content-Length", String(contentLength));
  } 
  else if (_contentLength != CONTENT_LENGTH_UNKNOWN) 
  {
    sendHeader("Content-Length", String(_contentLength));
  } 
  else if (_contentLength == CONTENT_LENGTH_UNKNOWN && _currentVersion) 
  { 
    //HTTP/1.1 or above client
    //let's do chunked
    _chunked = true;
    sendHeader("Accept-Ranges", "none");
    sendHeader("Transfer-Encoding", "chunked");
  }

  WS_LOGDEBUG(F("_prepareHeader sendHeader Conn close"));

  sendHeader("Connection", "close");

  response += _responseHeaders;
  response += "\r\n";
  
  // RM & KH fix
  //_responseHeaders = String();
  _responseHeaders = *(new String());
}

void WiFiWebServer::send(int code, const char* content_type, const String& content) 
{
  String header;
  
  // Can we asume the following?
  //if(code == 200 && content.length() == 0 && _contentLength == CONTENT_LENGTH_NOT_SET)
  //  _contentLength = CONTENT_LENGTH_UNKNOWN;

  WS_LOGDEBUG1(F("send1: len = "), content.length());
  WS_LOGDEBUG1(F("content = "), content);

  _prepareHeader(header, code, content_type, content.length());

  _currentClient.write((const uint8_t *)header.c_str(), header.length());

  if (content.length())
  {
    WS_LOGDEBUG1(F("send1: write header = "), header);
    //sendContent(content);
    sendContent(content, content.length());
  }
}

void WiFiWebServer::send(int code, char* content_type, const String& content, size_t contentLength)
{
  String header;

  WS_LOGDEBUG1(F("send2: len = "), contentLength);
  WS_LOGDEBUG1(F("content = "), content);

  char type[64];
  
  // KH, tempo for RTL8720
  //memccpy((void*)type, content_type, 0, sizeof(type));
  strncpy((char*)type, content_type, sizeof(type)),
  //////
  
  _prepareHeader(header, code, (const char* )type, contentLength);

  WS_LOGDEBUG1(F("send2: hdrlen = "), header.length());
  WS_LOGDEBUG1(F("header = "), header);

  _currentClient.write((const uint8_t *) header.c_str(), header.length());
  
  if (contentLength)
  {
    sendContent(content, contentLength);
  }
}

void WiFiWebServer::send(int code, char* content_type, const String& content) 
{
  send(code, (const char*)content_type, content);
}

void WiFiWebServer::send(int code, const String& content_type, const String& content) 
{
  send(code, (const char*)content_type.c_str(), content);
}

void WiFiWebServer::sendContent(const String& content) 
{
  const char * footer = "\r\n";
  size_t len = content.length();
  
  if (_chunked) 
  {
    char * chunkSize = (char *) malloc(11);
    
    if (chunkSize) 
    {
      sprintf(chunkSize, "%x%s", len, footer);
      _currentClient.write(chunkSize, strlen(chunkSize));
      free(chunkSize);
    }
  }
  
  _currentClient.write(content.c_str(), len);
  
  if (_chunked) 
  {
    _currentClient.write(footer, 2);
  }
}

void WiFiWebServer::sendContent(const String& content, size_t size)
{
  const char * footer = "\r\n";
  
  if (_chunked) 
  {
    char * chunkSize = (char *) malloc(11);
    
    if (chunkSize) 
    {
      WS_LOGDEBUG(F("sendContent: _chunked"));

      sprintf(chunkSize, "%x%s", size, footer);
      _currentClient.write(chunkSize, strlen(chunkSize));
      free(chunkSize);
    }
  }

  WS_LOGDEBUG1(F("sendContent: Client.write content: "), content);
  _currentClient.write(content.c_str(), size);
  
  if (_chunked) {
    _currentClient.write(footer, 2);
  }
}

String WiFiWebServer::arg(String name) 
{
  for (int i = 0; i < _currentArgCount; ++i) 
  {
    if ( _currentArgs[i].key == name )
      return _currentArgs[i].value;
  }
  
  return String();
}

String WiFiWebServer::arg(int i) 
{
  if (i < _currentArgCount)
    return _currentArgs[i].value;
    
  return String();
}

String WiFiWebServer::argName(int i) 
{
  if (i < _currentArgCount)
    return _currentArgs[i].key;
    
  return String();
}

int WiFiWebServer::args() 
{
  return _currentArgCount;
}

bool WiFiWebServer::hasArg(String  name) 
{
  for (int i = 0; i < _currentArgCount; ++i) 
  {
    if (_currentArgs[i].key == name)
      return true;
  }
  
  return false;
}


String WiFiWebServer::header(String name) 
{
  for (int i = 0; i < _headerKeysCount; ++i) 
  {
    if (_currentHeaders[i].key == name)
      return _currentHeaders[i].value;
  }
  
  return String();
}

void WiFiWebServer::collectHeaders(const char* headerKeys[], const size_t headerKeysCount) 
{
  _headerKeysCount = headerKeysCount + 1;
  
  if (_currentHeaders)
    delete[]_currentHeaders;
    
  _currentHeaders = new RequestArgument[_headerKeysCount];
  _currentHeaders[0].key = AUTHORIZATION_HEADER;
  
  for (int i = 1; i < _headerKeysCount; i++) 
  {
    _currentHeaders[i].key = headerKeys[i - 1];
  }
}

String WiFiWebServer::header(int i) 
{
  if (i < _headerKeysCount)
    return _currentHeaders[i].value;
    
  return String();
}

String WiFiWebServer::headerName(int i) 
{
  if (i < _headerKeysCount)
    return _currentHeaders[i].key;
    
  return String();
}

int WiFiWebServer::headers() 
{
  return _headerKeysCount;
}

bool WiFiWebServer::hasHeader(String name) 
{
  for (int i = 0; i < _headerKeysCount; ++i) 
  {
    if ((_currentHeaders[i].key == name) &&  (_currentHeaders[i].value.length() > 0))
      return true;
  }
  
  return false;
}

String WiFiWebServer::hostHeader() 
{
  return _hostHeader;
}

void WiFiWebServer::onFileUpload(THandlerFunction fn) 
{
  _fileUploadHandler = fn;
}

void WiFiWebServer::onNotFound(THandlerFunction fn) 
{
  _notFoundHandler = fn;
}

void WiFiWebServer::_handleRequest()
{
  bool handled = false;
  
  if (!_currentHandler)
  {
    WS_LOGDEBUG(F("_handleRequest: request handler not found"));
  }
  else
  {
    WS_LOGDEBUG(F("_handleRequest handle"));
    
    handled = _currentHandler->handle(*this, _currentMethod, _currentUri);
    
    if (!handled)
    {
      WS_LOGDEBUG(F("_handleRequest: _handleRequest failed"));
    }
    else
    {
      WS_LOGDEBUG(F("_handleRequest OK"));
    }
  }

  if (!handled && _notFoundHandler) 
  {
    _notFoundHandler();
    handled = true;
  }
  
  if (!handled) 
  {
    using namespace mime;
    
    send(404, mimeTable[html].mimeType, String("Not found: ") + _currentUri);
    handled = true;
  }
  
  if (handled) 
  {
    _finalizeResponse();
  }
  
  // RM & KH fix
  //_currentUri = String();
  _currentUri = *(new String());
}

void WiFiWebServer::_finalizeResponse() 
{
  if (_chunked) 
  {
    sendContent(String());
  }
}

String WiFiWebServer::_responseCodeToString(int code) 
{
  switch (code) 
  {
    case 100: return F("Continue");
    case 101: return F("Switching Protocols");
    case 200: return F("OK");
    case 201: return F("Created");
    case 202: return F("Accepted");
    case 203: return F("Non-Authoritative Information");
    case 204: return F("No Content");
    case 205: return F("Reset Content");
    case 206: return F("Partial Content");
    case 300: return F("Multiple Choices");
    case 301: return F("Moved Permanently");
    case 302: return F("Found");
    case 303: return F("See Other");
    case 304: return F("Not Modified");
    case 305: return F("Use Proxy");
    case 307: return F("Temporary Redirect");
    case 400: return F("Bad Request");
    case 401: return F("Unauthorized");
    case 402: return F("Payment Required");
    case 403: return F("Forbidden");
    case 404: return F("Not Found");
    case 405: return F("Method Not Allowed");
    case 406: return F("Not Acceptable");
    case 407: return F("Proxy Authentication Required");
    case 408: return F("Request Time-out");
    case 409: return F("Conflict");
    case 410: return F("Gone");
    case 411: return F("Length Required");
    case 412: return F("Precondition Failed");
    case 413: return F("Request Entity Too Large");
    case 414: return F("Request-URI Too Large");
    case 415: return F("Unsupported Media Type");
    case 416: return F("Requested range not satisfiable");
    case 417: return F("Expectation Failed");
    case 500: return F("Internal Server Error");
    case 501: return F("Not Implemented");
    case 502: return F("Bad Gateway");
    case 503: return F("Service Unavailable");
    case 504: return F("Gateway Time-out");
    case 505: return F("HTTP Version not supported");
    default:  return "";
  }
}

#endif    // WiFiWebServer_RTL8720_Impl_h

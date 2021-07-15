/**************************************************************************************************************************************
  WiFiWebServer_RTL8720.h - Dead simple web-server.
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

#ifndef WiFiWebServer_RTL8720_h
#define WiFiWebServer_RTL8720_h

#define WIFI_WEBSERVER_RTL8720_VERSION          "WiFiWebServer_RTL8720 v1.0.0"

#define WIFI_WEBSERVER_RTL8720_VERSION_MAJOR    1
#define WIFI_WEBSERVER_RTL8720_VERSION_MAJOR    0
#define WIFI_WEBSERVER_RTL8720_VERSION_MAJOR    0

#define WEBSOCKETS2_GENERIC_VERSION_INT         1000000

#define USE_NEW_WEBSERVER_VERSION     true

#define LATEST_RTL8720_FIRMWARE       "1.0.0"

// To support lambda function in class
#include <functional-vlpp.h>

#include <WiFi.h>
#warning Use WiFi.h from WiFiWebServer_RTL8720


#include "utility/mimetable.h"
#include "utility/RingBuffer.h"

#include <string.h>

// Permit redefinition of SENDCONTENT_P_BUFFER_SZ in sketch, default is 4K, minimum is 256 bytes
#ifndef SENDCONTENT_P_BUFFER_SZ
  #define SENDCONTENT_P_BUFFER_SZ     4096
  #warning SENDCONTENT_P_BUFFER_SZ using default 4 Kbytes
#else
  #if (SENDCONTENT_P_BUFFER_SZ < 256)
    #undef SENDCONTENT_P_BUFFER_SZ
    #define SENDCONTENT_P_BUFFER_SZ   256
    #warning SENDCONTENT_P_BUFFER_SZ reset to min 256 bytes
  #endif
#endif

#ifndef PGM_VOID_P
  #define PGM_VOID_P const void *
#endif

//////

enum HTTPMethod 
{ 
  HTTP_ANY, 
  HTTP_GET,
  HTTP_HEAD,
  HTTP_POST, 
  HTTP_PUT, 
  HTTP_PATCH, 
  HTTP_DELETE, 
  HTTP_OPTIONS 
};

enum HTTPUploadStatus 
{ 
  UPLOAD_FILE_START, 
  UPLOAD_FILE_WRITE, 
  UPLOAD_FILE_END,
  UPLOAD_FILE_ABORTED
};

enum HTTPClientStatus 
{ 
  HC_NONE, 
  HC_WAIT_READ, 
  HC_WAIT_CLOSE 
};

enum HTTPAuthMethod 
{ 
  BASIC_AUTH, 
  DIGEST_AUTH 
};

#define HTTP_DOWNLOAD_UNIT_SIZE 1460

// Permit user to increase HTTP_UPLOAD_BUFLEN larger than default 2K
//#define HTTP_UPLOAD_BUFLEN 2048
#if !defined(HTTP_UPLOAD_BUFLEN)
  #define HTTP_UPLOAD_BUFLEN 2048
#endif

#define HTTP_MAX_DATA_WAIT    5000 //ms to wait for the client to send the request
#define HTTP_MAX_POST_WAIT    5000 //ms to wait for POST data to arrive
#define HTTP_MAX_SEND_WAIT    5000 //ms to wait for data chunk to be ACKed
#define HTTP_MAX_CLOSE_WAIT   2000 //ms to wait for the client to close the connection

#define CONTENT_LENGTH_UNKNOWN ((size_t) -1)
#define CONTENT_LENGTH_NOT_SET ((size_t) -2)

class WiFiWebServer;

typedef struct 
{
  HTTPUploadStatus status;
  String  filename;
  String  name;
  String  type;
  size_t  totalSize;      // file size
  size_t  currentSize;    // size of data currently in buf
  size_t  contentLength;  // size of entire post request, file size + headers and other request data.
  uint8_t buf[HTTP_UPLOAD_BUFLEN];
} HTTPUpload;

#include "utility/RequestHandler.h"

class WiFiWebServer
{
  public:
    WiFiWebServer(int port = 80);
    ~WiFiWebServer();

    void begin();
    void handleClient();

    void close();
    void stop();

    bool authenticate(const char * username, const char * password);
    void requestAuthentication();

    typedef vl::Func<void(void)> THandlerFunction;
    //typedef std::function<void(void)> THandlerFunction;
    //typedef void (*THandlerFunction)(void);

    void on(const String &uri, THandlerFunction handler);
    void on(const String &uri, HTTPMethod method, THandlerFunction fn);
    void on(const String &uri, HTTPMethod method, THandlerFunction fn, THandlerFunction ufn);
    void addHandler(RequestHandler* handler);
    void onNotFound(THandlerFunction fn);   //called when handler is not assigned
    void onFileUpload(THandlerFunction fn); //handle file uploads

    String uri() 
    {
      return _currentUri;
    }
    
    HTTPMethod method() 
    {
      return _currentMethod;
    }
    
    WiFiClient client() 
    {
      return _currentClient;
    }
    
    //KH
    #if USE_NEW_WEBSERVER_VERSION
    HTTPUpload& upload() 
    {
      return *_currentUpload;
    }
    #else
    HTTPUpload& upload() 
    {
      return _currentUpload;
    }
    #endif
    
    String arg(String name);            // get request argument value by name
    String arg(int i);                  // get request argument value by number
    String argName(int i);              // get request argument name by number
    int args();                         // get arguments count
    bool hasArg(String name);           // check if argument exists
    void collectHeaders(const char* headerKeys[], const size_t headerKeysCount); // set the request headers to collect
    String header(String name);         // get request header value by name
    String header(int i);               // get request header value by number
    String headerName(int i);           // get request header name by number
    int headers();                      // get header count
    bool hasHeader(String name);        // check if header exists

    String hostHeader();                // get request host header if available or empty String if not

    // send response to the client
    // code - HTTP response code, can be 200 or 404
    // content_type - HTTP content type, like "text/plain" or "image/png"
    // content - actual content body
    void send(int code, const char* content_type = NULL, const String& content = String(""));
    void send(int code, char* content_type, const String& content);
    void send(int code, const String& content_type, const String& content);
    //KH
    void send(int code, char*  content_type, const String& content, size_t contentLength);
    
    void setContentLength(size_t contentLength);
    void sendHeader(const String& name, const String& value, bool first = false);
    void sendContent(const String& content);
    void sendContent(const String& content, size_t size);

    static String urlDecode(const String& text);

    template<typename T> size_t streamFile(T &file, const String& contentType) 
    {
      using namespace mime;
      setContentLength(file.size());
      
      if (String(file.name()).endsWith(mimeTable[gz].endsWith) && contentType != mimeTable[gz].mimeType && contentType != mimeTable[none].mimeType) 
      {
        sendHeader("Content-Encoding", "gzip");
      }
      
      send(200, contentType, "");
      return _currentClient.write(file);
    }

  protected:
    void _addRequestHandler(RequestHandler* handler);
    void _handleRequest();
    void _finalizeResponse();
    bool _parseRequest(WiFiClient& client);
    
    //KH
    #if USE_NEW_WEBSERVER_VERSION
    void _parseArguments(const String& data);
    int  _parseArgumentsPrivate(const String& data, vl::Func<void(String&,String&,const String&,int,int,int,int)> handler);
    bool _parseForm(WiFiClient& client, const String& boundary, uint32_t len);
    #else
    void _parseArguments(String data);
    bool _parseForm(WiFiClient& client, String boundary, uint32_t len);
    #endif
    
    static String _responseCodeToString(int code);    
    bool _parseFormUploadAborted();
    void _uploadWriteByte(uint8_t b);
    uint8_t _uploadReadByte(WiFiClient& client);
    void _prepareHeader(String& response, int code, const char* content_type, size_t contentLength);
    bool _collectHeader(const char* headerName, const char* headerValue);
    
    struct RequestArgument 
    {
      String key;
      String value;
    };

    WiFiServer  _server;

    WiFiClient        _currentClient;
    HTTPMethod        _currentMethod;
    String            _currentUri;
    uint8_t           _currentVersion;
    HTTPClientStatus  _currentStatus;
    unsigned long     _statusChange;

    RequestHandler*   _currentHandler   = nullptr;
    RequestHandler*   _firstHandler     = nullptr;
    RequestHandler*   _lastHandler      = nullptr;
    THandlerFunction  _notFoundHandler;
    THandlerFunction  _fileUploadHandler;

    int               _currentArgCount;
    RequestArgument*  _currentArgs      = nullptr;

    //KH = nullptr
    #if USE_NEW_WEBSERVER_VERSION
    HTTPUpload*       _currentUpload    = nullptr;
    int               _postArgsLen;
    RequestArgument*  _postArgs         = nullptr;
    
    #else
    HTTPUpload        _currentUpload;
    #endif
    
    int               _headerKeysCount;
    RequestArgument*  _currentHeaders   = nullptr;
    size_t            _contentLength;
    String            _responseHeaders;

    String            _hostHeader;
    bool              _chunked;
};

#include "WiFiWebServer_RTL8720-impl.h"
#include "Parsing_RTL8720-impl.h"

#endif    // WiFiWebServer_RTL8720_h


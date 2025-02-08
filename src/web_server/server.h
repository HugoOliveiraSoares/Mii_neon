#pragma once

#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

class WebServer {
public:
  WebServer();
  void begin();

private:
  AsyncWebServer server;
};

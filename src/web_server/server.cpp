#include "server.h"

WebServer::WebServer() : server(80) {}

void WebServer::begin() {
  if (!LittleFS.begin()) {
    Serial.println("❌ Falha ao montar o sistema de arquivos (LittleFS)!");
    return;
  }

  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

  // Endpoint to set the color of the LED strip
  server.on(
      "/setColor", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL,
      [this](AsyncWebServerRequest *request, uint8_t *data, size_t len,
             std::size_t index, std::size_t total) {
        // Parse the JSON
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, data, len);

        if (error) {
          request->send(400, "text/plain", "Invalid JSON");
          return;
        }

        if (!doc.containsKey("RGB")) {
          request->send(400, "application/json",
                        "{\"error\":\"Missing RGB object\"}");
          return;
        }

        // Extract RGB values
        int r = doc["RGB"]["r"];
        int g = doc["RGB"]["g"];
        int b = doc["RGB"]["b"];
        // int w = doc["RGB"]["w"]; // If using RGBW strips, otherwise
        // ignore

        // Set the color using the Effects class
        ledService.setColor(CRGB(r, g, b));

        // Send a response
        request->send(200, "text/plain", "Color set successfully");
      });

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Arquivo não encontrado");
  });

  server.begin();
}

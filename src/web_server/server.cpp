#include "server.h"

WebServer::WebServer() : server(80) {}

void WebServer::begin() {
  if (!LittleFS.begin()) {
    Serial.println("❌ Falha ao montar o sistema de arquivos (LittleFS)!");
    return;
  }

  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

  server.on(
      "/setColor", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL,
      [this](AsyncWebServerRequest *request, uint8_t *data, size_t len,
             std::size_t index, std::size_t total) {
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, data, len);

        if (error) {
          request->send(400, "text/plain", "Invalid JSON");
          return;
        }

        if (!doc.containsKey("rgb")) {
          request->send(400, "application/json",
                        "{\"error\":\"Missing rgb object\"}");
          return;
        }

        int r = doc["rgb"]["r"];
        int g = doc["rgb"]["g"];
        int b = doc["rgb"]["b"];

        ledService.setColor(CRGB(r, g, b));

        request->send(200, "text/plain", "Color set successfully");
      });

  server.on(
      "/setBright", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL,
      [this](AsyncWebServerRequest *request, uint8_t *data, size_t len,
             std::size_t index, std::size_t total) {
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, data, len);

        if (error) {
          request->send(400, "text/plain", "Invalid JSON");
          return;
        }

        if (!doc.containsKey("bright")) {
          request->send(400, "application/json",
                        "{\"error\":\"Missing bright object\"}");
          return;
        }

        int bright = doc["bright"];
        ledService.setBright(bright);

        request->send(200, "text/plain", "Color set successfully");
      });

  server.on("/effects", HTTP_GET, [this](AsyncWebServerRequest *request) {
    StaticJsonDocument<200> jsonDoc;
    JsonArray effectsArray = jsonDoc.createNestedArray("effects");
    std::vector<String> effectsList = ledService.getModes();

    for (const String &effectName : effectsList) {
      effectsArray.add(effectName);
    }

    String response;
    serializeJson(jsonDoc, response);
    request->send(200, "application/json", response);
  });

  server.begin();

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Resource not found");
  });

  server.begin();
}

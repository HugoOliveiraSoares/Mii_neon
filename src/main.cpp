#include "FastLED.h"
#include "effects/Effects.h"
#include "web_server/server.h"
#include <cstdlib>

WebServer webServer;

Effects effects;

Segment seg1 = {0, NUM_LEDS_STRIP1};
Segment seg2 = {NUM_LEDS_STRIP1, NUM_LEDS_STRIP2};

void setup() {

  Serial.begin(115200);

  WiFi.begin("Multilaser_2.4G_39E1A8", "smart600w");
  Serial.println("\n🔄 Conectando ao WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\n✅ Conectado ao WiFi!");
  Serial.print("📡 IP: ");
  Serial.println(WiFi.localIP());

  webServer.begin();

  effects.init();
  delay(100);
}

void loop() {

  // effects.fill(CRGB::Blue);
  // effects.fillSegment(CRGB::Blue, seg1);
  // effects.fillSegment(CRGB::Red, seg2);
  // effects.blink(CRGB::Red);
  // delay(1000);
  // effects.rainbowCycle();
  // effects.pacifica_loop();
  // effects.cyclon();
  // effects.colorWipe(CRGB::Green);
  // effects.snowSparkle(CRGB::White);
}

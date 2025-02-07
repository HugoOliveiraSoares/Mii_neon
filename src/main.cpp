#include "Effects.h"
#include "FastLED.h"

Effects effects;

unsigned long previousMillis = 0;
const long interval = 6000; // 5 segundos entre os efeitos
int currentEffect = 0;

void setup() {
  effects.init();
  delay(100);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    effects.blink(CRGB::Green);
  }
  delay(500);
  effects.cyclon();
  delay(500);
}

#include "FastLED.h"
#include "effects/Effects.h"
#include <cstdlib>

Effects effects;

unsigned long previousMillis = 0;
const long interval = 6000; // 5 segundos entre os efeitos
int currentEffect = 0;

void setup() {
  effects.init();
  delay(100);
}

void loop() { effects.snowSparkle(CRGB::White); }

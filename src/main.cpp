#include "FastLED.h"
#include "effects/Effects.h"
#include <cstdlib>

Effects effects;

void setup() {
  effects.init();
  delay(100);
}

void loop() { effects.rainbowCycle(); }

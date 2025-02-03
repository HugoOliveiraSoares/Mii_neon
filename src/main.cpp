#include "FastLED.h"
#include "Modes.h"

Modes modes;

void setup() {
  modes.init();
  delay(1000);
}

void loop() {
  // modes.blink(CRGB::Red, CRGB::Blue);
  // EVERY_N_MILLISECONDS(20) { modes.pacifica_loop(); }
  modes.cyclon();
}

#include "FastLED.h"
#include "effects/Effects.h"
#include <cstdlib>

Effects effects;

Segment seg1 = {0, NUM_LEDS_STRIP1};
Segment seg2 = {NUM_LEDS_STRIP1, NUM_LEDS_STRIP2};

void setup() {
  effects.init();
  delay(100);
}

void loop() {

  effects.fill(CRGB::Blue);
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

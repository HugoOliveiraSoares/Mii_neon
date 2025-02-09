#include "LedService.h"

extern Effects effects;

LedService::LedService() {}

void LedService::setColor(CRGB color) { effects.fill(color); }

void LedService::setBright(int bright) {

  FastLED.setBrightness(bright);
  FastLED.show();
}

void LedService::setMode() {}

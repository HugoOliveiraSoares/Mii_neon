#include "LedService.h"

extern Effects effects;

LedService::LedService() {}

void LedService::setColor(CRGB color) { effects.fill(color); }

void LedService::setBright(int bright) {

  FastLED.setBrightness(bright);
  FastLED.show();
}

void LedService::setMode() {}

std::vector<String> LedService::getModes() {
  std::vector<String> effectsNames;
  for (int i = 0; i < EFFECTS_COUNT; i++) {
    EffectsEnum effects = static_cast<EffectsEnum>(i);
    effectsNames.push_back(toString(effects));
  }
  return effectsNames;
}

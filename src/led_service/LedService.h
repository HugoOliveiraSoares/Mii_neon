#pragma once
#include "../effects/Effects.h"
#include "../effects/EffectsEnum.h"
#include <vector>

class LedService {
public:
  LedService();
  void setColor(CRGB color);
  void setBright(int bright);
  void setMode();
  std::vector<String> getModes();

private:
};

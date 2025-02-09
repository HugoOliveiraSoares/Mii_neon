#pragma once
#include "../effects/Effects.h"

class LedService {
public:
  LedService();
  void setColor(CRGB color);
  void setBright(int bright);
  void setMode();

private:
};

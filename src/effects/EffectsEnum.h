#ifndef EFFECTS_ENUM_H
#define EFFECTS_ENUM_H

enum EffectsEnum {
  Mii,
  Estatico,
  Blink,
  Pacifica,
  Cyclon,
  ColorWipe,
  ColorWipeInverse,
  SnowSparkle,
  Rainbow,
  // New Effects
  EFFECTS_COUNT
};

inline const char *toString(EffectsEnum effect) {
  switch (effect) {
  case Mii:
    return "Mii";
  case Estatico:
    return "Estatico";
  case Blink:
    return "Blink";
  case Pacifica:
    return "Pacifica";
  case Cyclon:
    return "Cyclon";
  case ColorWipe:
    return "ColorWipe";
  case ColorWipeInverse: // TODO: Implementar
    return "ColorWipeInverse";
  case SnowSparkle:
    return "SnowSparkle";
  case Rainbow:
    return "Rainbow";
  default:
    return "DESCONHECIDO";
  }
}

#endif

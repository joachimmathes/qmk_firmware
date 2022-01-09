#pragma once

enum layers {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  OLED_TOG = SAFE_RANGE,
};

#define RAI_ENT LT(_RAISE, KC_ENT)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define ADJUST MO(_ADJUST)

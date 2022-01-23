#pragma once

/* Enums for layers */
enum layers {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _ADJUST,
};

/* Enums for custom keycodes */
enum custom_keycodes {
  OLED_TOG = SAFE_RANGE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)
#define LGUI_SPC LGUI_T(KC_SPC)

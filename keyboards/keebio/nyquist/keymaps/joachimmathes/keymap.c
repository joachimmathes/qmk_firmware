#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |    |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   Ö  |Enter |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   -  |   Ä  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Esc  |Adjust| GUI  | Alt  |Lower |Space |    |Space |Raise | Del  |Print |   ß  |   Ü  |
 * `-----------------------------------------'    `-----------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12( \
  KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC, \
  KC_LCTL, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, KC_ENT, \
  KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, DE_ADIA, \
  KC_ESC,  ADJUST,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_DEL,  KC_PSCR, DE_SS,   DE_UDIA \
),

/* Lower
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |    |      | Home | Up   | End  | Pgup |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Ctrl |  F5  |  F6  |  F7  |  F8  |      |    |      | Left | Down |Right | Pgdn |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|  F9  |  F10 |  F11 |  F12 |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      | Gui  | Alt  |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_HOME, KC_UP,   KC_END,   KC_PGUP, _______, \
  KC_LCTL, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______, \
  KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, _______,  _______, _______ \
),

/* Raise
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |   ^  |   !  |   ?  |   {  |   }  |   %  |     |   `  |   7  |   8  |   9  |   +  |   *  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Ctrl |   &  |   $  |   (  |   )  |   \  |     |   "  |   4  |   5  |   6  |   -  |   /  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   |  |   @  |   [  |   ]  |   ~  |     |   '  |   1  |   2  |   3  |   =  |   #  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |    < |   >  | Gui  | Alt  |      |      |     |      |      |   0  |   .  |      |      |
 * `-----------------------------------------'     `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  DE_CIRC, DE_EXLM, DE_QUES, DE_LCBR, DE_RCBR, DE_PERC, DE_GRV,  KC_7,    KC_8, KC_9,   DE_PLUS, DE_ASTR, \
  KC_LCTL, DE_AMPR, DE_DLR,  DE_LBRC, DE_RBRC, DE_BSLS, DE_DQUO, KC_4,    KC_5, KC_6,   DE_MINS, DE_SLSH, \
  _______, DE_PIPE, DE_AT,   DE_LPRN, DE_RPRN, DE_TILD, DE_QUOT, KC_1,    KC_2, KC_3,   DE_EQL,  DE_HASH, \
  DE_LABK, DE_RABK, KC_LGUI, KC_LALT, _______, _______, _______, _______, KC_0, DE_DOT, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |RGB Tg|RGBRMd|RGB Md|Hue Dn|Hue Up|     |      |BL Tg |BL Dec|BL Inc|      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |RGB MP|RGB MB|RGB MK|Sat Dn|Sat Up|     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |RGBMTW|      |      |Val Dn|Val Up|     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Reset|      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------'     `------+------+------+------+------+------|
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, RGB_TOG,  RGB_MOD, RGB_RMOD, RGB_HUD, RGB_HUI, _______, BL_TOGG, BL_DEC,  BL_INC,  _______, _______, \
  _______, RGB_M_P,  RGB_M_B, RGB_M_K,  RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, \
  _______, RGB_M_TW, _______, _______,  RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, \
  RESET,   _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

/* Local Variables: */
/* compile-command: "qmk compile -kb keebio/nyquist/rev3 -km joachimmathes" */
/* End: */

/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_german.h"
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTZ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Z,    DE_U,    DE_I,    DE_O,   DE_P,  DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    DE_K,    DE_L, DE_ODIA, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, DE_MINS,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, LOWER, LGUI_SPC,      KC_ENT,  RAISE, KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      KC_PSCR, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,     XXXXXXX, ADJUST, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_CIRC, DE_EXLM, DE_QUES, DE_PERC,  DE_GRV, DE_LCBR,                      DE_RCBR,    KC_7,    KC_8,    KC_9, DE_PLUS, DE_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, DE_AMPR,  DE_DLR, DE_BSLS, DE_DQUO, DE_LBRC,                      DE_RBRC,    KC_4,    KC_5,    KC_6, DE_MINS, DE_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, DE_PIPE,   DE_AT, DE_TILD, DE_QUOT, DE_LPRN,                      DE_RPRN,    KC_1,    KC_2,    KC_3,  DE_EQL, DE_HASH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, ADJUST,  DE_LABK,    DE_RABK, _______,    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, RGB_TOG, RGB_MOD,RGB_RMOD, RGB_HUD, RGB_HUI,                      XXXXXXX,OLED_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_M_P, RGB_M_B, XXXXXXX, RGB_SAD, RGB_SAI,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

const key_override_t shift_dollar_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_DLR, DE_EURO);
const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_dollar_key_override,
    NULL
};

#ifdef OLED_ENABLE

uint16_t wpm_timer = 0;
uint16_t current_wpm = 0;
uint8_t y = 31;
float max_wpm = 110.0f; // WPM value at the top of the graph window
uint8_t vertical_count = 0;
bool vertical_lines = false;

#define L_QWERTZ 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_logo(void) {
    static const char PROGMEM split_logo[] = {
        0x00, 0x00, 0xc0, 0xc8, 0x38, 0x38, 0x1c, 0x1c, 0x3c, 0x7c, 0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
        0x0e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x3e, 0x3e, 0x1e, 0x1e, 0x3e, 0x3e, 0x3e, 0x3e,
        0x7c, 0x7c, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8,
        0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0,
        0xf0, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x10, 0x18, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x3c, 0x3c, 0x7c, 0x7c, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0,
        0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80,
        0x80, 0x80, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x07, 0x0f, 0x0f, 0x8f,
        0x86, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0,
        0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0x78, 0x78,
        0x78, 0x7c, 0xfc, 0xfc, 0xfc, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x1c, 0x18, 0x10, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f,
        0x1f, 0x1f, 0x3f, 0x3f, 0x7e, 0x7e, 0x7e, 0x7c, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x3f, 0x3f,
        0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07,
        0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07,
        0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

        oled_write_raw_P(split_logo, sizeof(split_logo));
}

void oled_render_wpm(void) {
    current_wpm = get_current_wpm();

    if(timer_elapsed(wpm_timer) > GRAPH_REFRESH_INTERVAL_MS) {

		y = 32 - ((current_wpm / max_wpm) * 32);

		for(int i = 0; i <= GRAPH_LINE_THICKNESS_PX - 1; i++){
			oled_write_pixel(1, y + i, true);
		}

        if(vertical_count == GRAPH_VERTICAL_LINE_INTERVAL) {
            vertical_count = 0;
            while(y <= 32){
                oled_write_pixel(1, y, true);
                y++;
            }
        } else {
            for(int i = 32; i > y; i--){
                if(i % GRAPH_HORIZONTAL_LINE_INTERVAL == 0){
                    oled_write_pixel(1, i, true);
                }
            }
            vertical_count++;
        }

        oled_pan(false);

        wpm_timer = timer_read();
    }

    if(current_wpm > 0) {
        oled_set_cursor(13, 3);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(current_wpm, '0'), false);
    }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
      oled_render_wpm();
    } else {
      oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

/* Local Variables: */
/* compile-command: "qmk compile -kb crkbd -km joachimmathes" */
/* End: */

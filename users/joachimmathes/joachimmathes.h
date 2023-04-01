/* Copyright 2022 Joachim Mathes joachim_mathes@web.de @joachimmathes
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "keymap_german.h"

enum user_layers {
    LAYER0,
    LAYER1,
    LAYER2,
    LAYER3,
};

#define KC_L1 MO(LAYER1)
#define KC_L2 MO(LAYER2)
#define KC_L3 MO(LAYER3)
#define DE_GUIT LGUI_T(DE_ODIA)

#define LAYOUT_LAYER0 \
    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,     DE_Z,    DE_U,    DE_I,     DE_O,     DE_P, \
    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,     DE_H,    DE_J,    DE_K,     DE_L,     DE_GUIT, \
    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,     DE_N,    DE_M,    DE_COMM,  DE_DOT,   DE_MINS, \
    XXXXXXX, XXXXXXX, KC_LCTL, KC_L2,   KC_SPC,   KC_RSFT, KC_L1,   KC_LALT,  XXXXXXX,  XXXXXXX

#define LAYOUT_LAYER1 \
    DE_CIRC, DE_HASH, DE_PERC, DE_BSLS, DE_DEG,   DE_PLUS, DE_7,    DE_8,     DE_9,     DE_MINS, \
    DE_EURO, DE_DLR,  DE_EXLM, DE_QUES, DE_UNDS,  DE_ASTR, DE_4,    DE_5,     DE_6,     DE_SLSH, \
    DE_PIPE, DE_AT,   DE_TILD, DE_AMPR, DE_SECT,  DE_0,    DE_1,    DE_2,     DE_3,     DE_EQL, \
    XXXXXXX, XXXXXXX, KC_LCTL, KC_L3,   KC_SPC,   KC_RSFT, _______, KC_LALT,  XXXXXXX,  XXXXXXX

#define LAYOUT_LAYER2 \
    KC_TAB,  XXXXXXX, DE_LCBR, DE_RCBR, DE_GRV,   KC_PGUP, KC_HOME, KC_UP,    KC_END,   KC_BSPC, \
    KC_ESC,  XXXXXXX, DE_LBRC, DE_RBRC, DE_DQUO,  KC_PGDN, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_ENT, \
    DE_LABK, DE_RABK, DE_LPRN, DE_RPRN, DE_QUOT,  KC_PSCR, DE_SS,   DE_ADIA,  DE_UDIA,  KC_DEL, \
    XXXXXXX, XXXXXXX, KC_LCTL, _______, KC_SPC,   KC_RSFT, KC_L3,   KC_LALT,  XXXXXXX,  XXXXXXX

#define LAYOUT_LAYER3 \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   BL_TOGG,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUD,  RGB_HUI, \
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   BL_DOWN,  RGB_M_P, RGB_M_B, RGB_M_K,  RGB_SAD,  RGB_SAI, \
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  BL_UP,    RGB_M_TW,XXXXXXX, XXXXXXX,  RGB_VAD,  RGB_VAI, \
    XXXXXXX, XXXXXXX, KC_LCTL, _______, KC_SPC,   KC_RSFT, _______, KC_LALT,  XXXXXXX,  XXXXXXX

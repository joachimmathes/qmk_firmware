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

#include QMK_KEYBOARD_H
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
#define KC_GUISPC LGUI_T(KC_SPC)

#define LAYOUT_LAYER0 \
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,     DE_Z,    DE_U,    DE_I,     DE_O,     DE_P,    DE_UDIA, \
    KC_LCTL, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,     DE_H,    DE_J,    DE_K,     DE_L,     DE_ODIA, DE_ADIA, \
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,     DE_N,    DE_M,    DE_COMM,  DE_DOT,   DE_MINS, DE_SS, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_L2,   KC_GUISPC,KC_ENT,  KC_L1,   KC_ESC,   XXXXXXX,  XXXXXXX, XXXXXXX

#define LAYOUT_LAYER1 \
    DE_CIRC, DE_EXLM, DE_QUES, DE_PERC, DE_GRV,  DE_LCBR,  DE_RCBR, KC_7,    KC_8,     KC_9,     DE_PLUS, DE_ASTR, \
    KC_LCTL, DE_AMPR, DE_DLR,  DE_BSLS, DE_DQUO, DE_LBRC,  DE_RBRC, KC_4,    KC_5,     KC_6,     DE_MINS, DE_SLSH, \
    KC_LSFT, DE_PIPE, DE_AT,   DE_TILD, DE_QUOT, DE_LPRN,  DE_RPRN, KC_1,    KC_2,     KC_3,     DE_EQL,  DE_HASH, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_L3,   DE_LABK,  DE_RABK, _______, KC_0,     XXXXXXX,  XXXXXXX, XXXXXXX

#define LAYOUT_LAYER2 \
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,  KC_PSCR, KC_HOME, KC_UP,    KC_END,   KC_PGUP, KC_BSPC, \
    KC_LCTL, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,  XXXXXXX, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_PGDN, KC_DEL, \
    KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX, KC_L3,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX

#define LAYOUT_LAYER3 \
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUD, RGB_HUI,  XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, \
    XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_K, RGB_SAD, RGB_SAI,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, RGB_M_TW,XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

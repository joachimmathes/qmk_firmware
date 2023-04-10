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
#define LGUI_SPC LGUI_T(KC_SPC)
#define LCTL_A LCTL_T(DE_A)
#define LCTL_OE LCTL_T(DE_ODIA)
#define LALT_S LALT_T(DE_S)
#define LALT_L LALT_T(DE_L)
#define GUIT_D LGUI_T(DE_D)
#define GUIT_K LGUI_T(DE_K)

/* --------------------------------------------------------------------------- */
/* LAYOUT ORTHO 4x12                                                           */
/* --------------------------------------------------------------------------- */
#define LAYOUT_ORTHO_4x12_LAYER0 \
    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     KC_BSPC, \
    KC_LCTL,  DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_ODIA,  KC_ENT, \
    KC_LSFT,  DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,  DE_ADIA, \
    KC_ESC,   ADJUST,   KC_LGUI,  KC_LALT,  KC_L2,    KC_SPC,   KC_SPC,   KC_L1,    KC_DEL,   KC_PSCR,  DE_SS,    DE_UDIA

#define LAYOUT_ORTHO_4x12_LAYER1 \
    DE_CIRC,  DE_EXLM,  DE_QUES,  DE_LCBR,  DE_RCBR,  DE_PERC,  DE_GRV,   KC_7,     KC_8,     KC_9,     DE_PLUS,  DE_ASTR, \
    KC_LCTL,  DE_AMPR,  DE_DLR,   DE_LBRC,  DE_RBRC,  DE_BSLS,  DE_DQUO,  KC_4,     KC_5,     KC_6,     DE_MINS,  DE_SLSH, \
    _______,  DE_PIPE,  DE_AT,    DE_LPRN,  DE_RPRN,  DE_TILD,  DE_QUOT,  KC_1,     KC_2,     KC_3,     DE_EQL,   DE_HASH, \
    DE_LABK,  DE_RABK,  KC_LGUI,  KC_LALT,  KC_L3,    _______,  _______,  _______,  KC_0,     DE_DOT,   _______,  _______

#define LAYOUT_ORTHO_4x12_LAYER2 \
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______, \
    KC_LCTL,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,  _______, \
    KC_LSFT,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______, \
    _______,  _______,  KC_LGUI,  KC_LALT,  _______,  _______,  _______,  KC_L3,    _______,  _______,  _______,  _______

#define LAYOUT_ORTHO_4x12_LAYER3 \
    _______,  RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUD,  RGB_HUI,  _______,  BL_TOGG,  BL_DEC,   BL_INC,   _______,  _______, \
    _______,  RGB_M_P,  RGB_M_B,  RGB_M_K,  RGB_SAD,  RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______, \
    _______,  RGB_M_TW, _______,  _______,  RGB_VAD,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______, \
    RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______


/* --------------------------------------------------------------------------- */
/* LAYOUT SPLIT 3x6+3                                                          */
/* --------------------------------------------------------------------------- */
#define LAYOUT_SPLIT_3x6_3_LAYER0 \
    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     DE_UDIA, \
    KC_LCTL,  DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_ODIA,  DE_ADIA, \
    KC_LSFT,  DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,  DE_SS, \
                                  KC_LALT,  LGUI_SPC, KC_L2,    KC_L1,    KC_ENT,   KC_ESC

#define LAYOUT_SPLIT_3x6_3_LAYER1 \
    DE_CIRC,  DE_EXLM,  DE_QUES,  DE_PERC,  DE_GRV,   DE_LCBR,  DE_RCBR,  KC_7,     KC_8,     KC_9,     DE_PLUS,  DE_ASTR, \
    KC_LCTL,  DE_AMPR,  DE_DLR,   DE_BSLS,  DE_DQUO,  DE_LBRC,  DE_RBRC,  KC_4,     KC_5,     KC_6,     DE_MINS,  DE_SLSH, \
    KC_LSFT,  DE_PIPE,  DE_AT,    DE_TILD,  DE_QUOT,  DE_LPRN,  DE_RPRN,  KC_1,     KC_2,     KC_3,     DE_EQL,   DE_HASH, \
                                  KC_LALT,  DE_LABK,  KC_L3,    _______,  DE_RABK,  KC_0

#define LAYOUT_SPLIT_3x6_3_LAYER2 \
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  XXXXXXX, \
    KC_LCTL,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,  XXXXXXX, \
    KC_LSFT,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
                                  XXXXXXX,  XXXXXXX,  _______,  KC_L3,    XXXXXXX,  XXXXXXX

#define LAYOUT_SPLIT_3x6_3_LAYER3 \
    XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUD,  RGB_HUI,  XXXXXXX,  OLED_TOG, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
    XXXXXXX,  RGB_M_P,  RGB_M_B,  XXXXXXX,  RGB_SAD,  RGB_SAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_VAD,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
                                  XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX


/* --------------------------------------------------------------------------- */
/* LAYOUT SPLIT 3x5+3                                                          */
/* --------------------------------------------------------------------------- */
#define LAYOUT_SPLIT_3x5_3_LAYER0 \
    DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P, \
    DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_GUIT, \
    DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS, \
                        KC_LCTL,  KC_L2,    KC_SPC,   KC_RSFT,  KC_L1,    KC_LALT

#define LAYOUT_SPLIT_3x5_3_LAYER1 \
    DE_CIRC,  DE_HASH,  DE_PERC,  DE_BSLS,  DE_DEG,   DE_PLUS,  DE_7,     DE_8,     DE_9,     DE_MINS, \
    DE_EURO,  DE_DLR,   DE_EXLM,  DE_QUES,  DE_UNDS,  DE_ASTR,  DE_4,     DE_5,     DE_6,     DE_SLSH, \
    DE_PIPE,  DE_AT,    DE_TILD,  DE_AMPR,  DE_SECT,  DE_0,     DE_1,     DE_2,     DE_3,     DE_EQL, \
                        KC_LCTL,  KC_L3,    KC_SPC,   KC_RSFT,  _______,  KC_LALT

#define LAYOUT_SPLIT_3x5_3_LAYER2 \
    KC_TAB,   XXXXXXX,  DE_LCBR,  DE_RCBR,  DE_GRV,   KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_BSPC, \
    KC_ESC,   XXXXXXX,  DE_LBRC,  DE_RBRC,  DE_DQUO,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_ENT, \
    DE_LABK,  DE_RABK,  DE_LPRN,  DE_RPRN,  DE_QUOT,  KC_PSCR,  DE_SS,    DE_ADIA,  DE_UDIA,  KC_DEL, \
                        KC_LCTL,  _______,  KC_SPC,   KC_RSFT,  KC_L3,    KC_LALT

#define LAYOUT_SPLIT_3x5_3_LAYER3 \
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    BL_TOGG,  RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUD,  RGB_HUI, \
    KC_F5,    KC_F6,    KC_F7,    KC_F8,    BL_DOWN,  RGB_M_P,  RGB_M_B,  RGB_M_K,  RGB_SAD,  RGB_SAI, \
    KC_F9,    KC_F10,   KC_F11,   KC_F12,   BL_UP,    RGB_M_TW, XXXXXXX,  XXXXXXX,  RGB_VAD,  RGB_VAI, \
                        KC_LCTL,  _______,  KC_SPC,   KC_RSFT,  _______,  KC_LALT


/* --------------------------------------------------------------------------- */
/* LAYOUT SPLIT 3x5+2                                                          */
/* --------------------------------------------------------------------------- */
#define LAYOUT_SPLIT_3x5_2_LAYER0 \
    DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P, \
    LCTL_A,   LALT_S,   GUIT_D,   DE_F,     DE_G,     DE_H,     DE_J,     GUIT_K,   LALT_L,   LCTL_OE, \
    DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS, \
                                  KC_L2,    KC_SPC,   KC_RSFT,  KC_L1

#define LAYOUT_SPLIT_3x5_2_LAYER1 \
    DE_CIRC,  DE_HASH,  DE_PERC,  DE_BSLS,  DE_DEG,   DE_PLUS,  DE_7,     DE_8,     DE_9,     DE_MINS, \
    DE_EURO,  DE_DLR,   DE_EXLM,  DE_QUES,  DE_UNDS,  DE_ASTR,  DE_4,     DE_5,     DE_6,     DE_SLSH, \
    DE_PIPE,  DE_AT,    DE_TILD,  DE_AMPR,  DE_SECT,  DE_0,     DE_1,     DE_2,     DE_3,     DE_EQL, \
                                  KC_L3,    KC_SPC,   KC_RSFT, _______

#define LAYOUT_SPLIT_3x5_2_LAYER2 \
    KC_TAB,   XXXXXXX,  DE_LCBR,  DE_RCBR,  DE_GRV,   KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_BSPC, \
    KC_ESC,   XXXXXXX,  DE_LBRC,  DE_RBRC,  DE_DQUO,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_ENT, \
    DE_LABK,  DE_RABK,  DE_LPRN,  DE_RPRN,  DE_QUOT,  KC_PSCR,  DE_SS,    DE_ADIA,  DE_UDIA,  KC_DEL, \
                                  _______,  KC_SPC,   KC_RSFT,  KC_L3

#define LAYOUT_SPLIT_3x5_2_LAYER3 \
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    BL_TOGG,  RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUD,  RGB_HUI, \
    KC_F5,    KC_F6,    KC_F7,    KC_F8,    BL_DOWN,  RGB_M_P,  RGB_M_B,  RGB_M_K,  RGB_SAD,  RGB_SAI, \
    KC_F9,    KC_F10,   KC_F11,   KC_F12,   BL_UP,    RGB_M_TW, XXXXXXX,  XXXXXXX,  RGB_VAD,  RGB_VAI, \
                                  _______,  KC_SPC,   KC_RSFT,  _______

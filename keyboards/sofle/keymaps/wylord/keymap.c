 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

enum {
  BASE = 0,
  NUM = 1,
  BRACK = 2,
  ARROWS = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// MAC Layout
[BASE] = LAYOUT(
  LT(NUM,KC_GRV),   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  LT(BRACK,KC_TAB), KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  LCTL_T(KC_ESC),   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,  KC_C,  KC_V,  KC_B,  KC_MUTE,                 _______,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
               LCTL(KC_LALT),KC_LALT,KC_LGUI, KC_SPC, MO(ARROWS),          KC_ENT, KC_SPC, RCTL(KC_BSLS), _______, _______ 
),
[NUM] = LAYOUT(
  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                    _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
  _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,                    _______,KC_7,   KC_8,   KC_9,   KC_PPLS,  KC_BSPC,
  _______, KC_F11, KC_F12,_______,_______,_______,                    _______,KC_4,   KC_5,   KC_6,   KC_PPLS, _______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,KC_1,   KC_2,   KC_3,   KC_PENT, _______,
                  _______,_______,_______,_______,_______,    _______,_______,KC_0,   KC_0,   KC_DOT
),

[BRACK] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LPRN,KC_RPRN,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LCBR,KC_RCBR,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LBRC,KC_RBRC,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
              _______,_______,_______,_______,_______,            _______,_______,_______,_______,_______
),

[ARROWS] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                    KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
              _______,_______,_______,_______,_______,            _______,KC_RCTL,_______,_______,_______
),
// [4] = LAYOUT(
//   _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
//   _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
//   _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
//   _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
//               _______,_______,_______,_______,_______,            _______,_______,_______,_______,_______
// ),
};

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

#include <stdio.h>

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef TAPPING_TOGGLE 
  #undef TAPPING_TOGGLE
  #define TAPPING_TOGGLE 2
#endif

#ifdef OLED_DRIVER_ENABLE
  #include "crab.c"
  #include "oled_base.c"
#endif
// char wpm_str[10];
#include "encoder.c"
#include "layers.c"
//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// MAC Layout
[MAC] = LAYOUT(
  LT(NUM,KC_1),     KC_2,  KC_3,  KC_4,  KC_5,  KC_6,                            KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_GRV,
  LT(BRACK,KC_TAB), KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  LCTL_T(KC_ESC),   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,  KC_C,  KC_V,  KC_B,  KC_MPLY,                 LCTL(LGUI(KC_Q)),KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        LCTL(KC_LALT),KC_LALT,MO(ARROWS),KC_SPC, KC_LGUI,                KC_ENT, KC_SPC, KC_EQL, RCTL_T(KC_BSLS),  DF(WINDOWS) 
),
[WINDOWS] = LAYOUT(
  LT(NUM,KC_1),     KC_2,  KC_3,  KC_4,  KC_5,  KC_6,                            KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_GRV,
  LT(BRACK,KC_TAB), KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  LCTL_T(KC_ESC),   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,  KC_C,  KC_V,  KC_B,  KC_MPLY,                LGUI(KC_L),KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        KC_LGUI, KC_LALT,MO(ARROWS),KC_SPC, KC_LCTL,                             KC_ENT, KC_SPC, KC_EQL, KC_BSLS,  DF(GAME) 
),
[GAME] = LAYOUT(
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                              KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_GRV,
  KC_TAB,    KC_T,  KC_Q,  KC_W,  KC_E,  KC_R,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_LSFT,   KC_G,  KC_A,  KC_S,  KC_D,  KC_F,                              KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTL,   KC_B,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_MPLY,   LCTL(LGUI(KC_Q)),KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        KC_LGUI, MO(ARROWS), KC_N,KC_SPC, KC_M,                  KC_ENT, KC_SPC, KC_EQL, RCTL_T(KC_BSLS),  DF(MAC) 
),
[NUM] = LAYOUT(
  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                    _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
  _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,                    _______,KC_7,   KC_8,   KC_9,   KC_PPLS,  KC_BSPC,
  _______, _______, _______,_______,KC_F11,KC_F12,                    _______,KC_4,   KC_5,   KC_6,   KC_PPLS, _______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,KC_1,   KC_2,   KC_3,   KC_PENT, _______,
                  _______,_______,_______,_______,_______,    _______,_______,KC_0,   KC_0,   KC_DOT
),

[BRACK] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LCBR,KC_RCBR,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LBRC,KC_RBRC,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
              _______,_______,_______,_______,_______,           _______,_______,_______,_______,_______
),

[ARROWS] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,KC_MPRV,KC_MNXT,
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                    KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,_______,_______,
  _______,_______,_______,_______,_______,_______,KC_MPRV,    KC_MNXT,_______,_______,_______,_______,_______,_______,
              _______,_______,_______,KC_MPRV,KC_MNXT,            KC_RCTL,XXXXXXX,XXXXXXX,_______,_______
),
// [4] = LAYOUT(
//   _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
//   _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
//   _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
//   _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
//               _______,_______,_______,_______,_______,            _______,_______,_______,_______,_______
// ),
};
unsigned char base = MAC;
unsigned char phase = 0;
unsigned int chars_typed = 0;
char chars_typed_str[12];

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  phase++;
  if (phase % 2 == 0) {
    chars_typed++;
    sprintf(chars_typed_str, "%d", chars_typed);
  }
  if (phase > 32) {
    phase = 0;
  }
  switch (keycode) {
    case DF(WINDOWS):
      base = WINDOWS;
      return true;
    case DF(MAC):
      base = MAC;
      return true;
    case DF(GAME):
      base = GAME;
      return true;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  if (is_keyboard_master()) {
    print_status_narrow(base, phase, chars_typed_str);
  } else {
   oled_render_anim();
  }
}
#endif


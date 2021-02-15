/* Copyright 2018
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

enum foobar_layers {
  QWERTY,
  ESCAPE,
  ARROWS,
  NUMS,
  FKEYS,
  BRKT,
};

#define ESCAPE_N  LT(ESCAPE, KC_N)
#define ARROWS_B  LT(ARROWS, KC_B)
#define NUMS_V    LT(NUMS, KC_V)
#define NUMS_M    LT(NUMS, KC_M)
#define BRKT_C    LT(BRKT, KC_C)

enum combo_events {
  JK_SPC, DF_SPC,
  AS_LSHIFT, LS_RSHIFT,
  ZX_LCTRL, DS_RCTRL,
  XC_LGUI, CD_RGUI,
  CV_LALT, MC_RALT
};

// Press jk or df for space
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

// Press as or lsemicolon for shift
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ls_combo[] = {KC_L, KC_SCLN, COMBO_END};

// Press zx or dotslash for control
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

// Press xc or commadot for meta
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};

// Press cv or mcomma for alt
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {\
  [JK_SPC] = COMBO(jk_combo, KC_SPC),\
  [DF_SPC] = COMBO(df_combo, KC_SPC),\
  [AS_LSHIFT] = COMBO(as_combo, KC_LSFT),\
  [LS_RSHIFT] = COMBO(ls_combo, KC_RSFT),\
  [ZX_LCTRL] = COMBO(zx_combo, KC_LCTRL),\
  [DS_RCTRL] = COMBO(ds_combo, KC_RCTRL),\
  [XC_LGUI] = COMBO(xc_combo, KC_LGUI),\
  [CD_RGUI] = COMBO(cd_combo, KC_RGUI),\
  [CV_LALT] = COMBO(cv_combo, KC_LALT),\
  [MC_RALT] = COMBO(mc_combo, KC_RALT),\
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_split(
    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,   KC_X,  BRKT_C,  NUMS_V,ARROWS_B,ESCAPE_N,  NUMS_M,    KC_COMM, KC_DOT,  KC_SLSH
  ),

  [ESCAPE] = LAYOUT_split(
    KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,
    _______, _______, _______, _______,  KC_SPC, _______, _______, _______, _______, _______
  ),

  [ARROWS] = LAYOUT_split(
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSPC,
    KC_LSFT, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
    _______, _______, _______, _______, _______, KC_SPC, _______,  _______, _______, _______
  ),

  [NUMS] = LAYOUT_split(
    KC_1,    KC_2,    KC_3,      KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, _______, _______,   _______, _______,  _______, _______, _______, _______, KC_RSFT,
    _______, _______, MO(FKEYS), _______, KC_SPC,   KC_SPC,  _______, MO(FKEYS), _______, _______
  ),

  [FKEYS] = LAYOUT_split(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_LSFT, _______, _______, _______, KC_F11, KC_F12, _______, _______, _______, KC_RSFT,
    _______, _______, _______, _______, KC_SPC, KC_SPC, _______, _______, _______, _______
  ),

  [BRKT] = LAYOUT_split(
    _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

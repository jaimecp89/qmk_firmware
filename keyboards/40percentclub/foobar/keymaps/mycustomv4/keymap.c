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
  FN2,
  FN3
};

enum combo_events {
    JK_CMB,
    SD_CMB, KL_CMB,
    CV_CMB, MCOMM_CMB,
    AS_CMB, LSCOL_CMB
};

const uint16_t PROGMEM jk_cmb[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM sd_cmb[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_cmb[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM cv_cmb[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcomm_cmb[] = {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM we_cmb[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_cmb[] = {KC_I, KC_O, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {\
  [JK_CMB] = COMBO(jk_cmb, KC_SPC),\
  [SD_CMB] = COMBO_ACTION(sd_cmb),\
  [KL_CMB] = COMBO_ACTION(kl_cmb),\
  [CV_CMB] = COMBO_ACTION(cv_cmb),\
  [MCOMM_CMB] = COMBO_ACTION(mcomm_cmb),\
  [AS_CMB] = COMBO(we_cmb, KC_LSFT),\
  [LSCOL_CMB] = COMBO(io_cmb, KC_RSFT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_split(
    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
  ),

  [FN2] = LAYOUT_split(
    KC_TAB,  KC_DQT,  KC_MINS, KC_GRV,  KC_EQL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
    KC_ESC,  KC_QUOT, KC_LBRC, KC_BSLS, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, _______, KC_LSFT, KC_RSFT, _______, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [FN3] = LAYOUT_split(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
  )

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

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SD_CMB:
    case KL_CMB:
      if (pressed) {
        layer_on(FN2);
      }else{
        layer_off(FN2);
      }
      break;
    case CV_CMB:
    case MCOMM_CMB:
      if (pressed) {
        layer_on(FN3);
      }else{
        layer_off(FN3);
      }
      break;
  }
}

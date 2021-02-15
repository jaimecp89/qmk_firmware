/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QW 0
#define _FN 1
#define _FN2 2
#define _FN3 3


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ENYE = SAFE_RANGE,
    ATILDE,
    ETILDE,
    ITILDE,
    OTILDE,
    UTILDE,
    UDIER,
    IQUES,
    IEXCL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN), MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,    KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,
    _______, KC_TAB,  KC_DQT,  KC_MINS, KC_GRV,  KC_EQL,  KC_P7,   KC_P8,   KC_P9,   KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   KC_BSPC, _______,
    _______, KC_ESC,  KC_QUOT, KC_LBRC, KC_BSLS, KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  KC_ENT,  _______,
    _______, KC_LCTL, KC_LGUI, KC_LALT, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______,  _______,  KC_RALT,  KC_RGUI, KC_RCTL, _______,
    _______, _______, KC_CAPS,   RESET, MO(_FN), MO(_FN), KC_P0,   _______, KC_PDOT, MO(_FN2), MO(_FN2), MO(_FN3), _______, _______, _______
  ),

  [_FN2] = LAYOUT_ortho_5x15( /* NUMBERS EASY ACCESS */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN3] = LAYOUT_ortho_5x15( /* SPANISH CHARS */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   IEXCL, _______,  ETILDE, _______, _______, _______, _______, _______, _______,  UTILDE,  ITILDE,  OTILDE, _______, _______,
    _______,  ATILDE, _______, _______, _______, _______, _______, _______, _______, _______,   UDIER, _______, _______,    ENYE, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   IQUES, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ENYE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0)  SS_TAP(X_KP_9)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4)  SS_TAP(X_KP_1)));
        }
      }
      break;
    case ATILDE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9)  SS_TAP(X_KP_3)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2)  SS_TAP(X_KP_5)));
        }
      }
      break;
    case ETILDE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0)  SS_TAP(X_KP_1)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3)  SS_TAP(X_KP_3)));
        }
      }
      break;
    case ITILDE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0)  SS_TAP(X_KP_5)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3)  SS_TAP(X_KP_7)));
        }
      }
      break;
    case OTILDE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1)  SS_TAP(X_KP_1)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4)  SS_TAP(X_KP_3)));
        }
      }
      break;
    case UTILDE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1)  SS_TAP(X_KP_8)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5)  SS_TAP(X_KP_0)));
        }
      }
      break;
    case UDIER:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
            unregister_code(KC_LSFT); unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2)  SS_TAP(X_KP_0)));
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5)  SS_TAP(X_KP_2)));
        }
      }
      break;
    case IQUES:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9)  SS_TAP(X_KP_1)));
      }
      break;
    case IEXCL:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6)  SS_TAP(X_KP_1)));
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

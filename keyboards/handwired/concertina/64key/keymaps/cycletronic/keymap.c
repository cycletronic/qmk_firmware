/* Copyright 2020-2021 Viktor Eikman
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

enum layer_names {
    _WORKMAN,  // keyboard-side Workman. Default.
    _QWERTY,   // keyboard-side Qwerty.
    _GAMING,   // Navigation clusters (only) change hands.
    _NUMERIC   // Numbers, function keys, special characters, mouse.
};

enum taps {
    PNX,  // Play/pause; next track.
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [PNX] = ACTION_TAP_DANCE_DOUBLE(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK),
};

// Shorthand:
#define LAYER_N MO(_NUMERIC)
#define LAYER_Q TG(_QWERTY)
#define LAYER_G TG(_GAMING)
#define PASTE LSFT(KC_INS)  // Terminal-compatible paste.
#define SLQ RALT(KC_9)  // Single left-side quotation mark (in Colemak).
#define SRQ RALT(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WORKMAN] = LAYOUT_64key(
                      SC_LSPO, KC_MINS, KC_EQL,                           KC_VOLD, KC_VOLU, SC_RSPC,
                      SC_LCPO, KC_LGUI, KC_BSPC, KC_ENT,         KC_MUTE, KC_TAB,  LAYER_N, SC_RCPC,
                               SC_LAPO, KC_SPC,  SLQ,            TD(PNX), KC_ESC,  SC_RAPC,

                      KC_D,    KC_R,    KC_W,    KC_B,           KC_J,    KC_F,    KC_U,    KC_P,
    KC_TAB,  KC_Q,    KC_S,    KC_H,    KC_T,    KC_G,           KC_Y,    KC_N,    KC_E,    KC_O,    KC_SCLN, KC_BSLS,
    KC_BSPC, KC_A,    KC_X,    KC_M,    KC_C,    KC_V,           KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_I,    KC_QUOT,
    KC_DEL,  KC_Z,    KC_HOME, KC_PGUP, KC_END,                           KC_LEFT, KC_UP,   KC_RGHT, KC_SLSH, KC_GRV,
                               KC_PGDN,                                            KC_DOWN
),

[_QWERTY] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                               _______, _______, _______,        _______, _______, _______,

                      KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,
    _______, KC_Q,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    _______,
    _______, KC_A,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    _______, _______, KC_SCLN, _______,
    _______, KC_Z,    _______, _______, _______,                          _______, _______, _______, _______, _______,
                               _______,                                            _______
),

[_GAMING] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                               _______, _______, _______,        _______, _______, _______,

                      _______, _______, _______, _______,        _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_UP,   KC_RGHT,                          KC_HOME, KC_PGUP, KC_END,  _______, _______,
                               KC_DOWN,                                            KC_PGDN
),

[_NUMERIC] = LAYOUT_64key(
                      _______, _______, _______,                          KC_ACL1, KC_ACL2, _______,
                      _______, _______, LAYER_Q, _______,        KC_ACL0, _______, _______, _______,
                               _______, _______, _______,        KC_SLEP, _______, _______,

                      KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,
    KC_F12,  KC_F1,   KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_F10,  KC_F11,
    _______, KC_1,    KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_APP,  KC_0,    PASTE,
    KC_INS,  KC_EXLM, KC_BTN1, KC_BTN3, KC_BTN2,                          KC_MS_L, KC_MS_U, KC_MS_R, KC_PSCR, QK_BOOT,
                               LAYER_G,                                            KC_MS_D
)
};

#include QMK_KEYBOARD_H
#include "5x6_whole_3_track.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_5x6_whole(
        KC_ESC , KC_1, KC_2, KC_3, KC_4, KC_5,                         KC_6, KC_7, KC_8,   KC_9,   KC_0,    _______,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I,   KC_O,   KC_P,    KC_MINS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K,   KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                         KC_N, KC_M, KC_COMM,KC_DOT ,KC_SLSH, KC_RSFT,
        KC_LCTL,KC_LALT,KC_LWIN,KC_LBRC,                                           KC_BSLS,KC_RWIN,KC_RALT,KC_RCTL,
RAISE, KC_SPC, KC_BSPC,      KC_DEL, KC_ENT, LOWER,
KC_LALT, KC_GRV
),

[_LOWER] = LAYOUT_5x6_whole(
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
        _______,_______,_______,_______,_______,KC_LBRC,                  KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                  KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______,RGB_VAI,RGB_SAI,RGB_HUI,RGB_MOD,RGB_TOG,                  _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
        _______,_______,_______,_______,                                                   KC_P0,_______,_______,_______,
        _______,KC_BTN3,KC_BTN1,        QK_BOOT,_______,_______,
        SNIPING,DRGSCRL
),

[_RAISE] = LAYOUT_5x6_whole(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                   KC_F6, KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,KC_LBRC,                   KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,KC_MUTE,
        _______,KC_LEFT,KC_UP,KC_DOWN,KC_RGHT,KC_LPRN,                     KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,
        _______,_______,_______,_______,_______,_______,                   _______,_______,_______,KC_VOLD,KC_VOLU,_______,
        _______,_______,_______,_______,                                                   SNIPING,DRGSCRL,KC_EQL,_______,
        _______,_______,_______,      KC_BTN1,KC_BTN3,KC_BTN2,
        _______,QK_BOOT
),
[_MOUSE] = LAYOUT_5x6_whole(
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,                                                   _______,_______,_______,_______,
        _______,KC_BTN3,KC_BTN1,        _______,_______,_______,
        SNIPING,DRGSCRL
)
};
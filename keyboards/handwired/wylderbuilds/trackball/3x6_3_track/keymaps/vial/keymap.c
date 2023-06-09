#include QMK_KEYBOARD_H
#include "3x6_3_track.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// TRACKBALL IN WALL LAYOUT (STANDARD 3X5_3)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                     KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_TAB,  KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                     KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                     KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                                    RAISE,   KC_SPC,  KC_TAB,          KC_LCTRL, KC_ENT, LOWER
        ),
    [_RAISE] = LAYOUT_split_3x6_3(
        _______,_______,_______,_______,_______,KC_LBRC,                    KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
        QK_BOOT,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                    KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______,DRGSCRL,SNIPING,KC_BTN3,KC_BTN2,KC_BTN1,                    KC_EQL, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                _______,   _______,  _______,          _______, _______, _______
        ),

    [_LOWER] = LAYOUT_split_3x6_3(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,KC_LBRC,                    KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,QK_BOOT,
        _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                    KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,KC_VOLU,
                                _______,   _______,  _______,         _______, _______, _______
        )
};

// STANDARD 3-KEY TRACKBALL CLUSTER ON RIGHT
//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    [_QWERTY] = LAYOUT_split_3x5_3(
//        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
//        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
//        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
//                                      RAISE, KC_SPC, KC_BSPC,      LOWER,
//                                                                   KC_ENT,
//                                                                KC_LALT
//        ),
//
//    [_LOWER] = LAYOUT_split_3x5_3(
//        _______,_______,_______,_______,KC_LBRC,                     KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS,
//        KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                     KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,
//        _______,_______,_______,_______,SNIPING,                     _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL,
//                                      KC_BTN3, KC_BTN1,DRGSCRL,    _______,
//                                                                   _______,
//                                                                QK_BOOT
//
//        ),
//
//    [_RAISE] = LAYOUT_split_3x5_3(
//        KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,
//        _______,_______,_______,_______,KC_LBRC,                     KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,
//        KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                     KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,
//                                        _______,_______,QK_BOOT,   _______,
//                                                                   _______,
//                                                                 _______
//        )
//};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_set_cursor(0, 5);
    oled_write_P(PSTR("WPM: "), false);

    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    // Host Keyboard LED Status

    oled_set_cursor(0, 8);
    led_t led_state = host_keyboard_led_state();

    oled_write_P(led_state.num_lock ? PSTR("NUMLK \n") : PSTR("    \n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK \n") : PSTR("    \n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("    \n"), false);

    return false;
}
#endif


void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
#else
    debug_enable=false;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;
#endif
}



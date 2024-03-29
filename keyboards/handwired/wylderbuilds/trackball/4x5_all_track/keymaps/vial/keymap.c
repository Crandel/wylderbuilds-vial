#include QMK_KEYBOARD_H
#include "4x5_all_track.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum wyld_keycodes {
    WYLD_AUTO_MS_TOG = SAFE_RANGE,
    WYLD_DPI_UP,
    WYLD_DPI_DOWN,
    WYLD_DPI_RESET
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_4x5(
            KC_1, KC_2, KC_3, KC_4, KC_5,                         KC_6, KC_7, KC_8,   KC_9,   KC_0,
            KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I,   KC_O,   KC_P,
            KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K,   KC_L,   KC_SCLN,
            KC_Z, KC_X, KC_C, KC_V, KC_B,                         KC_N, KC_M, KC_COMM,KC_DOT ,KC_SLSH,
                                      RAISE, KC_SPC,               LOWER,
                                      KC_TAB, KC_BSPC,             KC_ENT,
                                      KC_DEL, KC_GRV,     KC_MUTE, KC_LALT
    ),

    [_LOWER] = LAYOUT_4x5(
            QK_BOOT,WYLD_DPI_DOWN,WYLD_DPI_UP,WYLD_DPI_RESET,KC_LBRC,  KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS,
            KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                  KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,
            RGB_VAI, RGB_SAI,RGB_HUI, RGB_MOD, RGB_TOG,               KC_P0,   KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,
            KC_LPRN, KC_RPRN,_______,SNIPING, DRGSCRL,                _______, KC_LEFT, KC_DOWN, KC_UP,KC_RGHT,
                                        _______,_______,             _______,
                                        KC_BTN3,KC_BTN1,             _______,
                                        SNIPING,DRGSCRL,     KC_HOME,QK_BOOT
    ),

    [_RAISE] = LAYOUT_4x5(
            KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6, KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,
            _______,_______,_______,_______,KC_LBRC,                    KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,
            KC_LEFT,KC_UP,KC_DOWN,KC_RGHT,KC_LPRN,                      KC_RPRN,KC_MPRV,KC_MPLY,KC_VOLU,KC_VOLD,
            WYLD_AUTO_MS_TOG,_______,_______,_______,_______,           _______,_______,_______,_______,QK_BOOT,
                                        _______,_______,             _______,
                                        _______,_______,             _______,
                                        QK_BOOT,_______,     KC_HOME,_______
    ),
    [_MOUSE] = LAYOUT_4x5(
        _______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,
        _______,_______,_______,SNIPING, DRGSCRL,                       _______,_______,_______,_______,_______,
                                        _______,_______,             _______,
                                        KC_BTN3,KC_BTN1,             _______,
                                        SNIPING,DRGSCRL,     KC_MUTE,_______
        )
};

#ifdef POINTING_DEVICE_COMBINED
static void check_drag(report_mouse_t* mouse_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;

#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_X
    scroll_buffer_x -= mouse_report->x;
#    else
    scroll_buffer_x += mouse_report->x;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_X
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
    scroll_buffer_y -= mouse_report->y;
#    else
    scroll_buffer_y += mouse_report->y;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_Y
    mouse_report->x = 0;
    mouse_report->y = 0;
    if (abs(scroll_buffer_x) > 6) {
        mouse_report->h = scroll_buffer_x > 0 ? 1 : -1;
        scroll_buffer_x = 0;
    }
    if (abs(scroll_buffer_y) > 6) {
        mouse_report->v = scroll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
    }
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    check_drag(&left_report); // updated in trackball.c
    return pointing_device_combine_reports(left_report, right_report);
}
#endif


void pointing_device_init_user(void) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);
    set_auto_mouse_enable(false);
#endif
#ifdef POINTING_DEVICE_COMBINED
    pointing_device_set_cpi_on_side(true, CHARYBDIS_DRAGSCROLL_DPI); // LEFT
    pointing_device_set_cpi_on_side(false, 2000);  // RIGHT
#endif// always required before the auto mouse feature will work
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WYLD_AUTO_MS_TOG:
            if (record->event.pressed) {
                set_auto_mouse_enable(!get_auto_mouse_enable());
            }
            return false; // Skip all further processing of this key
        case WYLD_DPI_UP:
            if (record->event.pressed) {
                increase_dpi();
            }
            return false;
        case WYLD_DPI_DOWN:
            if (record->event.pressed) {
                decrease_dpi();
            }
            return false;
        case WYLD_DPI_RESET:
            if (record->event.pressed) {
                reset_dpi();
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}
#endif



#if defined(ENCODER_MAP_ENABLE)
// TWO ENCODERS
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RAISE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_MOUSE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM querty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 3, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {21, 3, HSV_RED}      // Light 4 LEDs, starting with LED 6
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 3, HSV_BLUE},
    {21, 3, HSV_BLUE}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 3, HSV_YELLOW},
    {21, 3, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 3, HSV_GREEN},
    {21, 3, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    querty_layer,    // Overrides caps lock layer
    lower_layer,    // Overrides other layers
    raise_layer,     // Overrides other layers
    mouse_layer      // Overrides other layers
);

//bool led_update_user(led_t led_state) {
//    rgblight_set_layer_state(0, led_state.caps_lock);
//    return true;
//}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    return state;
}


#endif

//    rgblight_enable();


void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_layers = my_rgb_layers;
//    rgblight_layers = my_rgb_layers;
//    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
//    rgblight_sethsv_noeeprom_cyan();
//    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
#endif

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



#include QMK_KEYBOARD_H
#include "3x5_track.h"

enum layers {
  COLMAK_L = 0,
  NUM_L = 1,
  CHARS_L = 2,
  MOUSE_L = 3,
  QWERTY_L = 4,
};
#define TO_CLM DF(COLMAK_L)
#define TO_NMB DF(NUM_L)
#define TO_CHR DF(CHARS_L)
#define TO_MOS DF(MOUSE_L)
#define TO_QWT DF(QWERTY_L)


#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
}
#endif

#ifdef TAP_DANCE_ENABLE
#define TAP_TAPPING_TERM 220
void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t td0 = { KC_DOT,
                                   KC_QUOT,
                                   KC_COMM,
                                   LSFT(KC_SLSH),
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td1 = { KC_SLASH,
                                   KC_GRV,
                                   LSFT(KC_SLSH),
                                   LSFT(KC_7),
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td2 = { KC_BTN1,
                                   KC_BTN2,
                                   KC_BTN1,
                                   KC_BTN3,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
    dynamic_keymap_set_tap_dance(2, &td2);
}
#endif // TAP_DANCE_ENABLE

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [_COLEMAK] = LAYOUT_3x5( */
/*         KC_Q  ,KC_W  , KC_F  , KC_P  , KC_G  ,                      KC_J  , KC_L  , KC_U  , KC_Y  , KC_SCLN, */
/*         KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                      KC_H  , KC_N  , KC_E  , KC_I  , KC_O, */
/*         KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                      KC_K  , KC_M  ,KC_COMM,KC_DOT , KC_SLSH, */
/*                                       RAISE, KC_SPC,               LOWER, */
/*                                       KC_TAB, KC_HOME,             KC_ENT, */
/*                                       KC_BSPC, KC_GRV,     KC_DEL, KC_LALT */
/*         ), */

/*     [_LOWER] = LAYOUT_3x5( */
/*         _______,_______,_______,_______,KC_LBRC,                     KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS, */
/*         KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                     KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS, */
/*         _______,_______,_______,_______,_______,                     _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL, */
/*                                         _______,_______,             _______, */
/*                                         KC_BTN3,KC_BTN1,             _______, */
/*                                         SNIPING,DRGSCRL,     _______,QK_BOOT */

/*         ), */

/*     [_RAISE] = LAYOUT_3x5( */
/*         KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 , */
/*         _______,_______,_______,_______,KC_LBRC,                     KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK, */
/*         KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                     KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD, */
/*                                         _______,_______,             _______, */
/*                                         _______,_______,             _______, */
/*                                         QK_BOOT,_______,     _______,_______ */
/*         ) */
/* }; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_3x5(
  //,-------------------------------------------------------.    ,---------------------------------------------------------------.
      KC_Q, RALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P), KC_B,         KC_J, LSFT_T(KC_L), LCTL_T(KC_U), RALT_T(KC_Y),       KC_SCLN,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
      KC_A,         KC_R,         KC_S,         KC_T, KC_G,         KC_M,         KC_N,         KC_E,         KC_I,          KC_O,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
      KC_Z,         KC_X,         KC_C,         KC_D, KC_V,         KC_K,         KC_H,      KC_COMM,       KC_DOT, LSFT(KC_SLSH),
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
                                          KC_SPC,     KC_ENT,                   TO_CLM,
                                      // -----------+-------|    |------+-------------|
                                          KC_TAB,     KC_DEL,                  KC_BSPC,
                                      // -----------+-------|    |------+-------------|
                                          TO_NMB,      TD(2),    QK_GESC,      KC_QUOT
                                      // -----------+-------|    |------+-------------|

  ),

  [NUM_L] = LAYOUT_3x5(
  //,--------------------------------------------------------.    ,------------------------------------------------------------------.
      KC_F5, LALT_T(KC_7), LCTL_T(KC_4), LSFT_T(KC_2),  KC_F1,          KC_HOME, LSFT_T(KC_PGDN), LCTL_T(KC_PGUP),    KC_END, MACRO_4,
  //|------+-------------+-------------+-------------+-------|    |------------+----------------+----------------+----------+--------|
      KC_F4,         KC_8,         KC_5,         KC_1,   KC_3,          KC_LEFT,         KC_DOWN,           KC_UP,  KC_RIGHT, KC_LCTL,
  //|------+-------------+-------------+-------------+-------|    |------------+----------------+----------------+----------+--------|
      KC_F3,         KC_9,         KC_6,         KC_0,  KC_F2,          KC_BSLS,         KC_MINS,         KC_ASTR,     TD(0), KC_SLSH,
  //|------+-------------+-------------+-------------+-------|    |------------+----------------+----------------+----------+--------|
                                           KC_SPC,     KC_ENT,                   TO_CLM,
                                       // -----------+-------|    |------+-------------|
                                           KC_TAB,     KC_DEL,                  KC_BSPC,
                                       // -----------+-------|    |------+-------------|
                                           TO_NMB,      TD(2),    QK_GESC,      KC_QUOT
                                       // -----------+-------|    |------+-------------|
  ),

  [CHARS_L] = LAYOUT_3x5(
  //,--------------------------------------------------------.    ,--------------------------------------------------------------------------.
      XXXXXXX, LSFT(KC_7), LSFT(KC_4), LSFT(KC_2),    KC_MUTE,            KC_MPRV,       KC_LSFT,       KC_LCTL,      KC_MNXT,       KC_EQUAL,
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
      MACRO_0, LSFT(KC_8), LSFT(KC_5), LSFT(KC_1), LSFT(KC_3),            KC_LBRC,    LSFT(KC_9),    LSFT(KC_0),      KC_RBRC,   LSFT(KC_GRV),
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
      MACRO_1,     KC_CUT, LSFT(KC_6),    KC_BRIU,    KC_PSTE,     LSFT(KC_COMMA), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_DOT), LSFT(KC_EQUAL),
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
                                           KC_SPC,     KC_ENT,                   TO_CLM,
                                      // -----------+-------|    |------+-------------|
                                          KC_TAB,     KC_DEL,                  KC_BSPC,
                                      // -----------+-------|    |------+-------------|
                                          TO_NMB,      TD(2),    QK_GESC,      KC_QUOT
                                      // -----------+-------|    |------+-------------|
  ),

  [MOUSE_L] = LAYOUT_3x5(
  //,---------------------------------------------.              ,-----------------------------------------------.
      XXXXXXX, KC_BRID,  KC_VOLD, KC_VOLU, KC_BRIU,                   KC_PSCR, KC_WH_D, KC_WH_U,   KC_F6,   KC_F7,
  //|--------+--------+---------+--------+--------|              |-----------+--------+--------+--------+--------|
      MACRO_0, KC_SLCT,  KC_BTN2, KC_BTN1, KC_BTN3,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,   KC_F9,
  //|--------+--------+---------+--------+--------|              |-----------+--------+--------+--------+--------|
      MACRO_1,  KC_CUT,  KC_COPY,  KC_APP, KC_PSTE,                   KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD,  KC_F11,
  //|--------+--------+------------------+--------|              |-----------+--------+--------+--------+--------|
                                          KC_SPC,     KC_ENT,                   TO_CLM,
                                      // -----------+-------|    |------+-------------|
                                          KC_TAB,     KC_DEL,                  KC_BSPC,
                                      // -----------+-------|    |------+-------------|
                                          TO_NMB,      TD(2),    QK_GESC,      KC_QUOT
                                      // -----------+-------|    |------+-------------|
  ),

  [QWERTY_L] = LAYOUT_3x5(
  //,-------------------------------------------------------.    ,-------------------------------------------------------------.
      KC_Q, RALT_T(KC_W), LCTL_T(KC_E), LSFT_T(KC_R),   KC_T,       KC_Y, LSFT_T(KC_U), LCTL_T(KC_I), RALT_T(KC_O),        KC_P,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+------------|
      KC_A,         KC_S,         KC_D,         KC_F,   KC_G,       KC_H,         KC_J,         KC_K,         KC_L,     KC_SCLN,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+------------|
      KC_Z,         KC_X,         KC_C,         KC_V,   KC_B,       KC_N,         KC_M,      KC_COMM,       KC_DOT,     KC_LBRC,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+------------|
                                          KC_SPC,     KC_ENT,                   TO_CLM,
                                      // -----------+-------|    |------+-------------|
                                          KC_TAB,     KC_DEL,                  KC_BSPC,
                                      // -----------+-------|    |------+-------------|
                                          TO_NMB,      TD(2),    QK_GESC,      KC_QUOT
                                      // -----------+-------|    |------+-------------|
  )
};

#include QMK_KEYBOARD_H
#include "3x5_track.h"

enum layers {
  COLMAK_L = 0,
  NUM_L = 1,
  CHARS_L = 2,
  MOUSE_L = 3,
  GAME_L = 4,
};
#define TO_CLM DF(COLMAK_L)
#define TO_NMB DF(NUM_L)
#define TO_CHR DF(CHARS_L)
#define TO_MOS DF(MOUSE_L)
#define TO_GAM DF(GAME_L)


#ifdef TAP_DANCE_ENABLE
#define TAP_TAPPING_TERM 220
void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
#endif // CONSOLE_ENABLE
    vial_tap_dance_entry_t td0 = { TO_CLM,
                                   TO_CHR,
                                   TO_NMB,
                                   TO_MOS,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td1 = { KC_DOT,
                                   KC_QUOT,
                                   KC_COMM,
                                   LSFT(KC_SLSH),
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td2 = { KC_BTN1,
                                   KC_BTN3,
                                   KC_BTN2,
                                   KC_BTN4,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td3 = { KC_QUOT,
                                   KC_LBRC,
                                   KC_SLSH,
                                   KC_RBRC,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
    dynamic_keymap_set_tap_dance(2, &td2);
    dynamic_keymap_set_tap_dance(3, &td3);
}
#endif // TAP_DANCE_ENABLE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_3x5(
  //,-------------------------------------------------------.    ,---------------------------------------------------------------.
      KC_Q, RALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P), KC_B,         KC_E, LSFT_T(KC_O), LCTL_T(KC_U), RALT_T(KC_Y),       KC_SCLN,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
      KC_A,         KC_R,         KC_S,         KC_T, KC_G,         KC_M,         KC_H,         KC_J,         KC_K,          KC_L,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
      KC_Z,         KC_X,         KC_C,         KC_D, KC_V,         KC_I,         KC_N,      KC_COMM,       KC_DOT,       KC_SLSH,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
                                             KC_LGUI, KC_SPC,                   KC_ENT,
                                      // -----------+-------|    |------+-------------|
                                             KC_CAPS,  TD(0),                   KC_TAB,
                                      // -----------+-------|    |------+-------------|
                                              KC_DEL,QK_GESC,       TD(3),     KC_BSPC
                                      // -----------+-------|    |------+-------------|
  ),

  [NUM_L] = LAYOUT_3x5(
  //,---------------------------------------------------------.    ,------------------------------------------------------------------------.
      KC_F5, LALT_T(KC_7), LCTL_T(KC_4), LSFT_T(KC_2), KC_MINS,           KC_HOME,  LSFT_T(KC_END), LCTL_T(KC_PGDN),RALT_T(KC_PGUP), XXXXXXX,
  //|------+-------------+-------------+-------------+--------|    |-------------+----------------+----------------+---------------+--------|
      KC_F4,        KC_8 ,        KC_5 ,        KC_1 ,    KC_3,             TD(1),         KC_LEFT,         KC_DOWN,          KC_UP,KC_RIGHT,
  //|------+-------------+-------------+-------------+--------|    |-------------+----------------+----------------+---------------+--------|
      KC_F3,        KC_9 ,        KC_6 ,        KC_0 ,   KC_F2,           KC_BTN4,         KC_BTN1,         KC_BTN2,        KC_BTN3, KC_BSLS,
  //|------+-------------+-------------+-------------+--------|    |-------------+----------------+----------------+---------------+--------|
                                              KC_LGUI,  KC_SPC,                             KC_ENT,
                                       // -----------+-- -----|    |-------------+----------------|
                                                KC_F1,   TD(0),                             KC_TAB,
                                       // -----------+--------|    |-------------+----------------|
                                               KC_DEL, QK_GESC,             TD(3),         KC_BSPC
                                       // -----------+--------|    |-------------+----------------|
  ),

  [CHARS_L] = LAYOUT_3x5(
  //,--------------------------------------------------------.    ,--------------------------------------------------------------------------.
        KC_F7, LSFT(KC_7), LSFT(KC_4), LSFT(KC_2),      KC_F8,             KC_EQL, LSFT(KC_BSLS),        KC_GRV, LSFT(KC_GRV),  LSFT(KC_SCLN),
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
      XXXXXXX, LSFT(KC_8), LSFT(KC_5), LSFT(KC_1), LSFT(KC_3),         KC_KB_MUTE,       KC_LBRC,    LSFT(KC_9),   LSFT(KC_0),        KC_RBRC,
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
      XXXXXXX,     KC_CUT, LSFT(KC_6),     KC_APP,    KC_PSTE,       LSFT(KC_EQL), LSFT(KC_LBRC),LSFT(KC_COMMA), LSFT(KC_DOT),  LSFT(KC_RBRC),
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
                                          KC_LGUI,     KC_SPC,                            KC_ENT,
                                   // -----------+-----------|    |--------------+--------------|
                                          KC_LALT,      TD(0),                            KC_TAB,
                                   // -----------+-----------|    |--------------+--------------|
                                          KC_LCTL,    QK_GESC,              TD(3),       KC_BSPC
                                   // -----------+-----------|    |--------------+--------------|
  ),

  [MOUSE_L] = LAYOUT_3x5(
  //,---------------------------------------------.    ,--------------------------------------------.
      KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_F9,       KC_F10,  KC_F11, KC_WH_D, KC_WH_U, KC_PSCR,
  //|--------+--------+---------+--------+--------|    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN4,  KC_BTN2, KC_BTN1, KC_BTN3,       KC_F12, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
  //|--------+--------+---------+--------+--------|    |--------+--------+--------+--------+--------|
      XXXXXXX,  KC_CUT,  KC_COPY,  KC_APP, KC_PSTE,       KC_INS, KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD,
  //|--------+--------+------------------+--------|    |--------+--------+--------+--------+--------|
                                  KC_LGUI,  KC_SPC,                             KC_ENT,
                           // -----------+--------|    |-------------+----------------|
                                    TD(4),   TD(0),                             KC_TAB,
                           // -----------+--------|    |-------------+----------------|
                                  QK_BOOT, QK_GESC,           QK_BOOT,         KC_BSPC
                           // -----------+--------|    |-------------+----------------|
  )
};

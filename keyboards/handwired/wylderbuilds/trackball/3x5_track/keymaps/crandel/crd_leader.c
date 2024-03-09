void umlauts(uint8_t code){
    tap_code(KC_PSCR);
    tap_code16(S(KC_QUOT));
    tap_code(code);
}

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_C)) {
    shifted_letters(KC_C);
    return;
  }
  if (leader_sequence_one_key(KC_V)) {
    shifted_letters(KC_V);
    return;
  }
  if (leader_sequence_one_key(KC_A)) {
    umlauts(KC_A);
    return;
  }
  if (leader_sequence_one_key(KC_E)) {
    umlauts(KC_E);
    return;
  }
  if (leader_sequence_one_key(KC_O)) {
    umlauts(KC_O);
    return;
  }
  if (leader_sequence_one_key(KC_S)) {
    tap_code(KC_PSCR);
    tap_code(KC_S);
    tap_code(KC_S);
    return;
  }
  if (leader_sequence_one_key(KC_U)) {
    umlauts(KC_U);
    return;
  }
  if (leader_sequence_one_key(KC_Q)) {
    tap_code(KC_SCLN);
    tap_code(KC_W);
    tap_code(KC_Q);
    return;
  }
  if (leader_sequence_one_key(KC_SCLN)) {
    tap_code16(A(KC_X));
    return;
  }
  if (leader_sequence_one_key(SLS_TD)) {
    tap_code16(S(KC_7));
    return;
  }
  if (leader_sequence_two_keys(KC_T, KC_T)) {
    tap_code16(A(KC_X));
    return;
  }
  if (leader_sequence_two_keys(KC_T, KC_S)) {
    tap_code16(S(KC_7));
    return;
  }
}

#include QMK_KEYBOARD_H

enum custom_keycodes {
    _BASE,
    _SHIFT,
    _NUM,
    _SYMB,
    _FCT,
    _NAV,
    _MEDIA,
    _GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Converted with : https://jhelvy.shinyapps.io/qmkjsonconverter/
    [_BASE]  = LAYOUT(KC_NO, KC_W, KC_M, KC_D, KC_Y, KC_LPRN, KC_RPRN, KC_J, KC_C, KC_P, KC_K, KC_NO, KC_NO, LGUI_T(KC_U), LALT_T(KC_A), LCTL_T(KC_I), LT(1,KC_E), KC_DOT, KC_COMM, LT(1,KC_S), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_R), KC_NO, KC_NO, KC_H, RALT_T(KC_V), KC_Q, LSFT_T(KC_O), KC_Z, KC_X, LSFT_T(KC_L), KC_B, RALT_T(KC_G), KC_F, KC_NO, KC_NO, KC_NO, KC_NO, LT(4,KC_ESC), LT(3,KC_SPC), LT(2,KC_TAB), LT(5,KC_ENT), LT(6,KC_BSPC), LT(7,KC_DEL), KC_NO, KC_NO, KC_NO),
    [_SHIFT] = LAYOUT(KC_NO, LSFT(KC_W), LSFT(KC_M), LSFT(KC_D), LSFT(KC_Y), KC_QUOT, LSFT(KC_QUOT), LSFT(KC_J), LSFT(KC_C), LSFT(KC_P), LSFT(KC_K), KC_NO, KC_NO, LSFT(KC_U), LSFT(KC_A), LSFT(KC_I), LSFT(KC_E), LSFT(KC_SCLN), KC_SCLN, LSFT(KC_S), LSFT(KC_T), LSFT(KC_N), LSFT(KC_R), KC_NO, KC_NO, LSFT(KC_H), LSFT(KC_V), LSFT(KC_Q), LSFT(KC_O), LSFT(KC_Z), LSFT(KC_X), LSFT(KC_L), LSFT(KC_B), LSFT(KC_G), LSFT(KC_F), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO),
    [_NUM]   = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_BSPC, KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_PPLS, KC_4, KC_5, KC_6, KC_PAST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PMNS, KC_1, KC_2, KC_3, KC_PSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_ENT, KC_P0, KC_NO, KC_NO, KC_NO, KC_NO),
    [_SYMB]  = LAYOUT(KC_NO, KC_EXLM, KC_QUES, KC_GRV, KC_CIRC, KC_ASTR, KC_DLR, KC_HASH, KC_PERC, KC_TILD, KC_AT, KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_LCBR, KC_RCBR, KC_AMPR, LSFT(KC_EQL), KC_EQL, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LT, KC_GT, KC_PIPE, KC_MINS, LSFT(KC_MINS), KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [_FCT]   = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [_NAV]   = LAYOUT(KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, LGUI(KC_HOME), LGUI(KC_UP), LGUI(KC_END), LGUI(KC_PGUP), KC_NO, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RGHT), LGUI(KC_PGDN), KC_NO, KC_NO, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [_MEDIA] = LAYOUT(KC_NO, KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_PAUS, LGUI(KC_L), KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_U), LCTL(KC_V), LCTL(KC_U), KC_NO, KC_NO, LGUI(KC_PAUS), KC_NO, KC_SLEP, KC_NO, KC_NO, CG_SWAP, KC_NO, LGUI(KC_D), LGUI(KC_E), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
    [_GAME]  = LAYOUT(KC_NO, KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_LSFT, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_0, KC_NO, KC_NO, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_TAB, KC_SPC, TO(0), TO(0), KC_NO, KC_NO, KC_NO, KC_NO) 

    /*  |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    // [_BASE] = LAYOUT (
    //     KC_NO,        KC_W,         KC_M,         KC_D,         KC_Y,         KC_LPRN,      KC_RPRN,      KC_J,         KC_C,         KC_P,         KC_K,         KC_NO,
    //     KC_NO,        LGUI_T(KC_U), LALT_T(KC_A), LCTL_T(KC_I), LT(1,KC_E),   KC_DOT,       KC_COMM,      LT(1,KC_S),   LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_R), KC_NO,
    //     KC_NO,        KC_H,         RALT_T(KC_V), KC_Q,         LSFT_T(KC_O), KC_Z,         KC_X,         LSFT_T(KC_L), KC_B,         RALT_T(KC_G), KC_F,         KC_NO,
    //     KC_NO,        KC_NO,        KC_NO,        LT(4,KC_ESC), LT(3,KC_SPC), LT(2,KC_TAB), LT(5,KC_ENT), LT(6,KC_BSPC),LT(7,KC_DEL), KC_NO,        KC_NO,        KC_NO,
    // ),

    /*  |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    // [_SHIFT] = LAYOUT (
    //     KC_NO,        LSFT(KC_W),   LSFT(KC_M),   LSFT(KC_D),   LSFT(KC_Y),   KC_QUOT,      LSFT(KC_QUOT),LSFT(KC_J),   LSFT(KC_C),   LSFT(KC_P),   LSFT(KC_K),   KC_NO,
    //     KC_NO,        LSFT(KC_U),   LSFT(KC_A),   LSFT(KC_I),   LSFT(KC_E),   LSFT(KC_SCLN),KC_SCLN,      LSFT(KC_S),   LSFT(KC_T),   LSFT(KC_N),   LSFT(KC_R),   KC_NO,
    //     KC_NO,        LSFT(KC_H),   LSFT(KC_V),   LSFT(KC_Q),   LSFT(KC_O),   LSFT(KC_Z),   LSFT(KC_X),   LSFT(KC_L),   LSFT(KC_B),   LSFT(KC_G),   LSFT(KC_F),   KC_NO,
    //     KC_NO,        KC_NO,        KC_NO,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_NO,        KC_NO,        KC_NO,
    // ),
};

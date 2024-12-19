/* -------------------------------
   tapotin, main keymap definition 
   ------------------------------- */

#include QMK_KEYBOARD_H

/* Timer for Keyboard jiggler function (ping every minute) */
#define IDLE_TIMEOUT_MS 60000

#define MY_REDO C(KC_Y) // Issue with MacOS
#define MY_PSTE C(KC_V)
#define MY_COPY C(KC_C)
#define MY_CUT  C(KC_X)
#define MY_UNDO C(KC_Z)

/* Layer list */
enum keyboard_layers {
    _BASE,
    _NUM,
    _SYMB,
    _FCT,
    _NAV,
    _ACC,
    _GAME,
    _QWERTY
};

/* Custom keycode for accents and jiggler function */
enum custom_keycodes { 
    MY_OS = SAFE_RANGE,
    MY_LOCK,
    MY_LSCR,
    MY_RSCR,
    ACC_EE,
    ACC_EG,
    ACC_EC,
    ACC_CC,
    ACC_UG,
    ACC_AG
};

/* Support multiples OS, Linux=0 (default), MacOS=1, Windows=2 */
enum os_type {
    LINUX,
    MACOS,
    WINDOWS
};
static uint8_t os_selector = 0;

/* Keys override definition, beacause a shifted key can be splitted on differnts keys on my layout, e.g.
 *   Shift . => :
 *   Shift , => ;
 */
const key_override_t central_remap_1 = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_QUOT); // KC_QUOT
const key_override_t central_remap_2 = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_DQUO); // LSFT(KC_QUOT)
const key_override_t central_remap_3 = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_COLN); // LSFT(KC_SCLN)
const key_override_t central_remap_4 = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN); // KC_SCLN

const key_override_t *key_overrides[] = {
    &central_remap_1,
    &central_remap_2,
    &central_remap_3,
    &central_remap_4
};

/* Combos definition 
 * Caps-lock, Caps-lock toggle & custom message 
 */
enum combo_events {
  CAPS, BOOT, MSG1, MSG2, MSG3
};
const uint16_t PROGMEM c_caps[]  = {KC_LSFT, KC_RSFT, COMBO_END};             // = Double Side Shift
const uint16_t PROGMEM c_boot[]  = {KC_LALT, KC_W, KC_K, KC_GRV, COMBO_END};  // = 2x 2x Lat Top
const uint16_t PROGMEM c_msg1[]  = {KC_Y, KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM c_msg2[]  = {KC_Y, KC_LPRN, KC_J, COMBO_END};
const uint16_t PROGMEM c_msg3[]  = {KC_Y, KC_LPRN, KC_C, COMBO_END};
combo_t key_combos[] = {
  [CAPS]  = COMBO(c_caps, KC_CAPS),
  [BOOT]  = COMBO(c_boot, QK_BOOT),
  [MSG1]  = COMBO_ACTION(c_msg1),
  [MSG2]  = COMBO_ACTION(c_msg2),
  [MSG3]  = COMBO_ACTION(c_msg3)
};

// TODO @ et ~


/* Keyboard mapping definion -- Software layout used in addition 
 * https://docs.qmk.fm/keycodes
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  Default Layer (Custom Dvorak)
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_BASE] = LAYOUT (
        KC_LALT,      KC_W,         KC_M,         KC_D,         KC_Y,         KC_LPRN,      KC_RPRN,      KC_J,          KC_C,        KC_P,         KC_K,         KC_GRV, 
        KC_LSFT,      KC_U,         KC_A,         KC_I,         KC_E,         KC_DOT,       KC_COMM,      KC_S,          KC_T,        KC_N,         KC_R,         KC_RSFT, 
        KC_LCTL,      KC_H,         KC_V,         KC_Q,         KC_O,         KC_Z,         KC_X,         KC_L,          KC_B,        KC_G,         KC_F,         KC_LGUI,
                                          LT(_FCT,KC_ESC),LT(_SYMB,KC_TAB),LT(_NUM,KC_SPC), LT(_NAV,KC_ENT),LT(_ACC,KC_BSPC),KC_DEL                                              ),

    /*  NumPad Layer / Left shortcut, Right mapping
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_NUM] = LAYOUT (
        XXXXXXX,      MY_UNDO,      MY_CUT,       MY_COPY,      MY_PSTE,      MY_REDO,      LSFT(KC_LBRC),KC_7,         KC_8,         KC_9,         LSFT(KC_RBRC),XXXXXXX,
        XXXXXXX,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,      KC_LBRC,      KC_4,         KC_5,         KC_6,         KC_RBRC,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      LSFT(KC_COMM),KC_1,         KC_2,         KC_3,         LSFT(KC_DOT), XXXXXXX,
                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_ENT,       KC_0,         KC_BSPC                                                  ),
    /*                                                                        ==^^^==                                                                                             */

    /*  Symbols Layer / Left shortcut, Right mapping
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_SYMB] = LAYOUT (
        XXXXXXX,      MY_UNDO,      MY_CUT,       MY_COPY,      MY_PSTE,      MY_REDO,      KC_EXLM,      KC_QUES,      KC_GRV,       KC_CIRC,      XXXXXXX,      KC_AT,
        XXXXXXX,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,      KC_ASTR,      KC_DLR,       KC_HASH,      KC_PERC,      KC_AMPR,      KC_SLSH,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_PLUS,      KC_MINS,      KC_EQL,       KC_UNDS,      KC_PIPE,      KC_BSLS,
                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX                                                  ),
    /*                                                          ==^^^==                                                                                                           */

    /*  Functions Layer / Left shortcut, Right mapping
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_FCT] = LAYOUT (
        MY_LSCR,      MY_UNDO,      MY_CUT,       MY_COPY,      MY_PSTE,      MY_REDO,      KC_PSCR,      KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_CALC,
        MY_RSCR,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,      KC_SCRL,      KC_F4,        KC_F5,        KC_F6,        KC_F11,       XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_PAUS,      KC_F1,        KC_F2,        KC_F3,        KC_F12,       MY_OS,
                                                  XXXXXXX,      XXXXXXX,      XXXXXXX,      MY_LOCK,      TO(_QWERTY),  TO(_GAME)                                                ),
    /*                                            ==^^^==                                                                                                                         */

    /*  Navigation + Media Layer / Right shortcut, Left mapping
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_NAV] = LAYOUT (
        XXXXXXX,      KC_PGUP,      KC_HOME,      KC_UP,        KC_END,       KC_INS,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX, 
        XXXXXXX,      KC_PGDN,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_CAPS,      XXXXXXX,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      KC_VOLD,      KC_VOLU,      KC_MPLY,      KC_MUTE,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                                  KC_ESC,       KC_TAB,       KC_SPC,       XXXXXXX,      XXXXXXX,      XXXXXXX                                                  ),
    /*                                                                                      ==^^^==                                                                               */

    /*  Accents Layer / Right shortcut, Left mapping
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_ACC] = LAYOUT (
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      ACC_EE,       XXXXXXX,      XXXXXXX,      XXXXXXX,      ACC_CC,       XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      ACC_UG,       ACC_AG,       XXXXXXX,      ACC_EG,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      ACC_EC,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                                  RALT(KC_QUOT),RALT(KC_GRV), XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX                                                  ),
    /*                                                                                                    ==^^^==                                                                 */

    /*  Gaming Layer (using Turn-On layer, excape on top-right corner)
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_GAME] = LAYOUT (
        KC_ESC,       KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         TO(_BASE),
        KC_LSFT,      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_HOME,      KC_UP,        KC_END,       KC_PGUP,      KC_RSFT,
        KC_LCTL,      KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_PGDN,      KC_CAPS,
                                                  KC_TAB,       KC_LALT,      KC_SPC,       KC_ENT,       KC_BSPC,      KC_DEL                                                   ),

    /*  Qwerty Layer (using Turn-On layer, excape on top-right corner)
        |-1-----------|-2-----------|-3-----------|-4-----------|-5-----------|-6----------||-7-----------|-8-----------|-9-----------|-10----------|-11----------|-12----------| */
    [_QWERTY] = LAYOUT (
        KC_LALT,      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         TO(_BASE),
        KC_LSFT,      KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_QUOT,      KC_RSFT,
        KC_LCTL,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_LGUI,
                                                  KC_ESC,       KC_TAB,       KC_SPC,       KC_ENT,       KC_BSPC,      KC_DEL                                                   ),
};


/* Keyboard Jiggler callback (Similar to a mouse jiggler) */
static uint32_t idle_callback(uint32_t trigger_time, void* cb_arg) {
    //tap_code(KC_BRIGHTNESS_UP);
    //tap_code(KC_BRIGHTNESS_DOWN);
    tap_code(QK_MOUSE_BUTTON_8);
    return IDLE_TIMEOUT_MS;
}


/* Keyboard custom init function */
void matrix_init_user(void) {
    /* Register a keyboard jiggler function
     * Doc: https://docs.qmk.fm/custom_quantum_functions#deferred-execution
     */
    static deferred_token idle_token = INVALID_DEFERRED_TOKEN;

    if (!extend_deferred_exec(idle_token, IDLE_TIMEOUT_MS)) {
        idle_token = defer_exec(IDLE_TIMEOUT_MS, idle_callback, NULL);
    }
}


/* Swap CTRL & GUI for Linux/MacOS convensions *
 * https://docs.qmk.fm/keycodes#magic-keycodes */
void update_key_swap(bool state) {
    keymap_config.raw = eeconfig_read_keymap();
    keymap_config.swap_lctl_lgui = state;
    eeconfig_update_keymap(keymap_config.raw);
    clear_keyboard(); // clear to prevent stuck keys
}


/* https://docs.qmk.fm/features/os_detection */
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_UNSURE:
        case OS_LINUX:
            os_selector = 0;
            update_key_swap(false);
            break;
        case OS_MACOS:
        case OS_IOS:
            os_selector = 1;
            update_key_swap(true);
            break;
        case OS_WINDOWS:
            os_selector = 2;
            update_key_swap(false);
            break;
    }
    return true;
}


/* Custom event management, documentation: 
 *   https://docs.qmk.fm/custom_quantum_functions
 *   https://docs.qmk.fm/feature_layers
 *   https://docs.qmk.fm/feature_macros
 *   https://docs.qmk.fm/feature_advanced_keycodes
 *
 * Note: Using US Intl. layout for accents, but key positions are not the same on differents OS...
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_OS:
            if (record->event.pressed) {
                /* Move to the next OS (no LED notification for now) */
                os_selector++;
                if (os_selector > 2) { 
                    os_selector = 0; 
                }

                switch (os_selector) {
                    case MACOS:
                        update_key_swap(true);  // Swap Left Control and GUI
                        SEND_STRING("Control / Command swapped");
                        break;
                    default:
                        update_key_swap(false); // Unswap Left Control and GUI
                        SEND_STRING("Control / Command regular position");
                        break;
                }
            }
            return false;

        case MY_LSCR:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                        tap_code16(LGUI(KC_PGUP));
                        break;
                    case MACOS:
                        tap_code16(LGUI(KC_LEFT));
                        break;
                    case WINDOWS:
                        tap_code16(LALT(KC_TAB));
                        break;
                    default:
                        break;
                }
            }
            return false;

        case MY_RSCR:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                        tap_code16(LGUI(KC_PGDN));
                        break;
                    case MACOS:
                        tap_code16(LGUI(KC_RGHT));
                        break;
                    case WINDOWS:
                        tap_code16(LSA(KC_TAB));
                        break;
                    default:
                        break;
                }
            }
            return false;

        case MY_LOCK:
            if (record->event.pressed) {
                switch (os_selector) {
                    case MACOS:
                        tap_code16(LCTL(LGUI(KC_Q)));  // CTRL-GUI-Q
                        break;
                    case LINUX:
                    case WINDOWS:
                        tap_code16(LGUI(KC_L));  // GUI-L 
                        break;
                    default:
                        break;
                }
            }
            return false;

        /* é (US-Alt. layout) */
        case ACC_EE:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                    case WINDOWS:    
                        tap_code16(RALT(KC_QUOT));
                        tap_code16(KC_E);
                        break;
                    case MACOS:
                        tap_code16(RALT(KC_E));
                        tap_code16(KC_E);
                        break;
                    default:
                        break;
                }
            }
            return false;

        /* è (US-Alt. layout) */
        case ACC_EG:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                    case MACOS:
                    case WINDOWS:
                        tap_code16(RALT(KC_GRV));
                        tap_code16(KC_E);
                        break;
                    default:
                        break;
                }
            }
            return false;

        /* ê (US-Alt. layout) */
        case ACC_EC:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                    case WINDOWS:
                        tap_code16(RALT(KC_6));
                        tap_code16(KC_E);
                        break;
                    case MACOS:
                        tap_code16(RALT(KC_I));
                        tap_code16(KC_E);
                        break;
                    default:
                        break;
                }
            }
            return false;

        /* ç (US-Alt. layout) */
        case ACC_CC:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                    case WINDOWS:
                        tap_code16(RALT(KC_COMM));
                        break;
                    case MACOS:
                        tap_code16(RALT(KC_C));
                        break;
                    default:
                        break;
                }
            }
            return false;

        /* ù (US-Alt. layout) */
        case ACC_UG:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                    case MACOS:
                    case WINDOWS:
                        tap_code16(RALT(KC_GRV));
                        tap_code16(KC_U);
                        break;
                    default:
                        break;
                }
            }
            return false;

        /* à (US-Alt. layout) */
        case ACC_AG:
            if (record->event.pressed) {
                switch (os_selector) {
                    case LINUX:
                    case MACOS:
                    case WINDOWS:
                        tap_code16(RALT(KC_GRV));
                        tap_code16(KC_A);
                        break;
                    default:
                        break;
                }
            }
            return false;
        }
    return true;
}


/* Combo Action definitions for custom message blocs */
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case MSG1:
            if (pressed) {
                SEND_STRING("Custom text bloc 1\n");
            }
            break;
        case MSG2:
            if (pressed) {
                SEND_STRING("Custom text bloc 2");
            }
            break;
        case MSG3:
            if (pressed) {
                SEND_STRING("Custom text bloc 3");
            }
            break;
    }
}
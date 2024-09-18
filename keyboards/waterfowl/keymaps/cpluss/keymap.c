#include QMK_KEYBOARD_H

// SWEDISH LETTERS AND SYMBOLS
// Letters
#define KC_SE_AA KC_LBRC             // Å
#define KC_SE_AE KC_QUOT             // Ä
#define KC_SE_OE KC_SCLN             // Ö
#define KC_SE_QUO KC_BSLS            // '
#define KC_SE_COL S(KC_DOT)          // :
#define KC_SE_SEMI S(KC_COMM)        // ;
#define KC_SE_EXCL S(KC_1)           // !
#define KC_SE_DQUO S(KC_2)           // "
#define KC_SE_HASH S(KC_3)           // #
#define KC_SE_PERC S(KC_5)           // %
#define KC_SE_AMPR S(KC_6)           // &
#define KC_SE_SLSH S(KC_7)           // /
#define KC_SE_LPRN S(KC_8)           // (
#define KC_SE_RPRN S(KC_9)           // )
#define KC_SE_EQAL S(KC_0)           // =
#define KC_SE_CIRC S(KC_RBRC)        // ^
#define KC_SE_AT RALT(KC_2)          // @
#define KC_SE_DLR RALT(KC_4)         // $
#define KC_SE_LCBR S(RALT(KC_8))     // {
#define KC_SE_LBRC RALT(KC_8)        // [
#define KC_SE_RBRC RALT(KC_9)        // ]
#define KC_SE_RCBR S(RALT(KC_9))     // }
#define KC_SE_TILD RALT(KC_RBRC)     // ~
#define KC_SE_DIAE KC_RBRC           // ¨
#define KC_SE_ACUT KC_EQL            // ´
#define KC_SE_MINS KC_SLASH          // -
#define KC_SE_GRAV KC_PLUS           // `
#define KC_SE_LESS KC_GRV      // <
#define KC_SE_MORE S(KC_GRV)         // >
#define KC_SE_PLUS KC_MINS           // +
#define KC_SE_ASTR S(KC_BSLS)        // *
#define KC_SE_QUES S(KC_MINS)        // ?
#define KC_SE_BSLH S(RALT(KC_7))     /* \ */
#define KC_SE_PIPE RALT(KC_7)        // |
#define KC_SE_USC S(KC_SLASH)       // _

// Shorthands in order to reduce the space these
// takes up in the layout below.
#define M_SWU KC_MS_WH_UP
#define M_SWD KC_MS_WH_DOWN
#define M_SWL KC_MS_WH_LEFT
#define M_SWR KC_MS_WH_RIGHT
#define M_RHT KC_MS_BTN2
#define M_LFT KC_MS_BTN1
#define M_MDL KC_MS_BTN3

enum layer_names {
    _SVORAK,
    _SYMBOLS,
    _FNUM,
};

num keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Default layer
    [_SVORAK] = LAYOUT( \
      KC_SE_AA, KC_SE_AE, KC_SE_OE, KC_P, KC_Y,  /*|*/  KC_F, KC_G, KC_C, KC_R, KC_L, \
      KC_A,     KC_O,     KC_E,     KC_U, KC_I,  /*|*/  KC_D, KC_H, KC_T, KC_N, KC_S, \
      KC_DOT,   KC_Q,     KC_J,     KC_K, KC_X,  /*|*/  KC_B, KC_M, KC_W, KC_V, KC_Z, \
      /*R*/                               /*R*/        /*R*/                                 /*R*/
      KC_NO, KC_ESC, KC_LSFT, MO(_FNUM), KC_NO, /*|*/  KC_NO, KC_ENT, KC_SPC, MO(_SYMBOLS), KC_NO \
    ),
    [_SYMBOLS] = LAYOUT( \
      KC_SE_LCBR, KC_SE_RCBR, KC_SE_LBRC, KC_SE_RBRC, KC_SE_DLR,  /*|*/ KC_SE_PLUS, KC_SE_QUES, KC_SE_AMPR, KC_SE_LESS, KC_SE_MORE, \
      KC_SE_SEMI, KC_SE_SLSH, KC_SE_LPRN, KC_SE_RPRN, KC_SE_PIPE, /*|*/ KC_COMM,    KC_SE_CIRC, KC_SE_HASH, KC_SE_DQUO, KC_SE_TILD, \
      KC_SE_COL,  KC_SE_EQAL, KC_SE_AT,   KC_SE_EXCL, KC_SE_BSLH, /*|*/ KC_SE_PERC, KC_SE_ACUT, KC_SE_QUO,  KC_SE_ASTR, KC_SE_USC, \
      /*R*/                                    /*R*/        /*R*/                         /*R*/
      KC_NO, KC_SE_USC, KC_SE_MINS, KC_SE_USC, KC_NO, /*|*/ KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO \
    ),
    [_FNUM] = LAYOUT( \
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  /*|*/ KC_6,    KC_7,    KC_8,  KC_9,    KC_0, \
      OS_CMD, OS_ALT, OS_SHFT, OS_CTRL, M_MDL, /*|*/ KC_NO,   KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,\
      KC_NO,   M_SWU,   M_SWD,   M_RHT,   M_LFT, /*|*/ KC_BSPC, KC_DEL,  M_SWU, M_SWD,   M_SWR,\
      /*R*/                        /*R*/        /*R*/                         /*R*/
      KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, /*|*/ KC_NO, KC_COPY, KC_TAB, KC_0, KC_NO \
    ),
};

/*bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}*/

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}å

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;å
}

#ifdef OLED_ENABLE

void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _SVORAK:
            oled_write_ln_P(PSTR("SVORAK"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("SYMBOLS"), false);
            break;
        case _FNUM:
            oled_write_ln_P(PSTR("FNUM"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNKNOWN"), false);
    }
}

// init hook
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    } else {
        return OLED_ROTATION_270;
    }
}

// actual rendering loop
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_layer_state();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 3) { // Right encoder
        if (clockwise) {
            tap_code(KC_MPRV);
        } else {
            tap_code(KC_MNXT);
        }
    }

    return false;
}
#endif

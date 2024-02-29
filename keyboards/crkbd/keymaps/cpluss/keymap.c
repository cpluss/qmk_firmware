/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum macro_keycodes {
    KC_SAMPLEMACRO,
};

// This is the default layer and where
// all the character keys should be - and
// the gateway to the others.
#define _SVORAK 0
// Symbol layer based on the svorak A5 layout
#define _SYMBOLS 1
// Function and numbers layer
#define _FNUM 2
// Special to access gaming keys in a qwerty
// layout, because that is essentially what
// most games default to today ..
#define _GAMING 3

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

// Tap dance for SHIFT -> TAB
#define TD_CTL_TAB 0

tap_dance_action_t tap_dance_actions[] = {
    [TD_CTL_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_TAB)
};

const uint16_t PROGMEM combo_gaming[] = {KC_RSFT, KC_SE_MINS, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_gaming, TG(_GAMING))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Default layer
    [_SVORAK] = LAYOUT_split_3x6_3( \
      KC_ESC,          KC_SE_AA, KC_SE_AE, KC_SE_OE, KC_P, KC_Y,  /* | */  KC_F, KC_G, KC_C, KC_R, KC_L, KC_COMM, \
      TD (TD_CTL_TAB), KC_A,     KC_O,     KC_E,     KC_U, KC_I,  /* | */  KC_D, KC_H, KC_T, KC_N, KC_S, KC_SE_MINS,\
      KC_RSFT,         KC_DOT,   KC_Q,     KC_J,     KC_K, KC_X,  /* | */  KC_B, KC_M, KC_W, KC_V, KC_Z, KC_LALT, \

                                    KC_LGUI, KC_BSPC, MO(_FNUM), /* | */  KC_ENT, KC_SPC,  MO(_SYMBOLS) \
    ),
    [_SYMBOLS] = LAYOUT_split_3x6_3( \
      KC_NO, KC_SE_LCBR, KC_SE_RCBR, KC_SE_LBRC, KC_SE_RBRC, KC_SE_DLR,   /*|*/   KC_NO,      KC_SE_QUES, KC_SE_AMPR, KC_SE_LESS, KC_SE_MORE, KC_SE_PLUS, \
      KC_NO, KC_SE_SEMI, KC_SE_SLSH, KC_SE_LPRN, KC_SE_RPRN, KC_SE_PIPE,  /*|*/   KC_COMM,    KC_SE_CIRC, KC_SE_HASH, KC_SE_DQUO, KC_SE_TILD, KC_NO, \
      KC_NO, KC_SE_COL,  KC_SE_EQAL, KC_SE_AT,   KC_SE_EXCL, KC_SE_BSLH,  /*|*/   KC_SE_PERC, KC_SE_ACUT, KC_SE_QUO,  KC_SE_ASTR, KC_SE_GRAV, KC_NO, \

                                                   KC_NO, KC_NO, KC_NO,  /* | */  KC_NO, KC_NO, KC_TRNS \
    ),
    [_FNUM] = LAYOUT_split_3x6_3( \
      KC_NO, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,              /* | */ KC_6,    KC_7,    KC_8,  KC_9,    KC_0,     KC_NO, \
      KC_NO, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_NO,           /* | */ KC_NO,   KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_NO, \
      KC_NO, KC_NO,   KC_MS_WH_UP,   KC_MS_WH_DOWN,   KC_MS_BTN2, KC_MS_BTN1,   /* | */ KC_NO, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT,   KC_NO, \

                       KC_NO, KC_NO, KC_TRNS, /* | */   KC_COPY, KC_PSTE, KC_0 \
    ),
    [_GAMING] = LAYOUT_split_3x6_3( \
      KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,  /* | */  KC_Y, KC_U, KC_I,  KC_O,  KC_P,  KC_BSPC, \
      KC_RSFT, KC_A, KC_S, KC_D, KC_F, KC_G,  /* | */  KC_H, KC_J, KC_K,  KC_L,  KC_NO, KC_SE_MINS,\
      KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,  /* | */  KC_N, KC_M, KC_NO, KC_NO, KC_NO, KC_LALT, \
                              KC_TAB, KC_SPC, MO(_FNUM), /* | */  KC_ENT, KC_SPC, KC_LGUI \
    )
};


#ifdef OLED_ENABLE

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _SVORAK:
            oled_write_ln_P(PSTR("svorak"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("symbols"), false);
            break;
        case _FNUM:
            oled_write_ln_P(PSTR("fn-num"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("gaming"), false);
            break;
        default:
            oled_write_ln_P(PSTR("unknown"), false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}


char keylog_str[24] = {};
const char keycode_to_name[] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = keycode_to_name[keycode];
  }

  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

// hook on each key-press
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      set_keylog(keycode, record);
  }
  return true;
}

void oled_render_keylog(void) {
    // just render the actual keylog string into the
    // screen as is
    oled_write(keylog_str, false);
}

// init hook
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

// actual rendering loop
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif

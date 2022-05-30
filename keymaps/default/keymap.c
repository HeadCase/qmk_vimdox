#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SYMB,
    NAV,
    ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)
#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, MO(_NAV),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_SPC, MO(_SYMB), KC_LCTL, KC_LALT, KC_BSPC, KC_ENT
        //`--------------------------'  `--------------------------'

        ),

    [_SYMB] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TO(_NAV), KC_EXLM, KC_AT, KC_NUHS, KC_AMPR, KC_LCBR, KC_RCBR, KC_PMNS, KC_PLUS, KC_EQL, KC_0, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(_QWERTY), KC_PERC, KC_DLR, KC_UNDS, KC_ASTR, KC_LPRN, KC_RPRN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, RGB_MOD, KC_CIRC, KC_GRV, KC_LT, KC_LBRC, KC_RBRC, KC_GT, KC_DQUO, KC_TILD, RGB_TOG, KC_PGDN,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_BTN2, TO(_SYMB), KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS
        //`--------------------------'  `--------------------------'
        ),

    [_NAV] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PAST, KC_PLUS, KC_P7, KC_P8, KC_P9, KC_CALC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(_QWERTY), KC_F6, KC_F7, KC_F8, KC_F9, KC_F19, KC_PSLS, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PEQL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LGUI, KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_VOLU, KC_PERC, KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_TRNS, TO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //`--------------------------'  `--------------------------'
        ),

    [_ADJUST] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
        //`--------------------------'  `--------------------------'
        )};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state | default_layer_state) > 0) {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else { /* Layer 0 */
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    }

    return false;
}


#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // LAYER 0 (Base)
    LAYOUT_ortho_6x5(
        KC_ESC,  KC_1,   KC_2,   KC_3,    KC_4,
        KC_TAB,  KC_Q,   KC_W,   KC_E,    KC_R,
        KC_LCTL, KC_A,   KC_S,   KC_D,    KC_F,
        KC_LSFT, KC_Z,   KC_X,   KC_C,    KC_V,
        KC_LALT, KC_SPC, KC_ENT, KC_BSPC, KC_DEL,
        MO(1),   KC_NO,  KC_NO,  KC_NO,   KC_NO
    ),
    // LAYER 1 (Fn Layer - RGB Cleaned out)
    LAYOUT_ortho_6x5(
        _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    // LAYER 2 (VIA Template)
    LAYOUT_ortho_6x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    // LAYER 3 (VIA Template)
    LAYOUT_ortho_6x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    )
};

#include QMK_KEYBOARD_H
#include "timer.h"

#define KEY_FLASH_MS 120

static uint16_t flash_start = 0;
static bool flash_active = false;

void set_strip_off(void) {
    for (uint8_t i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        rgblight_setrgb_at(i, 0, 0, 0);
    }
}

void trigger_key_flash(void) {
    flash_active = true;
    flash_start = timer_read();
    for (uint8_t i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        rgblight_setrgb_at(i, 0, 255, 0);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_7, KC_8, KC_9, KC_0,
        KC_4, KC_5, KC_6, KC_ENT
    )
};

void keyboard_post_init_user(void) {
    set_strip_off();
}

void matrix_scan_user(void) {
    if (!flash_active) {
        return;
    }

    uint16_t elapsed = timer_elapsed(flash_start);
    if (elapsed >= KEY_FLASH_MS) {
        set_strip_off();
        flash_active = false;
        return;
    }

    uint8_t brightness = 255 - ((elapsed * 255) / KEY_FLASH_MS);
    for (uint8_t i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        rgblight_setrgb_at(i, 0, brightness, 0);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        trigger_key_flash();
    }
    return true;
}



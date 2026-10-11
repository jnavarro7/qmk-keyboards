#include QMK_KEYBOARD_H
#include "timer.h"

#define KEY_FLASH_MS 120
#define NUM_LEDS 8

static uint16_t flash_start[NUM_LEDS] = {0};
static bool flash_active[NUM_LEDS] = {0};

void set_led_off(uint8_t led_idx) {
    if (led_idx < NUM_LEDS) {
        rgblight_setrgb_at(0, 0, 0, led_idx);
    }
}

void trigger_key_flash(uint8_t led_idx) {
    if (led_idx < NUM_LEDS) {
        flash_active[led_idx] = true;
        flash_start[led_idx] = timer_read();
        rgblight_setrgb_at(0, 255, 0, led_idx);
    }
}

// 4x2 keymap 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_5, KC_6, KC_7, KC_8,
        KC_1, KC_2, KC_3, KC_4
    )
};

void keyboard_post_init_user(void) {
    // RGB lighting configuration
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void matrix_scan_user(void) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        if (!flash_active[i]) {
            continue;
        }

        uint16_t elapsed = timer_elapsed(flash_start[i]);
        if (elapsed >= KEY_FLASH_MS) {
            set_led_off(i);
            flash_active[i] = false;
            continue;
        }

        uint8_t brightness = 255 - ((elapsed * 255) / KEY_FLASH_MS);
        rgblight_setrgb_at(0, brightness, 0, i);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t row = record->event.key.row;
        uint8_t col = record->event.key.col;
        uint8_t led_idx = (row * MATRIX_COLS) + col;

        trigger_key_flash(led_idx);
    }
    return true; // Process all keycodes normally
}

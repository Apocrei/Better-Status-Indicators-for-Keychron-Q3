/* Keychron Q3 ANSI (Encoder) VIA keymap
 * Conditional lighting:
 *  - Caps Lock ON  -> Caps + Arrow keys turn red
 *  - Scroll Lock ON-> Print, Scroll Lock, Pause turn red
 * Robustness:
 *  - Even when RGB is OFF, lock changes repaint/clear the relevant keys so nothing gets "stuck".
 * GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

// ----------------------
// Layers
// ----------------------
enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

// ----------------------
// Keymaps
// (Note: encoder variant still uses LAYOUT_tkl_f13_ansi here)
// ----------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,  KC_NO,    KC_NO,    RM_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RM_TOGG,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RM_TOGG,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

// ----------------------
// Encoder map (if enabled)
// ----------------------
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE

// ----------------------
// RGB Matrix indicators
// ----------------------
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"

// Paint all physical positions that resolve to keycode `kc`
static void paint_keycode(uint16_t kc, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t highest = get_highest_layer(layer_state | default_layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            keypos_t kp = (keypos_t){ .row = row, .col = col };
            if (keymap_key_to_keycode(highest, kp) == kc) {
                // Newer QMK uses matrix_co for key->LED index
                uint8_t idx = g_led_config.matrix_co[row][col];
                if (idx != NO_LED) rgb_matrix_set_color(idx, r, g, b);
            }
        }
    }
}

static inline void red(uint16_t kc) { paint_keycode(kc, 255, 0, 0); }
static inline void off(uint16_t kc) { paint_keycode(kc,   0, 0, 0); }
// Blink helper (500 ms period)
static inline bool blink_on(void) { return ((timer_read32() / 500) & 1) == 0; }
// Remember previous lock states (for one-time clear on falling edge)
static bool prev_caps_on = false;
static bool prev_scroll_on = false;

static void paint_caps_group(bool on) {
    if (on) { red(KC_CAPS); red(KC_UP); red(KC_DOWN); red(KC_LEFT); red(KC_RGHT); }
    else    { off(KC_CAPS); off(KC_UP); off(KC_DOWN); off(KC_LEFT); off(KC_RGHT); }
}
static void paint_scroll_group(bool on) {
    if (on) { red(KC_PSCR); red(KC_SCRL); red(KC_PAUS); }
    else    { off(KC_PSCR); off(KC_SCRL); off(KC_PAUS); }
}

// When RGB is OFF, repaint/clear indicators on lock changes so nothing gets stuck
bool led_update_user(led_t led_state) {
    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_enable_noeeprom();
        paint_caps_group(led_state.caps_lock);
        paint_scroll_group(led_state.scroll_lock);
        rgb_matrix_disable_noeeprom();
    }
    return true; // also allow default handling
}

// Normal per-frame painter while RGB is ON
bool rgb_matrix_indicators_user(void) {
    led_t leds = host_keyboard_led_state();

    // CAPS: blink when ON; clear once when turning OFF
    if (leds.caps_lock) {
        paint_caps_group(blink_on());   // true = red, false = off
    } else if (prev_caps_on) {
        paint_caps_group(false);        // one-time clear
    }

    // SCROLL: blink when ON; clear once when turning OFF
    if (leds.scroll_lock) {
        paint_scroll_group(blink_on());
    } else if (prev_scroll_on) {
        paint_scroll_group(false);
    }

    prev_caps_on   = leds.caps_lock;
    prev_scroll_on = leds.scroll_lock;

    return false; // keep base effects running
}
#endif

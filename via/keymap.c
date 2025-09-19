/* Keychron Q3 ANSI (Encoder) VIA keymap
 * Conditional lighting:
 *  - Caps Lock ON  -> Caps + Arrow keys turn red (blink)
 *  - Scroll Lock ON-> Print, Scroll Lock, Pause turn red (blink)
 * Robustness:
 *  - Even when RGB is OFF, lock changes repaint/clear the relevant keys so nothing gets "stuck".
 * Physical anchoring:
 *  - Scroll trio and arrow cluster are painted by their physical LED indices, so VIA remaps won't affect indicators.
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
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    QK_RGB_MATRIX_VALUE_DOWN,  QK_RGB_MATRIX_VALUE_UP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,  KC_NO,    KC_NO,    QK_RGB_MATRIX_MODE_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     QK_RGB_MATRIX_TOGGLE,  _______,  _______,  QK_RGB_MATRIX_TOGGLE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        QK_RGB_MATRIX_TOGGLE,  QK_RGB_MATRIX_MODE_NEXT,  QK_RGB_MATRIX_VALUE_UP,  QK_RGB_MATRIX_HUE_UP,  QK_RGB_MATRIX_SATURATION_UP,  QK_RGB_MATRIX_SPEED_UP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  QK_RGB_MATRIX_MODE_PREVIOUS,  QK_RGB_MATRIX_VALUE_DOWN,  QK_RGB_MATRIX_HUE_DOWN,  QK_RGB_MATRIX_SATURATION_DOWN,  QK_RGB_MATRIX_SPEED_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
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
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  QK_RGB_MATRIX_VALUE_DOWN,  QK_RGB_MATRIX_VALUE_UP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    QK_RGB_MATRIX_TOGGLE,  _______,  _______,  QK_RGB_MATRIX_TOGGLE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        QK_RGB_MATRIX_TOGGLE,  QK_RGB_MATRIX_MODE_NEXT,  QK_RGB_MATRIX_VALUE_UP,  QK_RGB_MATRIX_HUE_UP,  QK_RGB_MATRIX_SATURATION_UP,  QK_RGB_MATRIX_SPEED_UP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  QK_RGB_MATRIX_MODE_PREVIOUS,  QK_RGB_MATRIX_VALUE_DOWN,  QK_RGB_MATRIX_HUE_DOWN,  QK_RGB_MATRIX_SATURATION_DOWN,  QK_RGB_MATRIX_SPEED_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

// ----------------------
// Encoder map (if enabled)
// ----------------------
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(QK_RGB_MATRIX_VALUE_DOWN, QK_RGB_MATRIX_VALUE_UP)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(QK_RGB_MATRIX_VALUE_DOWN, QK_RGB_MATRIX_VALUE_UP)}
};
#endif // ENCODER_MAP_ENABLE

// ----------------------
// RGB Matrix indicators
// ----------------------
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"

// Map keycode -> LEDs (fallback helpers)
static void paint_keycode(uint16_t kc, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t highest = get_highest_layer(layer_state | default_layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            keypos_t kp = (keypos_t){ .row = row, .col = col };
            if (keymap_key_to_keycode(highest, kp) == kc) {
                uint8_t idx = g_led_config.matrix_co[row][col];
                if (idx != NO_LED) rgb_matrix_set_color(idx, r, g, b);
            }
        }
    }
}

static inline void paint_idx(uint8_t idx, uint8_t r, uint8_t g, uint8_t b) {
    if (idx != NO_LED) rgb_matrix_set_color(idx, r, g, b);
}
static inline void red_kc(uint16_t kc) { paint_keycode(kc, 255, 0, 0); }
static inline void off_kc(uint16_t kc) { paint_keycode(kc,   0, 0, 0); }

// Blink helper (500 ms period)
static inline bool blink_on(void) { return ((timer_read32() / 500) & 1) == 0; }

// Remember previous lock states (for one-time clear on falling edge)
static bool prev_caps_on   = false;
static bool prev_scroll_on = false;

// --- Physical LED indices for anchored groups ---
static uint8_t led_caps  = NO_LED;
static uint8_t led_up    = NO_LED, led_down = NO_LED, led_left = NO_LED, led_right = NO_LED;
static uint8_t led_pscr  = NO_LED, led_scrl = NO_LED, led_paus = NO_LED;
static bool    leds_resolved = false;

// Resolve indices once by scanning a base layer (prefers WIN_BASE, falls back to MAC_BASE)
static void resolve_indices_once(void) {
    if (leds_resolved) return;
    uint8_t layers_to_try[2] = { WIN_BASE, MAC_BASE };
    for (uint8_t li = 0; li < 2; li++) {
        uint8_t layer = layers_to_try[li];
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                keypos_t kp = (keypos_t){ .row = row, .col = col };
                uint16_t kc = keymap_key_to_keycode(layer, kp);
                uint8_t idx = g_led_config.matrix_co[row][col];
                if (idx == NO_LED) continue;

                if (kc == KC_CAPS && led_caps == NO_LED) led_caps = idx;

                if (kc == KC_UP   && led_up    == NO_LED) led_up    = idx;
                if (kc == KC_DOWN && led_down  == NO_LED) led_down  = idx;
                if (kc == KC_LEFT && led_left  == NO_LED) led_left  = idx;
                if (kc == KC_RGHT && led_right == NO_LED) led_right = idx;

                if (kc == KC_PSCR && led_pscr  == NO_LED) led_pscr  = idx;
                if (kc == KC_SCRL && led_scrl  == NO_LED) led_scrl  = idx;
                if (kc == KC_PAUS && led_paus  == NO_LED) led_paus  = idx;
            }
        }
        if ((led_up|led_down|led_left|led_right) != NO_LED || (led_pscr|led_scrl|led_paus) != NO_LED || led_caps != NO_LED) break;
    }
    leds_resolved = true;
}

// Group painters that prefer physical indices, with keycode fallback
static void paint_caps_group(bool on) {
    if (leds_resolved && (led_caps != NO_LED || led_up != NO_LED || led_down != NO_LED || led_left != NO_LED || led_right != NO_LED)) {
        uint8_t r = on ? 255 : 0, g = 0, b = 0;
        paint_idx(led_caps,  r, g, b);
        paint_idx(led_up,    r, g, b);
        paint_idx(led_down,  r, g, b);
        paint_idx(led_left,  r, g, b);
        paint_idx(led_right, r, g, b);
        return;
    }
    if (on) { red_kc(KC_CAPS); red_kc(KC_UP); red_kc(KC_DOWN); red_kc(KC_LEFT); red_kc(KC_RGHT); }
    else    { off_kc(KC_CAPS); off_kc(KC_UP); off_kc(KC_DOWN); off_kc(KC_LEFT); off_kc(KC_RGHT); }
}

static void paint_scroll_group(bool on) {
    if (leds_resolved && (led_pscr != NO_LED || led_scrl != NO_LED || led_paus != NO_LED)) {
        uint8_t r = on ? 255 : 0, g = 0, b = 0;
        paint_idx(led_pscr, r, g, b);
        paint_idx(led_scrl, r, g, b);
        paint_idx(led_paus, r, g, b);
        return;
    }
    if (on) { red_kc(KC_PSCR); red_kc(KC_SCRL); red_kc(KC_PAUS); }
    else    { off_kc(KC_PSCR); off_kc(KC_SCRL); off_kc(KC_PAUS); }
}

// Ensure indices are resolved after boot
void keyboard_post_init_user(void) {
    resolve_indices_once();
}

// When RGB is OFF, repaint/clear indicators on lock changes so nothing gets stuck
bool led_update_user(led_t led_state) {
    resolve_indices_once();
    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_enable_noeeprom();
        paint_caps_group(led_state.caps_lock);
        paint_scroll_group(led_state.scroll_lock);
        rgb_matrix_disable_noeeprom();
    }
    return true; // also allow default handling
}

// Normal per-frame painter while RGB is ON (blink + edge-clear)
bool rgb_matrix_indicators_user(void) {
    resolve_indices_once();

    led_t leds = host_keyboard_led_state();

    if (leds.caps_lock) {
        paint_caps_group(blink_on());   // true = red, false = off
    } else if (prev_caps_on) {
        paint_caps_group(false);        // one-time clear
    }

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

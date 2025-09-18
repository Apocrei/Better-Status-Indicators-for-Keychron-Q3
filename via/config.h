/* config.h for Keychron Q3 ANSI VIA custom build */

#pragma once


// ----------------------
// RGB Matrix settings
// ----------------------

// Use Keychron’s default LED count
#define RGB_MATRIX_LED_COUNT 87   // Q3 has 87 per-key RGB LEDs

// Enable Caps Lock / indicator handling
#define RGB_MATRIX_KEYPRESSES    // reacts to keypresses
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// Idle timeout (turns off lights after inactivity, optional)
#define RGB_MATRIX_TIMEOUT 600000   // 10 minutes in ms

// Allow suspend/resume to control LEDs
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

// Limit brightness for safety
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
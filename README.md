# Keychron Q3 (ANSI, Encoder) - VIA Keymap with Lock Indicators

This VIA keymap for the Keychron Q3 (ANSI, encoder version) adds **lock-aware lighting** while keeping all your normal RGB Matrix effects.

**What it does**
- Caps Lock ON  -> Caps key + Arrow keys turn red
- Scroll Lock ON -> PrintScreen, ScrollLock, Pause turn red
- Works even when RGB is toggled OFF: lock status still updates, so you never get "stuck red" keys

---

## Quick Start

1) Install QMK and set up the build environment.

- Windows: install QMK MSYS (https://msys.qmk.fm/), then run `qmk setup` inside QMK MSYS.
- macOS/Linux: follow https://docs.qmk.fm/#/newbs_getting_started then run `qmk setup`.

2) Place this keymap folder at:

```
qmk_firmware/keyboards/keychron/q3/ansi_encoder/keymaps/via
```

3) Build and flash (encoder version):

```bash
qmk compile -kb keychron/q3/ansi_encoder -km via
# Put the board in bootloader (hold Esc while plugging in USB-C, or press the reset button)
qmk flash   -kb keychron/q3/ansi_encoder -km via
```

If you have the non-encoder Q3, use these instead:

```bash
qmk compile -kb keychron/q3/ansi -km via
qmk flash   -kb keychron/q3/ansi -km via
```

---

## What is included

- `keymap.c`  - the VIA keymap with lock-aware lighting:
  - Uses `rgb_matrix_indicators_user()` to paint only the relevant keys while locks are ON.
  - Uses `led_update_user()` to briefly enable RGB when lights are OFF so Caps/Scroll changes still repaint or clear those keys immediately.
- `rules.mk`
  ```makefile
  VIA_ENABLE = yes
  RGB_MATRIX_ENABLE = yes
  RGBLIGHT_ENABLE = no
  CONSOLE_ENABLE = no
  COMMAND_ENABLE = no
  ```
- `config.h` is optional. You can omit it entirely. If you want defaults like a brightness cap or timeouts, create one in the same folder and add only what you need.

Folder layout (encoder variant):

```
qmk_firmware/
  keyboards/
    keychron/
      q3/
        ansi_encoder/
          keymaps/
            via/
              keymap.c
              rules.mk
              (optional) config.h
```

---

## Behavior details

- Caps Lock ON: lights `KC_CAPS`, `KC_UP`, `KC_DOWN`, `KC_LEFT`, `KC_RGHT` in red.
- Scroll Lock ON: lights `KC_PSCR`, `KC_SCRL`, `KC_PAUS` in red.
- RGB OFF case: if you toggle RGB off and then change Caps/Scroll, firmware briefly enables RGB to update just those keys, then disables again. Result: no stuck red keys when you turn locks off while the lights are off.

Base lighting and VIA-controlled effects remain intact. This keymap only overlays the listed keys while their corresponding lock is ON.

---

## Customizing

### Change the indicator color
Open `keymap.c` and modify the paint helper:
```c
static inline void red(uint16_t kc) { paint_keycode(kc, 255, 0, 0); }
```
For example, dim white:
```c
static inline void red(uint16_t kc) { paint_keycode(kc, 40, 40, 40); }
```

### Change which keys light up
Edit the groups:
```c
static void paint_caps_group(bool on) { /* keys for Caps */ }
static void paint_scroll_group(bool on) { /* keys for Scroll */ }
```

### Use with non-encoder Q3
Put the same `via/` folder under `keychron/q3/ansi/keymaps/` and build/flash with `-kb keychron/q3/ansi`.

---

## Troubleshooting

**VIA does not detect the board**
- Ensure `VIA_ENABLE = yes` in `rules.mk`.
- Unplug/replug the keyboard. In VIA, enable "Show Design tab" if needed.

**A key stays red after turning Caps/Scroll off while lights are off**
- This keymap's `led_update_user()` handles that case. Make sure it was not removed or modified.

**Compile error mentions `matrix_co` or `key_to_led`**
- Newer QMK uses `g_led_config.matrix_co[row][col]`. If your fork is older, replace with `g_led_config.key_to_led[row][col]` or update QMK.

**Revert to stock**
- Flash the official Keychron VIA firmware using QMK Toolbox, or build the default keymap:
```bash
qmk flash -kb keychron/q3/ansi_encoder -km default
```

---

## License

This keymap follows QMK's GPL-2.0-or-later license.

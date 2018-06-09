#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* enable/disable LEDs based on layout */
#undef BACKLIGHT_USE_SPLIT_BACKSPACE
#define BACKLIGHT_USE_SPLIT_BACKSPACE 1

#undef BACKLIGHT_USE_SPLIT_LEFT_SHIFT
#define BACKLIGHT_USE_SPLIT_LEFT_SHIFT 0

#undef BACKLIGHT_USE_SPLIT_RIGHT_SHIFT
#define BACKLIGHT_USE_SPLIT_RIGHT_SHIFT 1

#undef BACKLIGHT_USE_7U_SPACEBAR
#define BACKLIGHT_USE_7U_SPACEBAR 1

#undef BACKLIGHT_USE_ISO_ENTER
#define BACKLIGHT_USE_ISO_ENTER 0

#undef BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS
#define BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS 1

#undef BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED
#define BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED 1

#undef BACKLIGHT_DISABLE_AFTER_TIMEOUT
#define BACKLIGHT_DISABLE_AFTER_TIMEOUT 10

#undef BACKLIGHT_ALPHAS_MODS_ROW_0
#undef BACKLIGHT_ALPHAS_MODS_ROW_1
#undef BACKLIGHT_ALPHAS_MODS_ROW_2
#undef BACKLIGHT_ALPHAS_MODS_ROW_3
#undef BACKLIGHT_ALPHAS_MODS_ROW_4
#define BACKLIGHT_ALPHAS_MODS_ROW_0 0b0000000000000000
#define BACKLIGHT_ALPHAS_MODS_ROW_1 0b0010000000000001
#define BACKLIGHT_ALPHAS_MODS_ROW_2 0b0001000000000001
#define BACKLIGHT_ALPHAS_MODS_ROW_3 0b0011000000000001
#define BACKLIGHT_ALPHAS_MODS_ROW_4 0b0011100000000111

#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
/* #define TAPPING_TERM 150 */

#define FORCE_NKRO

#endif

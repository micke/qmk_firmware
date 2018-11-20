#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#undef BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED
#define BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED 1

#undef BACKLIGHT_DISABLE_AFTER_TIMEOUT
#define BACKLIGHT_DISABLE_AFTER_TIMEOUT 10

#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
/* #define TAPPING_TERM 150 */

#define FORCE_NKRO

#endif

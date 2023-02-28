/* Copyright 2022 Mantas Jurkuvenas

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID 0x4D44  // "MD"
// #define PRODUCT_ID 0x5244 // "RD"
// #define DEVICE_VER 0x0100
// #define MANUFACTURER Mantastic
// #define PRODUCT TheVimdoxKeyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS \
    { GP2, GP3, GP19, GP10 }

// wiring of each half
#define MATRIX_COL_PINS \
    { GP4, GP5, GP6, GP7, GP8, GP9 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define RGBLIGHT_LIMIT_VAL 250
#define LED_DISABLE_WHEN_USB_SUSPENDED
/* define if matrix has ghost */
// #define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN GP1
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13
/* ws2812 RGB LED */
#define RGB_DI_PIN GP29

#define RGBLED_NUM 21 // Number of LEDs
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SPLIT // sync LEDs between RIGHT and LEFT hand

#define ENCODERS_PAD_A \
    { GP18 }
#define ENCODERS_PAD_B \
    { GP26 }

#define ENCODER_RESOLUTION 2
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION

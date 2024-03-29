/*
Copyright 2023 Vitalii Drevenchuk <@Crandel>
SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#ifdef DEBUG_ENABLE
#include "print.h"
#endif
// Disable options
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#ifndef NO_PRINT
#define NO_PRINT
#endif // !NO_PRINT
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT

// Vial settings
#define VIAL_KEYBOARD_UID {0xF6, 0x24, 0xF4, 0x83, 0xB1, 0x4B, 0xE2, 0xB4}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 3 }

#define VIAL_TAP_DANCE_ENTRIES 15
#define VIAL_COMBO_ENTRIES     15

// Keyboard settings
#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define DYNAMIC_KEYMAP_MACRO_COUNT 15

#define TAPPING_TERM   260
#define TAPPING_TOGGLE 3
#define PERMISSIVE_HOLD

/* Select hand configuration */
#define USB_VBUS_PIN GP26

#ifdef LEADER_ENABLE
#  define LEADER_NO_TIMEOUT
#  define LEADER_PER_KEY_TIMING
#endif

/* Redefine default settings */
#define SERIAL_USART_PIN_SWAP

#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { GP3,  GP4,  GP5,  GP6,  GP7 }
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { GP11, GP12, GP13, GP14, GP15 }

/* Trackball settings*/
/* #undef PMW33XX_LIFTOFF_DISTANCE */
/* #define PMW33XX_LIFTOFF_DISTANCE 0x04 */
/* #undef POINTING_DEVICE_TASK_THROTTLE_MS */
/* #define POINTING_DEVICE_TASK_THROTTLE_MS 1 */

/* #define TRACKBALL_DPI_OPTIONS { 1200, 1800, 2600, 3400 } */
/* #define CHARYBDIS_MINIMUM_DEFAULT_DPI 1200 */
/* #define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 200 */

/* Mouse settings */
// #define MK_KINETIC_SPEED
/* #undef MOUSEKEY_DELAY */
/* #define MOUSEKEY_DELAY 5 */
/* #undef MOUSEKEY_INTERVAL */
/* #define MOUSEKEY_INTERVAL 10 */
/* #define MOUSEKEY_MOVE_DELTA 16 */
/* #define MOUSEKEY_INITIAL_SPEED 100 */
/* #define MOUSEKEY_BASE_SPEED 5000 */
/* #define MOUSEKEY_DECELERATED_SPEED 400 */
/* #define MOUSEKEY_ACCELERATED_SPEED 3000 */
/* #define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16 */
/* #define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32 */
/* #define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 */
/* #define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8 */
/* #define MK_3_SPEED */
/* #define MK_MOMENTARY_ACCEL */
/* #undef CHARYBDIS_MINIMUM_DEFAULT_DPI */
/* #define CHARYBDIS_MINIMUM_DEFAULT_DPI 600 */

/* #undef ROTATIONAL_TRANSFORM_ANGLE */
/* #define ROTATIONAL_TRANSFORM_ANGLE -25 */

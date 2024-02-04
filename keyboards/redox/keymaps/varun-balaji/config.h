#pragma once

/* Use I2C or Serial, not both */
// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

// Left half wiring
#ifdef MATRIX_ROW_PINS
    #undef MATRIX_ROW_PINS
#endif
#ifdef MATRIX_COL_PINS
    #undef MATRIX_COL_PINS
#endif
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5 }

// Tapping time for mod-tap
#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat (Home row mods)
#define TAPPING_FORCE_HOLD_PER_KEY

//
// Created by nethe on 11/9/2022.
//

#ifndef WYLD_QMK_FIRMWARE_6X6_H
#define WYLD_QMK_FIRMWARE_6X6_H

#endif // WYLD_QMK_FIRMWARE_6X6_H

#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_6x6_4_rp2040( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45,                          R40, R41, R42, R43, R44, R45, \
    L50, L51, L52, L53,                                              R52, R53, R54, R55, \
                        L54, L55, L65,                R60, R50, R51, \
                        L62, L63, L64,                R61, R62, R63  \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45 }, \
    { L50, L51, L52, L53, L54, L55 }, \
    { XXX, XXX, L62, L63, L64, L65 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, R43, R44, R45 }, \
    { R50, R51, R52, R53, R54, R55 }, \
    { R60, R61, R62, R63, XXX, XXX } \
}

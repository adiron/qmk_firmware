#pragma once

#include "quantum.h"

#define LAYOUT( \
                KA00, KA01, KA02, KA03, KA04, KA05,         KA07, KA08, KA09, KA10, KA11, KA12, KA13,         KA14, KA15, KA16, KA17, \
        KB06,   KB00, KB01, KB02, KB03, KB04, KB05, KF05,   KB07, KB08, KB09, KB10, KB11, KB12, KB13,         KB14, KB15, KB16, KB17, \
        KC06,   KC00, KC01, KC02, KC03, KC04, KC05,   KF07, KC07, KC08, KC09, KC10, KC11, KC12, KC13,         KC14, KC15, KC16, KC17, \
        KD06,   KD00, KD01, KD02, KD03, KD04, KD05,         KD07, KD08, KD09, KD10, KD11, KD12, KD13,         KD14, KD15, KD16,       \
        KE06,   KE00, KE01, KE02, KE03, KE04, KE05,         KE07, KE08, KE09, KE10, KE11, KE12, KE13,         KE14, KE15, KE16, KE17, \
        KF06,   KF00, KF01, KF02, KF03,    KF04,               KF08,    KF09, KF10, KF11, KF12, KF13,            KF14,   KF16        \
) { \
  { KA00, KA01, KA02, KA03, KA04, KA05,KC_NO, KA07, KA08, KA09, KA10, KA11, KA12, KB13, KA14, KA15, KA16, KA17}, \
  { KB00, KB01, KB02, KB03, KB04, KB05, KB06, KB07, KB08, KB09, KB10, KB11, KB12, KB13, KB14, KB15, KB16, KB17}, \
  { KC00, KC01, KC02, KC03, KC04, KC05, KC06, KC07, KC08, KC09, KC10, KC11, KC12, KC13, KC14, KC15, KC16, KC17}, \
  { KD00, KD01, KD02, KD03, KD04, KD05, KD06, KD07, KD08, KD09, KD10, KD11, KD12, KD13, KD14, KD15, KD16,KC_NO}, \
  { KE00, KE01, KE02, KE03, KE04, KE05, KE06, KE07, KE08, KE09, KE10, KE11, KE12, KE13, KE14, KE15, KE16, KE17}, \
  { KF00, KF01, KF02, KF03, KF04, KF05, KF06, KF07, KF08, KF09, KF10, KF11, KF12, KF13, KF14,KC_NO, KF16,KC_NO}  \
}



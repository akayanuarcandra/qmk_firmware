#pragma once

#include "quantum.h"

#define LAYOUT_baboon38( \
    K00, K01, K02, K03, K04,           K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14,           K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24,           K25, K26, K27, K28, K29, \
                   K30, K31,           K35, K34, \
                   K33, K32,           K36, K37  \
) \
{ \
    { K00,   K01,   K02,   K03,   K04    }, \
    { K10,   K11,   K12,   K13,   K14,   }, \
    { K20,   K21,   K22,   K23,   K24,   }, \
    { K30,   K31,   K32,   K33,   KC_NO, }, \
    { K05,   K06,   K07,   K08,   K09,   }, \
    { K15,   K16,   K17,   K18,   K19,   }, \
    { K25,   K26,   K27,   K28,   K29,   }, \
    { K34,   K35,   K36,   K37,   KC_NO,}, \
}

// General fingerpunch firmware include
#include "keyboards/fingerpunch/src/fp.h"

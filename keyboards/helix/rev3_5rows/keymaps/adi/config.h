// This sets a custom font. Somehow it wouldn't work without it.
#ifdef OLED_FONT_H
    #undef OLED_FONT_H
#endif
#ifdef MASTER_LEFT
    #undef MASTER_LEFT
#endif
#ifdef SPLIT_HAND_MATRIX_GRID
    #undef SPLIT_HAND_MATRIX_GRID
    #undef SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT
#endif
// #define MASTER_LEFT
#define MASTER_RIGHT
#define OLED_FONT_H "keyboards/helix/rev3_5rows/keymaps/adi/helixfont.h"

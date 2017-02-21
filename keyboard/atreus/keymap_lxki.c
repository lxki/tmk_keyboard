#include "keymap_common.h"

/*
 *  q    w    e    r    t        ||        y    u    i    o    p
 *  a    s    d    f    g        ||        h    j    k    l    ;
 *  z    x    c    v    b        ||        n    m    ,    .    /
 * esc  fn2 ctrl  fn0  shft  spc ||  ent shft  fn1  alt  ins  gui
 */
#define MAIN_LAYER KEYMAP(                     \
         Q, W, E, R, T, Y, U, I, O, P,         \
         A, S, D, F, G, H, J, K, L, SCLN,      \
         Z, X, C, V, B, N, M, COMM, DOT, SLSH, \
         ESC, FN2, LCTL, FN0, LSFT,            \
         SPC, ENT,                             \
         RSFT, FN1, LALT, INSERT, LGUI)

/*
 * nop  home  up  end  pgup      ||       nop   7    8    9   nop
 * nop  left down rght pgdn      ||        0    4    5    6   nop
 * nop  nop  nop  nop  nop       ||       nop   1    2    3   nop
 * trns nop  trns nop  trns del  || bspc trns  nop trns trns trns
 */
#define FN0_LAYER KEYMAP(                             \
         NO, HOME UP, END, PGUP, NO, 7, 8, 9, NO,     \
         NO, LEFT, DOWN, RIGHT, PGDN, 0, 4, 5, 6, NO, \
         NO, NO, NO, NO, NO, NO, 1, 2, 3, NO,         \
         TRNS, NO, TRNS, NO, TRNS,                    \
         DEL, BSPC,                                   \
         TRNS, NO, TRNS, TRNS, TRNS)

/*
 *  ~    -    .    ,    =        ||      pgup  home  up  end  nop
 *  (    )    [    ]    "        ||      pgdn  left down rght  nop
 * nop  nop  nop  nop   \        ||      nop   nop  nop  nop  nop
 * trns nop  trns nop  trns del  || bspc trns  nop  trns trns trns
 */
#define FN1_LAYER KEYMAP(                                                   \
         GRV, MINS, DOT, COMM, EQL, PGUP, HOME, UP, END, NO,                \
         SHIFT(9), SHIFT(0), LBRC, RBRC, QUOT, PGDN, LEFT, DOWN, RIGHT, NO, \
         NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                            \
         TRNS, NO, TRNS, NO, TRNS,                                          \
         DEL, BSPC,                                                         \
         TRNS, NO, TRNS, TRNS, TRNS)

/*
 * vlup nop  nop  nop  nop       ||      f12    f7  f8   f9  nop
 * vldn nop  nop  nop  nop       ||      f10    f4  f5   f6  nop
 * mute nop  nop  nop  nop       ||      f11    f1  f2   f3  nop
 * boot nop  trns nop  trns trns || trns trns  nop trns trns trns
 */
#define FN2_LAYER KEYMAP(                           \
         VOLU, NO, NO, NO, NO, F12, F7, F8, F9, NO, \
         VOLD, NO, NO, NO, NO, F10, F4, F5, F6, NO, \
         MUTE, NO, NO, NO, NO, F11, F1, F2, F3, NO, \
         FN3, NO, TRNS, NO, TRNS,                   \
         TRNS, TRNS,                                \
         TRNS, NO, TRNS, TRNS, TRNS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  MAIN_LAYER,
  FN0_LAYER,
  FN1_LAYER,
  FN2_LAYER
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),
  [1] = ACTION_LAYER_MOMENTARY(2),
  [2] = ACTION_LAYER_MOMENTARY(3),
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (id == BOOTLOADER) {
    bootloader();
  }
}

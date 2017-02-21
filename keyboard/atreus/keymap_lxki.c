#include "keymap_common.h"

/*
 *  q    w    e    r    t        ||        y    u    i    o    p
 *  a    s    d    f    g        ||        h    j    k    l    ;
 *  z    x    c    v    b        ||        n    m    ,    .    /
 * esc  fn2 ctrl  fn0  shft  spc ||  ent shft  fn1  alt  ins  gui
 */
#define MAIN_LAYER KEYMAP(                                                   \
         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,         \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,      \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_FN2, KC_LCTL, KC_FN0, KC_LSFT,                           \
         KC_SPC, KC_ENT,                                                     \
         KC_RSFT, KC_FN1, KC_LALT, KC_INSERT, KC_LGUI)

/*
 * nop  home  up  end  pgup      ||       nop   7    8    9   nop
 * nop  left down rght pgdn      ||        0    4    5    6   nop
 * nop  nop  nop  nop  nop       ||       nop   1    2    3   nop
 * trns nop  trns nop  trns del  || bspc trns  nop trns trns trns
 */
#define FN0_LAYER KEYMAP(                                                           \
         KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_7, KC_8, KC_9, KC_NO,    \
         KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_0, KC_4, KC_5, KC_6, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO,         \
         KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS,                                   \
         KC_DEL, KC_BSPC,                                                           \
         KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS)

/*
 *  ~    -    .    ,    =        ||      pgup  home  up  end  nop
 *  (    )    [    ]    "        ||      pgdn  left down rght  nop
 * nop  nop  nop  nop   \        ||      nop   nop  nop  nop  nop
 * trns nop  trns nop  trns del  || bspc trns  nop  trns trns trns
 */
#define FN1_LAYER KEYMAP(                                                                                 \
         KC_GRV, KC_MINS, KC_DOT, KC_COMM, KC_EQL, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO,                \
         SHIFT(KC_9), SHIFT(KC_0), KC_LBRC, KC_RBRC, KC_QUOT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            \
         KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS,                                                         \
         KC_DEL, KC_BSPC,                                                                                 \
         KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS)

/*
 * vlup nop  nop  nop  nop       ||      f12    f7  f8   f9  nop
 * vldn nop  nop  nop  nop       ||      f10    f4  f5   f6  nop
 * mute nop  nop  nop  nop       ||      f11    f1  f2   f3  nop
 * boot nop  trns nop  trns trns || trns trns  nop trns trns trns
 */
#define FN2_LAYER KEYMAP(                                                         \
         KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, \
         KC_VOLD, KC_NO, KC_NO, KC_NO, KC_NO, KC_F10, KC_F4, KC_F5, KC_F6, KC_NO, \
         KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_F11, KC_F1, KC_F2, KC_F3, KC_NO, \
         KC_FN3, KC_NO, KC_TRNS, KC_NO, KC_TRNS,                                  \
         KC_TRNS, KC_TRNS,                                                        \
         KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS)

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

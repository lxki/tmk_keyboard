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
         KC_ESC, KC_FN2, KC_LCTL, KC_FN0, KC_FN12,                           \
         KC_SPC, KC_ENT,                                                     \
         KC_FN13, KC_FN1, KC_LALT, KC_INSERT, KC_LGUI)

/*
 * nop  home  up  end  pgup      ||       nop   7    8    9   nop
 * tab  left down rght pgdn      ||        0    4    5    6   nop
 * nop  nop  nop  nop  nop       ||       nop   1    2    3   nop
 * trns nop  trns trns trns del  || bspc trns  nop trns trns trns
 */
#define FN0_LAYER KEYMAP(                                                            \
         KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_7, KC_8, KC_9, KC_NO,     \
         KC_TAB, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_0, KC_4, KC_5, KC_6, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO,          \
         KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,                                  \
         KC_DEL, KC_BSPC,                                                            \
         KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS)

/*
 *  ~    -    ,    .    =        ||      pgup  home  up  end  nop
 *  9    0    [    ]    "        ||      pgdn  left down rght  nop
 * nop  nop  nop  nop   \        ||      nop   nop  nop  nop  nop
 * trns nop  trns nop  trns del  || bspc trns  trns trns trns trns
 */
#define FN1_LAYER KEYMAP(                                                                   \
         KC_GRV, KC_MINS, KC_COMM, KC_DOT, KC_EQL, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO,  \
         KC_9, KC_0, KC_LBRC, KC_RBRC, KC_QUOT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              \
         KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS,                                           \
         KC_DEL, KC_BSPC,                                                                   \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

/*
 * vlup msb1 msup msb2 mswup     ||      f12    f7  f8   f9  nop
 * vldn msle msdn msri mswdn     ||      f10    f4  f5   f6  nop
 * mute nop  nop  nop  nop       ||      f11    f1  f2   f3  nop
 * boot trns trns nop  trns trns || trns trns  nop trns trns trns
 */
#define FN2_LAYER KEYMAP(                                                               \
         KC_VOLU, KC_FN10, KC_FN4, KC_FN11, KC_FN8, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, \
         KC_VOLD, KC_FN6, KC_FN5, KC_FN7, KC_FN9, KC_F10, KC_F4, KC_F5, KC_F6, KC_NO,   \
         KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_F11, KC_F1, KC_F2, KC_F3, KC_NO,       \
         KC_FN3, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,                                      \
         KC_TRNS, KC_TRNS,                                                              \
         KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  MAIN_LAYER,
  FN0_LAYER,
  FN1_LAYER,
  FN2_LAYER,
};

const uint16_t PROGMEM fn_actions[] = {
  // function layers
  [0] = ACTION_LAYER_MOMENTARY(1),
  [1] = ACTION_LAYER_MOMENTARY(2),
  [2] = ACTION_LAYER_MOMENTARY(3),

  // reset key
  [3] = ACTION_FUNCTION(BOOTLOADER),

  // mouse movement
  [4] = ACTION_MOUSEKEY(KC_MS_U),
  [5] = ACTION_MOUSEKEY(KC_MS_D),
  [6] = ACTION_MOUSEKEY(KC_MS_L),
  [7] = ACTION_MOUSEKEY(KC_MS_R),
  // mouse wheel
  [8] = ACTION_MOUSEKEY(KC_WH_U),
  [9] = ACTION_MOUSEKEY(KC_WH_D),
  // mouse click
  [10] = ACTION_MOUSEKEY(KC_BTN1),
  [11] = ACTION_MOUSEKEY(KC_BTN2),

  // left/right shift
  [12] = ACTION_FUNCTION(LEFT_SHIFT_PRESS),
  [13] = ACTION_FUNCTION(RIGHT_SHIFT_PRESS),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (id == BOOTLOADER) {
    bootloader();
    return;
  }

  if (id == LEFT_SHIFT_PRESS || id == RIGHT_SHIFT_PRESS) {
    uint8_t curr_weak_mods = 0;

    // Set weak_mods value for each shift key 
    if (id == LEFT_SHIFT_PRESS) {
      curr_weak_mods = MOD_BIT(KC_LSHIFT);
    } else {
      curr_weak_mods = MOD_BIT(KC_RSHIFT);
    }

    if (record->event.pressed) {
      // Get the previous weak_mods value
      uint8_t prev_weak_mods = get_weak_mods();

      // When a shift key is pressed, check previous weak_mods value.
      // If 0, then no shift key is held down.
      // If not 0, then at least one shift key is held down.
      if (prev_weak_mods != 0) {
        // Toggle capslock if more than one shift key is pressed. 
        add_key(KC_CAPSLOCK);
        send_keyboard_report();
        del_key(KC_CAPSLOCK);
        send_keyboard_report();
      } else {
        // Set the appropriate weak_mods value if just one shift
        // key is pressed.
        add_weak_mods(curr_weak_mods);
        send_keyboard_report();
      }
    } else {
      // Unset the weak_mods value when shift key is released. 
      del_weak_mods(curr_weak_mods);
      send_keyboard_report();
    }
  }
}

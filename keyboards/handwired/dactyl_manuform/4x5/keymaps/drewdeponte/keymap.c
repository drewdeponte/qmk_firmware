#include QMK_KEYBOARD_H

#include "keymap_dvorak.h"

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)
#define CTL_SPC  CTL_T(KC_SPC)
#define ALT_BSPC ALT_T(KC_BSPC)
#define ALT_ENT  ALT_T(KC_ENT)
#define SFT_BSPC SFT_T(KC_BSPC)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE TT(_RAISE)
#define LOWER TT(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base (dvorak)
* ,----------------------------------,                             ,----------------------------------,
* |   '  |   ,  |   .  |   p  |   y  |                             |   f  |   g  |   c  |   r  |   l  |
* |------+------+------+------+------|                             |-------------+------+------+------|
* |   a  |   o  |   e  |   u  |   i  |                             |   d  |   h  |   t  |   n  |   s  |
* |------+------+------+------+------|                             |------|------+------+------+------|
* |   ;  |   q  |   j  |   k  |   x  |                             |   b  |   m  |   w  |   v  |   z  |
* |------+------+------+-------------,                             ,-------------+------+------+------,
*        |  [   |   ]  |                                                         |   -  |   =  |
*        '------+------'-------------'                             '-------------'------+------'
*                      | ESC  |SPACE |                             | ENTER|  BS  |
*                      |  +   |      |                             |      |  +   |
*                      | SHIFT|      |                             |      |SHIFT |
*                      '------+------'                             '------+------'
*                                    '------+------' '------+------'
*                                    | TAB  |Raise | | Lower|  ~   |
*                                    '------+------' '------+------'
*                                    | CTRL | GUI  | | GUI  | ALT  |
*                                    '------+------' '------+------'
*/
    [_BASE] = LAYOUT(
        DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,                                         DV_F,    DV_G,    DV_C,    DV_R,    DV_L,
        DV_A,    DV_O,    DV_E,    DV_U,    DV_I,                                         DV_D,    DV_H,    DV_T,    DV_N,    DV_S,
        DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                         DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,
                          DV_LBRC, DV_RBRC,                                                        DV_MINS, DV_EQL,
                                                     SFT_ESC,  KC_SPC,  KC_ENT, SFT_BSPC,
                                                       RAISE,  KC_TAB,  DV_GRV, LOWER,
                                                     KC_LGUI, KC_LCTL,  KC_RALT, KC_RGUI
    ),
/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */
    [_RAISE] = LAYOUT(
        _______, _______, KC_MU,   _______, _______,                                      KC_VOLU, _______, KC_UP,   _______, KC_PGUP,
        _______, KC_ML,   KC_MD,   KC_MR,   _______,                                      KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        _______, _______, _______, _______, _______,                                      KC_VOLD, DV_SLSH, DV_BSLS, DV_QUES, DV_PIPE,
                 _______, _______,                                                                          KC_MB1,  KC_MB2,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        DV_1,    DV_2,    DV_3,    DV_4,    DV_5,                                         DV_6,    DV_7,    DV_8,    DV_9,    DV_0,
        DV_EXLM, DV_AT,   DV_HASH, DV_DLR,  DV_PERC,                                      DV_CIRC, DV_AMPR, DV_ASTR, DV_LPRN, DV_RPRN,
                 KC_F11,  KC_F12,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

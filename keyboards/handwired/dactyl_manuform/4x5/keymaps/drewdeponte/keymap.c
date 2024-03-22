#include QMK_KEYBOARD_H

#include "keymap_dvorak.h"
#include "features/achordion.h"

#define _BASE 0
#define _RAISE 1 // _RAISE
#define _MOTLR 2 // Motion Layer
#define _LMODLR 3 // Left Modifier Layer
#define _RMODLR 4 // Right Modifier Layer


/* #define DD_CTLA CTL_T(DV_A) */
/* #define DD_OPTO OPT_T(DV_O) */
/* #define DD_SFTE SFT_T(DV_E) */
/* #define DD_CMDU CMD_T(DV_U) */
/* #define DD_CMDH CMD_T(DV_H) */
/* #define DD_SFTT SFT_T(DV_T) */
/* #define DD_OPTN OPT_T(DV_N) */
/* #define DD_CTLS CTL_T(DV_S) */

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

#define SYMLR MO(_RAISE)
#define MOTLR MO(_MOTLR)
#define LMODLR MO(_LMODLR)
#define RMODLR MO(_RMODLR)

#define CTLA MT(MOD_LCTL, DV_A)
#define ALTO MT(MOD_LALT, DV_O)
#define SFTE MT(MOD_LSFT, DV_E)
#define CMDU MT(MOD_LGUI, DV_U)
#define CTLS MT(MOD_RCTL, DV_S)
#define ALTN MT(MOD_RALT, DV_N)
#define SFTT MT(MOD_RSFT, DV_T)
#define CMDH MT(MOD_RGUI, DV_H)

#define LCTLSYM LM(_RAISE, MOD_LCTL)
#define LALTSYM LM(_RAISE, MOD_LALT)
#define LSFTSYM LM(_RAISE, MOD_LSFT)
#define LGUISYM LM(_RAISE, MOD_LGUI)
#define RCTLSYM LM(_RAISE, MOD_RCTL)
#define RALTSYM LM(_RAISE, MOD_RALT)
#define RSFTSYM LM(_RAISE, MOD_RSFT)
#define RGUISYM LM(_RAISE, MOD_RGUI)

/* I am not actively using any of the following currently. But I may want to go
 * back to them so just keeping them here for a while. */
#define WIN1 LOPT(LCTL(LSFT(DV_1)))
#define WIN2 LOPT(LCTL(LSFT(DV_2)))
#define WIN3 LOPT(LCTL(LSFT(DV_3)))
#define WIN4 LOPT(LCTL(LSFT(DV_4)))
#define LAUNCHER LGUI(KC_SPC)
#define JMPFWD LCTL(DV_I)
#define JMPBCK LCTL(DV_O)
#define COMNT LGUI(DV_SLSH)
#define QUITAPP LGUI(DV_Q)


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
*                                    |MOTLR |SYMLR | | SYMLR|  TAB |
*                                    '------+------' '------+------'
*                                    |MODLR | LCMD | | RCMD |MODLR |
*                                    '------+------' '------+------'
*/
    [_BASE] = LAYOUT(
        DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,                                         DV_F,    DV_G,    DV_C,    DV_R,    DV_L,
           CTLA,    ALTO,   SFTE,  CMDU,    DV_I,                                         DV_D,    CMDH,    SFTT,    ALTN,    CTLS,
        DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                         DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,
                          DV_LBRC, DV_RBRC,                                                        DV_MINS, DV_EQL,
                                                     SFT_ESC,  KC_SPC,  KC_ENT, SFT_BSPC,
                                                       SYMLR,  MOTLR,   KC_TAB, SYMLR,
                                                      KC_LCMD, LMODLR,   RMODLR, KC_RCMD
    ),

/* Raise - SYMLR - Symbol Layer
 * ,----------------------------------,                             ,----------------------------------,
 * |  1   |  2   |  3   |  4   |  5   |                             |   !  |  @   |  #   |  $   |  %   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  6   |  7   |  8   |  9   |  0   |                             |   ^  |  &   |  *   |  (   |  )   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             |      |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |  `   |  ~   |
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
           DV_1,    DV_2,    DV_3,    DV_4,    DV_5,                                      DV_EXLM,   DV_AT, DV_HASH,  DV_DLR, DV_PERC,
           DV_6,    DV_7,    DV_8,    DV_9,    DV_0,                                      DV_CIRC, DV_AMPR, DV_ASTR, DV_LPRN, DV_RPRN,
        _______, _______, _______, _______, _______,                                      _______, DV_SLSH, DV_BSLS, DV_QUES, DV_PIPE,
                 _______, _______,                                                                           DV_GRV, DV_TILD,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),
/* MOTLR - Motion Layer
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |      |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      |      |      |      |      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |      |      |      |      |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |      |      |
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
    [_MOTLR] = LAYOUT(
        _______, _______, _______, _______, _______,                                      KC_VOLU, _______, KC_UP,   _______, KC_PGUP,
        _______, _______, _______, _______, _______,                                      KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        _______, _______, _______, _______, _______,                                      KC_VOLD, _______, _______, _______, _______,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

/* LMODLR - Left Modifier Layer
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |      |      |      |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | CTL  | ALT  | SFT  | GUI  |      |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |CTLSYM|ALTSYM|SFTSYM|GUISYM|      |                             |      |      |      |      |      |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |      |      |
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
    [_LMODLR] = LAYOUT(
        _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______,
        KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, _______,                                      _______, _______, _______, _______, _______,
        LCTLSYM, LALTSYM, LSFTSYM, LGUISYM, _______,                                      _______, _______, _______, _______, _______,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),
/* RMODLR - Right Modifier Layer
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |      |      |      |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      |      |      |      |      |                             |      | GUI  | SFT  | ALT  | CTL  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             |      |GUISYM|SFTSYM|ALTSYM|CTLSYM|
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |      |      |
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
    [_RMODLR] = LAYOUT(
        _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                      _______, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL,
        _______, _______, _______, _______, _______,                                      _______, RGUISYM, RSFTSYM, RALTSYM, RCTLSYM,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

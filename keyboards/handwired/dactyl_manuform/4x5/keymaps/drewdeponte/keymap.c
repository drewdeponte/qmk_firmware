#include QMK_KEYBOARD_H

#include "keymap_dvorak.h"

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
           DV_A,    DV_O,   DV_E,  DV_U,    DV_I,                                         DV_D,    DV_H,    DV_T,    DV_N,    DV_S,
        DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                         DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,
                          DV_LBRC, DV_RBRC,                                                        DV_MINS, DV_EQL,
                                                     SFT_ESC,  KC_SPC,  KC_ENT, SFT_BSPC,
                                                       SYMLR,  MOTLR,   KC_TAB, SYMLR,
                                                      KC_LCMD, LMODLR,  RMODLR, KC_RCMD
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

/*
 * need to add COMBO_ENABLED = yes to rules.mk
 *
 * also it is worth noting that I tried KC_LCTL in the combo as the thumb
 * cluster key, however this created problems with trying to actually create
 * Ctrl-A combo. So then I tried KC_NO but that created problems where A by
 * itself was being seen as a Ctrl.
 *
 * One thing I didn't try was trying to use KC_F24 for the key in the thumb cluster.
 * */

/*
enum combos {
  LCTL_COMBO,
  LALT_COMBO,
  LCMD_COMBO,
  LCTLALT_COMBO,
  LALTCMD_COMBO,
  LCTLALTCMD_COMBO,
  LCTLSFT_COMBO,
  LALTSFT_COMBO,
  LCMDSFT_COMBO,
  LCTLALTSFT_COMBO,
  LALTCMDSFT_COMBO,
  LCTLALTCMDSFT_COMBO,
  RCTL_COMBO,
  RALT_COMBO,
  RCMD_COMBO,
  RCTLALT_COMBO,
  RALTCMD_COMBO,
  RCTLALTCMD_COMBO,
  RCTLSFT_COMBO,
  RALTSFT_COMBO,
  RCMDSFT_COMBO,
  RCTLALTSFT_COMBO,
  RALTCMDSFT_COMBO,
  RCTLALTCMDSFT_COMBO,
};

const uint16_t PROGMEM ao_combo[] = {DV_A, DV_O, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {DV_O, DV_E, COMBO_END};
const uint16_t PROGMEM eu_combo[] = {DV_E, DV_U, COMBO_END};

const uint16_t PROGMEM aoe_combo[] = {DV_A, DV_O, DV_E, COMBO_END};
const uint16_t PROGMEM oeu_combo[] = {DV_O, DV_E, DV_U, COMBO_END};
const uint16_t PROGMEM aoeu_combo[] = {DV_A, DV_O, DV_E, DV_U, COMBO_END};

const uint16_t PROGMEM aoSFT_combo[] = {DV_A, DV_O, KC_LSFT, COMBO_END};
const uint16_t PROGMEM oeSFT_combo[] = {DV_O, DV_E, KC_LSFT, COMBO_END};
const uint16_t PROGMEM euSFT_combo[] = {DV_E, DV_U, KC_LSFT, COMBO_END};

const uint16_t PROGMEM aoeSFT_combo[] = {DV_A, DV_O, DV_E, KC_LSFT, COMBO_END};
const uint16_t PROGMEM oeuSFT_combo[] = {DV_O, DV_E, DV_U, KC_LSFT, COMBO_END};
const uint16_t PROGMEM aoeuSFT_combo[] = {DV_A, DV_O, DV_E, DV_U, KC_LSFT, COMBO_END};

const uint16_t PROGMEM sn_combo[] = {DV_S, DV_N, COMBO_END};
const uint16_t PROGMEM nt_combo[] = {DV_N, DV_T, COMBO_END};
const uint16_t PROGMEM th_combo[] = {DV_T, DV_H, COMBO_END};

const uint16_t PROGMEM snt_combo[] = {DV_S, DV_N, DV_T, COMBO_END};
const uint16_t PROGMEM nth_combo[] = {DV_N, DV_T, DV_H, COMBO_END};
const uint16_t PROGMEM snth_combo[] = {DV_S, DV_N, DV_T, DV_H, COMBO_END};

const uint16_t PROGMEM snSFT_combo[] = {DV_S, DV_N, KC_RSFT, COMBO_END};
const uint16_t PROGMEM ntSFT_combo[] = {DV_N, DV_T, KC_RSFT, COMBO_END};
const uint16_t PROGMEM thSFT_combo[] = {DV_T, DV_H, KC_RSFT, COMBO_END};

const uint16_t PROGMEM sntSFT_combo[] = {DV_S, DV_N, DV_T, KC_RSFT, COMBO_END};
const uint16_t PROGMEM nthSFT_combo[] = {DV_N, DV_T, DV_H, KC_RSFT, COMBO_END};
const uint16_t PROGMEM snthSFT_combo[] = {DV_S, DV_N, DV_T, DV_H, KC_RSFT, COMBO_END};


combo_t key_combos[] = {
  [LCTL_COMBO] = COMBO(ao_combo, KC_LCTL),
  [LALT_COMBO] = COMBO(oe_combo, KC_LALT),
  [LCMD_COMBO] = COMBO(eu_combo, KC_LCMD),
  [LCTLALT_COMBO] = COMBO(aoe_combo, LCTL(KC_LALT)),
  [LALTCMD_COMBO] = COMBO(oeu_combo, LCMD(KC_LALT)),
  [LCTLALTCMD_COMBO] = COMBO(aoeu_combo, LCMD(LCTL(KC_LALT))),

  [LCTLSFT_COMBO] = COMBO(aoSFT_combo, LSFT(KC_LCTL)),
  [LALTSFT_COMBO] = COMBO(oeSFT_combo, LSFT(KC_LALT)),
  [LCMDSFT_COMBO] = COMBO(euSFT_combo, LSFT(KC_LCMD)),
  [LCTLALTSFT_COMBO] = COMBO(aoeSFT_combo, LSFT(LCTL(KC_LALT))),
  [LALTCMDSFT_COMBO] = COMBO(oeuSFT_combo, LSFT(LCMD(KC_LALT))),
  [LCTLALTCMDSFT_COMBO] = COMBO(aoeuSFT_combo, LSFT(LCMD(LCTL(KC_LALT)))),

  [RCTL_COMBO] = COMBO(sn_combo, KC_RCTL),
  [RALT_COMBO] = COMBO(nt_combo, KC_RALT),
  [RCMD_COMBO] = COMBO(th_combo, KC_RCMD),
  [RCTLALT_COMBO] = COMBO(snt_combo, RCTL(KC_RALT)),
  [RALTCMD_COMBO] = COMBO(nth_combo, RCMD(KC_RALT)),
  [RCTLALTCMD_COMBO] = COMBO(snth_combo, RCMD(RCTL(KC_RALT))),

  [RCTLSFT_COMBO] = COMBO(snSFT_combo, RSFT(KC_RCTL)),
  [RALTSFT_COMBO] = COMBO(ntSFT_combo, RSFT(KC_RALT)),
  [RCMDSFT_COMBO] = COMBO(thSFT_combo, RSFT(KC_RCMD)),
  [RCTLALTSFT_COMBO] = COMBO(sntSFT_combo, RSFT(RCTL(KC_RALT))),
  [RALTCMDSFT_COMBO] = COMBO(nthSFT_combo, RSFT(RCMD(KC_RALT))),
  [RCTLALTCMDSFT_COMBO] = COMBO(snthSFT_combo, RSFT(RCMD(RCTL(KC_RALT))))
};
*/


/* enum combos { */
  /* LCTL_COMBO, */
  /* LALT_COMBO, */
  /* LSFT_COMBO, */
  /* LCMD_COMBO, */
  /* LCTLALT_COMBO, */
  /* LALTCMD_COMBO, */
  /* LCTLALTCMD_COMBO, */
  /* LCTLSFT_COMBO, */
  /* LALTSFT_COMBO, */
  /* LCMDSFT_COMBO, */
  /* LCTLALTSFT_COMBO, */
  /* LALTCMDSFT_COMBO, */
  /* LCTLALTCMDSFT_COMBO, */
  /* RCTL_COMBO, */
  /* RALT_COMBO, */
  /* RCMD_COMBO, */
  /* RCTLALT_COMBO, */
  /* RALTCMD_COMBO, */
  /* RCTLALTCMD_COMBO, */
  /* RCTLSFT_COMBO, */
  /* RALTSFT_COMBO, */
  /* RCMDSFT_COMBO, */
  /* RCTLALTSFT_COMBO, */
  /* RALTCMDSFT_COMBO, */
  /* RCTLALTCMDSFT_COMBO, */
/* }; */

/*
const uint16_t PROGMEM aNO_combo[] = {DV_A, KC_NO, COMBO_END};
const uint16_t PROGMEM oNO_combo[] = {DV_O, KC_NO, COMBO_END};
const uint16_t PROGMEM eNO_combo[] = {DV_E, KC_NO, COMBO_END};
const uint16_t PROGMEM uNO_combo[] = {DV_U, KC_NO, COMBO_END};
const uint16_t PROGMEM aoNO_combo[] = {DV_A, DV_O, KC_LCTL, COMBO_END};
const uint16_t PROGMEM aeNO_combo[] = {DV_A, DV_E, KC_LCTL, COMBO_END};
const uint16_t PROGMEM auNO_combo[] = {DV_A, DV_U, KC_LCTL, COMBO_END};
const uint16_t PROGMEM aoeNO_combo[] = {DV_A, DV_O, DV_E, KC_LCTL, COMBO_END};
const uint16_t PROGMEM aoeuNO_combo[] = {DV_A, DV_O, DV_E, DV_U, KC_LCTL, COMBO_END};
*/

/* const uint16_t PROGMEM aoe_combo[] = {DV_A, DV_O, DV_E, COMBO_END}; */
/* const uint16_t PROGMEM oeu_combo[] = {DV_O, DV_E, DV_U, COMBO_END}; */
/* const uint16_t PROGMEM aoeu_combo[] = {DV_A, DV_O, DV_E, DV_U, COMBO_END}; */

/* const uint16_t PROGMEM aoSFT_combo[] = {DV_A, DV_O, KC_LSFT, COMBO_END}; */
/* const uint16_t PROGMEM oeSFT_combo[] = {DV_O, DV_E, KC_LSFT, COMBO_END}; */
/* const uint16_t PROGMEM euSFT_combo[] = {DV_E, DV_U, KC_LSFT, COMBO_END}; */

/* const uint16_t PROGMEM aoeSFT_combo[] = {DV_A, DV_O, DV_E, KC_LSFT, COMBO_END}; */
/* const uint16_t PROGMEM oeuSFT_combo[] = {DV_O, DV_E, DV_U, KC_LSFT, COMBO_END}; */
/* const uint16_t PROGMEM aoeuSFT_combo[] = {DV_A, DV_O, DV_E, DV_U, KC_LSFT, COMBO_END}; */

/* const uint16_t PROGMEM sn_combo[] = {DV_S, DV_N, COMBO_END}; */
/* const uint16_t PROGMEM nt_combo[] = {DV_N, DV_T, COMBO_END}; */
/* const uint16_t PROGMEM th_combo[] = {DV_T, DV_H, COMBO_END}; */

/* const uint16_t PROGMEM snt_combo[] = {DV_S, DV_N, DV_T, COMBO_END}; */
/* const uint16_t PROGMEM nth_combo[] = {DV_N, DV_T, DV_H, COMBO_END}; */
/* const uint16_t PROGMEM snth_combo[] = {DV_S, DV_N, DV_T, DV_H, COMBO_END}; */

/* const uint16_t PROGMEM snSFT_combo[] = {DV_S, DV_N, KC_RSFT, COMBO_END}; */
/* const uint16_t PROGMEM ntSFT_combo[] = {DV_N, DV_T, KC_RSFT, COMBO_END}; */
/* const uint16_t PROGMEM thSFT_combo[] = {DV_T, DV_H, KC_RSFT, COMBO_END}; */

/* const uint16_t PROGMEM sntSFT_combo[] = {DV_S, DV_N, DV_T, KC_RSFT, COMBO_END}; */
/* const uint16_t PROGMEM nthSFT_combo[] = {DV_N, DV_T, DV_H, KC_RSFT, COMBO_END}; */
/* const uint16_t PROGMEM snthSFT_combo[] = {DV_S, DV_N, DV_T, DV_H, KC_RSFT, COMBO_END}; */


/* combo_t key_combos[] = { */
/*   [LCTL_COMBO] = COMBO(aNO_combo, KC_LCTL), */
/*   [LALT_COMBO] = COMBO(oNO_combo, KC_LALT), */
/*   [LSFT_COMBO] = COMBO(eNO_combo, KC_LSFT), */
/*   [LCMD_COMBO] = COMBO(uNO_combo, KC_LCMD), */
/* }; */

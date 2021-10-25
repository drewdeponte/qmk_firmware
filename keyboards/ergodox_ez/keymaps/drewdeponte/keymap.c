#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    RAISE,  // symbols
    LOWER,  // media keys
};


#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * +------+------+------+------+-------           +------+------+------+------+------+
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------|           |------+------+------+------+------+
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |  ;   |
 * +------+------+------+------+------|           |------+------+------+------+------+
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |  '   |
 * +------+------+------+------+-------           -------+------+------+------+------+
 *        |   [  |   ]  |                                       |   -  |   =  |              
 *        ---------------                                       ---------------              
 *                      ,-------------.           ,-------------.
 *                      | TAB  | HOME |           | END  |  DEL  |
 *               ,------|------|------|           |------+--------+------.
 *               | space| Esc  | Raise|           | Lower| Enter  | Bs	 |
 *               |  +   |  +   |------|           |------|  +     |  +   |
 *               | alt  |Shift |  ~   |           | Gui  | Shift  | Ctrl |
 *               `--------------------'           `----------------------'
 *
 */
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  '   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |   [  |   ]  |      |                                       |      |   -  |   =  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TAB  | HOME |       | END  |  DEL  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | space| Esc  | Raise|       | Lower| Enter  | Bs	 |
 *                                 |  +   |  +   |------|       |------|  +     |  +   |
 *                                 | alt  |Shift |  ~   |       | Gui  | Shift  | Ctrl |
 *                                 `--------------------'       `----------------------'
 *
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         	 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_Q,        KC_W,      KC_E,    KC_R,    KC_T,    XXXXXXX,         	 XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
  XXXXXXX,  KC_A,        KC_S,      KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
  XXXXXXX,  KC_Z,        KC_X,      KC_C,    KC_V,    KC_B,    XXXXXXX,            XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, XXXXXXX,
  XXXXXXX,  XXXXXXX,     KC_LBRC,	  KC_RBRC, XXXXXXX,                                                XXXXXXX, KC_MINS, KC_EQL, 	XXXXXXX, XXXXXXX,
                                                       KC_TAB, KC_HOME,            KC_END, KC_DEL,
                                                             TT(RAISE),            TT(LOWER),
                                             ALT_SPC, SFT_ESC,  KC_GRV,            KC_RGUI, SFT_ENT, CTL_BSPC
),
/* Keymap 1: Mouse Keys, Arrow Keys, Media Keys, & small symbol set
 *
 * +------+------+------+------+-------           +------+------+------+------+------+
 * |      |      | MsUp |      |      |           | VOL+ |      |  up  |      | PgUp |
 * +------+------+------+------+------|           |------+------+------+------+------+
 * |      |MsLeft|MsDown|MsRght|      |           | MUTE | left | down | right| PgDn |
 * +------+------+------+------+------|           |------+------+------+------+------+
 * |      |      |      |      |      |           | VOL- |  /   |  \   |  ?   |  |   |
 * +------+------+------+------+-------           -------+------+------+------+------+
 *        |      |      |                                       | mbtn1| mbtn2|       
 *        ---------------                                       ---------------       
 *                      ,-------------.           ,-------------.
 *                      |      |      |           |      |      |
 *               ,------|------|------|           |------+------+------.
 *               |      |      |      |           |      |      |      |
 *               |      |      |------|           |------|      |      |
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
/* Keymap 1: Mouse Keys, Arrow Keys, Media Keys, & small symbol set
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      | VOL+ |      |  up  |      | PgUp |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| MUTE | left | down | right| PgDn |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | VOL- |  /   |  \   |  ?   |  |   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | mbtn1| mbtn2|      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RAISE] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______,     _______, KC_VOLU, _______, KC_UP,   _______, KC_PGUP, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,               				KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE, _______,
  _______, _______, _______, _______, _______,                                         _______, KC_BTN1, KC_BTN2, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
/* Keymap 2: 
 *
 * +------+------+------+------+-------           +------+------+------+------+------+
 * | F1   | F2   | F3   | F4   | F5   |           | F6   | F7   | F8   | F9   | F10  |
 * +------+------+------+------+------|           |------+------+------+------+------+
 * | 1    | 2    | 3    | 4    | 5    |           | 6    | 7    | 8    | 9    |  0   |
 * +------+------+------+------+------|           |------+------+------+------+------+
 * | !    | @    | #    | $    | %    |           | ^    | &    | *    | (    | )    |
 * +------+------+------+------+-------           -------+------+------+------+------+
 *        | F11  | F12  |                                       | -    | =    |              
 *        ---------------                                       ---------------              
 *                     ,-------------.            ,-------------.
 *                     |      |      |            |      |      |
 *              ,------|------|------|            |------+------+------.
 *              |      |      |      |            |      |      |      |
 *              |      |      |------|            |------|      |      |
 *              |      |      |      |            |      |      |      |
 *              `--------------------'            `--------------------'
 */
/* Keymap 2: 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F1   | F2   | F3   | F4   | F5   |      |           |      | F6   | F7   | F8   | F9   | F10  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | 1    | 2    | 3    | 4    | 5    |------|           |------| 6    | 7    | 8    | 9    |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | !    | @    | #    | $    | %    |      |           |      | ^    | &    | *    | (    | )    |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | F11  | F12  |      |                                       |      | -    | =    |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LOWER] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, KC_F11,  KC_F12,                                          _______, KC_MINS, KC_EQL,  _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

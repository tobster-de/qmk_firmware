#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Helpful defines
#define XXXXXXX     KC_NO
#define _______     KC_TRNS

// Layer names
#define BASE        0 // default layer
#define SYMB        1 // symbol layer
#define MDIA        2 // media keys

// missing mapping
#define DE_MICR     ALGR(KC_M)

/* Pretty Layout
.---------------------------------------------.         .---------------------------------------------.
|   1   |  2  |  3  |  4  |  5  |  6  |   7   |         !   8   |  9  |  10 |  11 |  12 |  13 |   14  |
!-------+-----+-----+-----+-----+-------------!         !-------+-----+-----+-----+-----+-----+-------!
|   15  |  16 |  17 |  18 |  19 |  20 |   21  |         !   22  |  23 |  24 |  25 |  26 |  27 |   28  |
!-------+-----+-----+-----x-----x-----!       !         !       !-----x-----x-----+-----+-----+-------!
|   29  |  30 |  31 |  32 |  33 |  34 |-------!         !-------!  35 |  36 |  37 |  38 |  39 |   40  |
!-------+-----+-----+-----x-----x-----!       !         !       !-----x-----x-----+-----+-----+-------!
|   41  |  42 |  43 |  44 |  45 |  46 |   47  |         !   48  |  49 |  50 |  51 |  52 |  53 |   54  |
'-------+-----+-----+-----+-----+-------------'         '-------------+-----+-----+-----+-----+-------'
 |  55  |  56 |  57 |  58 |  59 | .---------------. .---------------. !  60 |  61 |  62 |  63 |   64 |
 '------------------------------' |   65  |   66  | !   67  |   68  | '------------------------------'
                          .-------+-------+-------! !-------+-------+-------.
                          !       !       |   69  | !   70  |       !       !
                          !       !       !-------! !-------!       !       !
                          |   71  |   72  |   73  | !   74  |   75  |   76  |
                          '-----------------------' '-----------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer, used with german decals
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |           |      |   7  |   8  |   9  |   0  |  ß?  |   ´`   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |  TT  |   Z  |   U  |   I  |   O  |   P  |   +*~  |
 * |--------+------+------+------+------+------|      |           |   2  |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  #'  |  Enter |
 * |--------+------+------+------+------+------| OSL  |           | OSL  |------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |   1  |           |   1  |   N  |   M  |  ,;  |  .:  |  -_  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Gui  |  Alt | Left | Right|                                       |  Up  | Down | AltGr|  App | Ctrl |
 *   `----------------------------------' ,-------------.       ,-------------. `----------------------------------'
 *                                        | Ins  | Del  |       | Home |  End |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Space |Enter |
 *                                 |      |ace   |      |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
	[BASE] = LAYOUT_ergodox_pretty(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0,   DE_SS, DE_ACUT,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   TT(2),             TT(2),    DE_Z,    KC_U,    KC_I,    KC_O,    KC_P, DE_PLUS,
        KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L, DE_HASH,  KC_ENT, 
        KC_LSFT,    DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,  OSL(1),            OSL(1),    KC_N,    KC_M, KC_COMM,  KC_DOT, DE_MINS, KC_RSFT, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,                                                 KC_UP, KC_DOWN, DE_ALGR,  KC_APP, KC_RCTL,  
                                                      KC_INS,  KC_DEL,           KC_HOME,  KC_END, 
                                                              XXXXXXX,           KC_PGUP,
                                            KC_BSPC,  KC_SPC, XXXXXXX,           KC_PGDN,  KC_SPC,  KC_ENT),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^°   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   @  |      |   €  |      |      |      |           |      |      |   Ü  |      |   Ö  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Ä  |   ß  |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   <>|  |      |      |      |      |      |      |           |      |      |   µ  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  |   |  (   |       |  )   |  &   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  {   |       |  }   |      |      |
 *                                 |      |  <   |------|       |------|  >   |      |
 *                                 |      |      |  [   |       |  ]   |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
	[SYMB] = LAYOUT_ergodox_pretty(
        DE_CIRC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
        XXXXXXX,   DE_AT, XXXXXXX, DE_EURO, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX,   DE_UE, XXXXXXX,   DE_OE, XXXXXXX, XXXXXXX,
        XXXXXXX,   DE_AE,   DE_SS, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        DE_LESS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,           _______, XXXXXXX, DE_MICR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     DE_PIPE, DE_LPRN,           DE_RPRN, DE_AMPR,
                                                              DE_LCBR,           DE_RCBR,
                                            XXXXXXX,   KC_LT, DE_LBRC,           DE_RBRC,   KC_GT, XXXXXXX),

                                           
/* Keymap 2: Media / Numpad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | Numlk|      | Numlk|  /   |  *   |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Btn4 |MsLeft|MsDown|MsRght| Btn5 |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WhRght|WhDown| WhUp |WhLeft|WhClk |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |MsAcl0|MsAcl1|MsAcl2|                                       |  0   |  0   |  ,   | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Mute |       | Mute | Next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | WWW< |       | VolUp|      |      |
 *                                 | Stop | Play |------|       |------| Stop | Play |
 *                                 |      |      | WWW> |       | VolDn|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA
	[MDIA] = LAYOUT_ergodox_pretty(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_NLCK, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, _______,           _______, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, XXXXXXX,
        XXXXXXX, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,                             XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, XXXXXXX, 
        XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3, XXXXXXX,           XXXXXXX, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PENT, XXXXXXX, 
        XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2,                                                 KC_P0,   KC_P0, KC_PDOT, KC_PENT, XXXXXXX, 
                                                     KC_MPRV, KC_MUTE,           KC_MUTE, KC_MNXT,
                                                              KC_WBAK,           KC_VOLU,
                                            KC_MSTP, KC_MPLY, KC_WFWD,           KC_VOLD, KC_MSTP, KC_MPLY)
};

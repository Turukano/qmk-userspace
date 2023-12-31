enum layer_names {
    DEF,
    SHIF,
    NAV,
    NUM,
    STRG
};

#include QMK_KEYBOARD_H
#include "definitions.h"
#include "macros.h"
#include "tapdances.h"
#include "combos.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEF] = LAYOUT(
 LT(0,KC_J), KC_D, LT(0,KC_U), LT(0,KC_A), LT(0,KC_X),                  KC_P, LT(0,KC_H), LT(0,KC_L), LT(0,KC_M), KC_W,
 LT(STRG,KC_C), LT(NUM,KC_T), LT(0,KC_I), LT(0,KC_E), LT(0,KC_O),       KC_B, LT(0,KC_N), LT(0,KC_R), LT(0,KC_S), LT(0,KC_G),
 KC_F, LT(0,KC_V), LT(0,DE_UDIA), TD(ADIAAT), LT(0,DE_ODIA),            TD(YMINS), DE_Z, OSL(SHIF), LT(0,KC_COMM), KC_K,
 MO(NAV), OSL(SHIF), KC_DOT,                                            KC_BSPC, KC_SPC, KC_ENT ),

[SHIF] = LAYOUT( 
 S(KC_J), S(KC_D), LT(1,S(KC_U)), LT(1,S(KC_A)), S(KC_X),               S(KC_P), S(KC_H), S(KC_L), S(KC_M), S(KC_W),
 S(KC_C), S(KC_T), LT(1,S(KC_I)), LT(1,S(KC_E)), LT(1,S(KC_O)),         S(KC_B), S(KC_N), S(KC_R), S(KC_S), LT(1,S(KC_G)),
 S(KC_F), S(KC_V), LT(1,S(DE_UDIA)), S(DE_ADIA), LT(1,S(DE_ODIA)),      S(DE_Y), S(DE_Z), DE_UNDS, DE_SEMI, S(KC_K),
 _______, DE_DQUO, FN_COLN,                                             KC_BSPC, KC_SPC, S(KC_ENT) ),

[NAV] = LAYOUT( 
 KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,                           LT(1,KC_F5), FN_FFGOBACK, KC_UP, FN_FFGOFORTH, KC_DEL,
 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, _______,                           LT(1,KC_HOME), KC_LEFT, KC_DOWN, KC_RGHT, LT(1,KC_END),
 _______, _______, _______, FN_ZOOMOUT, FN_ZOOMIN,                      _______, C(KC_PGUP), LT(1,FN_FFXTAB), LT(1,C(KC_PGDN)), LT(1,KC_NO),
 _______, _______, _______,                                             KC_BSPC, KC_SPC, KC_ENT ),

[NUM] = LAYOUT( 
 _______, _______, _______, _______, _______,                           TD(PLUSIST), KC_7, KC_8, KC_9, TD(EURDOLLPARA),
 _______, _______, _______, _______, _______,                           TD(STARPIPEPM), KC_4, KC_5, KC_6, KC_0,
 _______, _______, _______, _______, _______,                           DE_MINS, KC_1, KC_2, LT(1,KC_3), TD(PERDEGTILD),
 _______, _______, KC_DOT,                                              KC_BSPC, KC_SPC, TD(ENTIST) ),

[STRG] = LAYOUT( 
 LWIN(DE_Y), FN_DESKTOP, _______, FN_SEALL, FN_CUT,                     FN_PRINT, FN_NO, FN_LCKSCRN, FN_ROTATE, _______,
 _______, C(KC_T), FN_TXTSHT, FN_EXPL, _______,                         FN_BULLET, FN_NEW, FN_RUN, TD(SAVEAS), TD(SCRNSHT),
 FN_SEARCH, _______, _______, _______, _______,                         FN_REDO, FN_UNDO, _______, _______, LT(1,FN_STREAM),
 _______, _______, _______,                                             C(KC_BSPC), _______, C(KC_ENTER) ),
};
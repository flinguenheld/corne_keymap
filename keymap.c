/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of

GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_bepo.h>

#include "features/french.h"
#include "features/tap_dance.c"


// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_bepo.h
        // SEND_STRING("aurnisetaurie");
        // send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");


enum layers { 
    _BASE, 
    _LOWER, 
    _RAISE, 
    _ARROWS,
    _MOUSE,
    _FN,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BSPC_DEL] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_DEL), // Backspace - Del
    [TD_TREMA_ALT] = ACTION_TAP_DANCE_TAP_HOLD(BP_DIAE, KC_LEFT_ALT), // Trema - Alt
    [TD_EXCLA_QUEST] = ACTION_TAP_DANCE_TAP_HOLD(BP_EXLM, BP_QUES), // ! - ?
    [TD_QUOTE_3DOTS] = ACTION_TAP_DANCE_TAP_HOLD(BP_QUOT, BP_ELLP), // ' - …

    [TD_PARENT] = ACTION_TAP_DANCE_TAP_HOLD(BP_LPRN, BP_RPRN), // ( - )
    [TD_BRACK] = ACTION_TAP_DANCE_TAP_HOLD(BP_LBRC, BP_RBRC), // [ - ]
    [TD_CURLY_B] = ACTION_TAP_DANCE_TAP_HOLD(BP_LCBR, BP_RCBR), // { - }
    [TD_SLASHS] = ACTION_TAP_DANCE_TAP_HOLD(BP_SLSH, BP_BSLS), // Slashs

    [TD_CURRENCY] = ACTION_TAP_DANCE_TAP_HOLD(BP_DLR, BP_EURO), // $ - €
    [TD_PERCENT] = ACTION_TAP_DANCE_TAP_HOLD(BP_PERC, BP_PERM), // % - BUG


    // Specific tap dances to replace LT(layer, kc)
    [TDS_LT3_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt3_colon_finished, lt3_colon_reset),
    [TDS_LT4_SCOLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt4_scolon_finished, lt4_scolon_reset)
};




const uint16_t PROGMEM test_combo1[] = {BP_E, BP_T, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {LT(_LOWER, BP_COMM), LT(_RAISE, BP_DOT), COMBO_END};
// const uint16_t PROGMEM combo_fn[] = {TD(TDS_LT4_SCOLON), TD(TDS_LT3_COLON), COMBO_END};
const uint16_t PROGMEM combo_fn[] = {LT(_RAISE, BP_DOT), BP_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, BP_W),
    COMBO(test_combo2, BP_A),
    COMBO(combo_fn, OSL(_FN)),
};



  /* [1] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ), */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
       KC_TAB               ,     BP_Z       ,    BP_EACU     ,     BP_P       ,     BP_O       ,        BP_ECIR        ,                BP_AGRV        ,      BP_V      ,      BP_D      ,      BP_L      ,      BP_J      ,     TD(TD_BSPC_DEL)   ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      GUI_T(KC_ESC)         ,     BP_A       ,     BP_U       ,     BP_I       ,     BP_E       ,   TD(TD_EXCLA_QUEST)  ,                 BP_C          ,      BP_T      ,      BP_S      ,      BP_R      ,      BP_N      ,     BP_M              ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      TD(TD_TREMA_ALT)      ,     BP_B       ,     BP_Y       ,     BP_X       ,     BP_W       ,   TD(TD_QUOTE_3DOTS)  ,                 BP_K          ,      BP_Q      ,      BP_G      ,      BP_H      ,      BP_F      , MT(MOD_RSFT, BP_DCIR) ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                            TD(TDS_LT4_SCOLON),   LT(1, BP_COMM)  ,    LCTL_T(KC_SPC)     ,        KC_ENT             ,   LT(2, BP_DOT)   , TD(TDS_LT3_COLON)
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_LOWER] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            BP_UNDS         ,     XXXXXXX    ,     BP_GRV     ,     BP_QUOT    ,    BP_DQUO     ,        XXXXXXX        ,               XXXXXXX         ,    BP_HASH     ,TD(TD_CURRENCY) ,      BP_AT     ,     XXXXXXX    ,        _______        ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    , TD(TD_CURLY_B) ,  TD(TD_BRACK)  ,  TD(TD_PARENT) ,        XXXXXXX        ,               XXXXXXX         ,    BP_AMPR     ,     BP_PIPE    ,     BP_TILD    ,     BP_ASTR    ,        XXXXXXX        ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     BP_LABK    ,    BP_RABK     ,  TD(TD_SLASHS) ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,     XXXXXXX    ,     BP_CIRC    ,        _______        ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,      XXXXXXX      ,        XXXXXXX        ,           XXXXXXX         ,     XXXXXXX       ,     XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_RAISE] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      BP_7      ,      BP_8      ,      BP_9      ,     BP_PLUS    ,       BP_MINS         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,                BP_EQL         ,      BP_4      ,      BP_5      ,      BP_6      ,     BP_ASTR    ,       BP_SLSH         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,                BP_DOT         ,      BP_1      ,      BP_2      ,      BP_3      ,     BP_CIRC    ,    TD(TD_PERCENT)     ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      BP_0
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_ARROWS] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    KC_HOME     ,  KC_PAGE_DOWN  ,   KC_PAGE_UP   ,     KC_END     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    KC_LEFT     ,    KC_DOWN     ,     KC_UP      ,    KC_RIGHT    ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,   CTL_T(BP_D)  ,   CTL_T(BP_U)  ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,  KC_MS_WH_LEFT ,   KC_MS_WH_UP  ,  KC_MS_WH_DOWN , KC_MS_WH_RIGHT ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_LEFT   ,    KC_MS_UP    ,   KC_MS_DOWN   ,   KC_MS_RIGHT  ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_BTN1   ,     XXXXXXX    ,   KC_MS_BTN3   ,   KC_MS_BTN2   ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_FN] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F7     ,      KC_F8     ,      KC_F9     ,     KC_F10     ,    KC_PRINT_SCREEN    ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F4     ,      KC_F5     ,      KC_F6     ,     KC_F11     ,   S(KC_PRINT_SCREEN)  ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F1     ,      KC_F2     ,      KC_F3     ,     KC_F12     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),


};


// --------------------------------------------------------------------------------
// Auto shift
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_TAB:
            return true;
        case BP_AT:
            return false;
        default:
            return false;
    }
}


// --------------------------------------------------------------------------------
// OLED

// Logo position in the glcdfont_flo.c file
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

// Return the logo for the right part (if it's the master)
oled_rotation_t oled_init_user(oled_rotation_t rotation) {

#ifdef MASTER_RIGHT
    if (!is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    else {
        return OLED_ROTATION_180;
    }
#endif

    return rotation;
}

// Display the layout on the master and the logo on the slave
bool oled_task_user(void) {

    if (is_keyboard_master()) {

        oled_clear();
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("\n   * BASE *"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("\n   ** LOWER **"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("\n   ** RAISE **"), false);
                break;
            case _ARROWS:
                oled_write_P(PSTR("\n   *** ARROWS ***"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("\n   *** MOUSE ***"), false);
                break;
            case _FN:
                oled_write_P(PSTR("\n   **** FN (OSL) ****"), false);
                break;

            default:
                oled_write_P(PSTR("Prout"), false);
        }

    } else {
        render_logo();  // Renders a static logo
    }
    return false;
}

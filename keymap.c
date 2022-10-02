/*
QMK keymap for the crkbd keyboard 3x6
Flo 2022

https://github.com/foostan/crkbd
https://docs.qmk.fm/#/
*/

#include QMK_KEYBOARD_H
#include <stdio.h>


// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Layers -----------------------------------------------------------------------------------------------------------------------------------------------
enum layers { 
    _BASE, 
    _NUMERIC, 
    _ARROWS,
    _MOUSE,
    _ADJUST,
    _FN,
};

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Timer ------------------------------------------------------------------------------------------------------------------------------------------------
// To shutdown oled screens
static uint16_t oled_timer = 0;
static bool     is_key_processed = true;

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Custom keys ------------------------------------------------------------------------------------------------------------------------------------------
enum custom_keys {
    UNICODE = SAFE_RANGE, // Shortcut to write a unicode, see numeric layer

    // With auto-shift
    CS_EACUTE,
    CS_AGRAVE,
    CS_EGRAVE,
    CS_UGRAVE,
    CS_CCEDILLA,
    CS_AE,
    CS_OE,

    CS_ACIRCUMFLEX,
    CS_ECIRCUMFLEX,
    CS_ICIRCUMFLEX,
    CS_OCIRCUMFLEX,
    CS_UCIRCUMFLEX,
    CS_EDIAERESIS,
    CS_IDIAERESIS,
    CS_UDIAERESIS,
    CS_YDIAERESIS,

    // Without, manage here
    CS_EURO,
    CS_POUND,
};

// --
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Restart the timer on all pressed key
    // The timer value is read by the oled_task_user() function
    if (record->event.pressed) {
        oled_timer = timer_read();
        is_key_processed = true;
    }

    // Macros
    switch (keycode) {

        case UNICODE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code16(KC_U);
            }else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;

        case CS_EURO:
            if (record->event.pressed) { send_unicode_string("€"); }
            break;
        case CS_POUND:
            if (record->event.pressed) { send_unicode_string("£"); }
            break;
    }

    return true;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Features ---------------------------------------------------------------------------------------------------------------------------------------------
#include "features/auto_shift.c"
#include "features/combo.c"
#include "features/oled.c"

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Layouts ----------------------------------------------------------------------------------------------------------------------------------------------

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
      KC_TAB                ,     KC_J       ,   CS_EACUTE    ,     KC_P       ,     KC_O       ,        KC_Z           ,                 KC_K          ,      KC_V      ,      KC_D      ,      KC_L      ,      KC_M      ,       KC_BSPC         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      GUI_T(KC_ESC)         ,     KC_A       ,     KC_U       ,     KC_I       ,     KC_E       ,       KC_EXLM         ,                 KC_C          ,      KC_T      ,      KC_S      ,      KC_R      ,      KC_N      ,       KC_QUOTE        ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      KC_LALT               ,     KC_B       ,     KC_Y       ,     KC_X       ,     KC_W       ,       KC_LABK         ,                KC_RABK        ,      KC_Q      ,      KC_G      ,      KC_H      ,      KC_F      ,       KC_RSFT         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                |----------------------+----------------------+-----------------------|   |-----------------------+----------------------+----------------------|
                                                            KC_SCLN        , LT(_MOUSE, KC_COMM)  ,        KC_LCPO        ,      LT(_NUMERIC, KC_ENT) , LT(_ARROWS, KC_DOT)  ,     KC_COLN
  //                                                |----------------------+----------------------+----/* Space ctl */----|   |-----------------------+----------------------+----------------------|
  ),

  [_NUMERIC] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     KC_RCBR    ,     KC_RBRC    ,    KC_RPRN     ,        XXXXXXX        ,                KC_COMM        ,      KC_7      ,      KC_8      ,      KC_9      ,     KC_PLUS    ,       KC_MINS         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     KC_LCBR    ,     KC_LBRC    ,    KC_LPRN     ,        XXXXXXX        ,                  KC_0         ,      KC_4      ,      KC_5      ,      KC_6      ,     KC_ASTR    ,       KC_SLSH         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,                 KC_EQL        ,      KC_1      ,      KC_2      ,      KC_3      ,     KC_CIRC    ,       KC_PERC         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       UNICODE     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,  KC_MS_WH_LEFT ,   KC_MS_WH_UP  ,  KC_MS_WH_DOWN , KC_MS_WH_RIGHT ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_LEFT   ,    KC_MS_UP    ,   KC_MS_DOWN   ,   KC_MS_RIGHT  ,        XXXXXXX        ,               XXXXXXX         ,  KC_MS_ACCEL0  ,  KC_MS_ACCEL1  ,  KC_MS_ACCEL2  ,    XXXXXXX     ,       KC_RCTL         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_BTN1   ,     XXXXXXX    ,   KC_MS_BTN3   ,   KC_MS_BTN2   ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,     XXXXXXX       ,        _______        ,          KC_MS_BTN1       ,     KC_MS_BTN3    ,     KC_MS_BTN2
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_ARROWS] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    KC_HOME     ,  KC_PAGE_DOWN  ,   KC_PAGE_UP   ,     KC_END     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    KC_LEFT     ,    KC_DOWN     ,     KC_UP      ,    KC_RIGHT    ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    C(KC_D)     ,    C(KC_U)     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,     XXXXXXX       ,        _______        ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     , KC_AUDIO_MUTE  , KC_AUDIO_VOL_UP,   KC_AUDIO_VOL_DOWN   ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
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

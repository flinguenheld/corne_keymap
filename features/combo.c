// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Combos

// How to :
//      - Add an entry in the enum
//      - Create a new sequence of keys
//      - Link the enum to this sequence in the key_combos table

// For macros :
//      - Same steps
//      - And add the macro in the process_combo_event() function

enum combos {

    LAYER_ADJUST,
    LAYER_FN,

    // French
    A_GRAVE,
    E_GRAVE,
    U_GRAVE,
    C_CEDILLA,

    E_A,
    E_O,

    A_CIRCUMFLEX,
    E_CIRCUMFLEX,
    I_CIRCUMFLEX,
    O_CIRCUMFLEX,
    U_CIRCUMFLEX,
    E_DIAERESIS,
    I_DIAERESIS,
    U_DIAERESIS,
    Y_DIAERESIS,

    // --
    ENTER_SHIFTED,
    CONTROL_SHIFT,
    CONTROL_ALT,
    CONTROL_SHIFT_ALT,
    RIGHT_ALT,

    // --
    AMPERSAND,
    AT,
    BACKSLASH,
    CIRCUMFLEX,
    DOUBLE_QUOTE,
    EQUAL,

    GRAVE,
    HASH,
    PIPE,
    PERCENT,
    PLUS,
    SLASH,
    STAR,
    TILDE,
    TIRET,              // Sorry Elis but it's better than dash
    UNDERSCORE,

    DOLLAR,
    EURO,
    POUND,

    // --
    // MAIL_SHORT,
        // KC_MAIL_SHORT,
    // MAIL_LONG,
        // KC_MAIL_LONG,

    COMBO_LENGTH, // Just to replace the define in config.h
};
uint16_t COMBO_LEN = COMBO_LENGTH;


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys

const uint16_t PROGMEM combo_adjust[] = {LT(_MOUSE, KC_COMM), LT(_ARROWS, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_fn_osl[] = {LT(_ARROWS, KC_DOT), KC_F, COMBO_END};

// --
const uint16_t PROGMEM combo_enter_shifted[] = {LT(_NUMERIC, KC_ENT), KC_S, COMBO_END};
const uint16_t PROGMEM combo_control_shift[] = {KC_LCPO, KC_S, COMBO_END};
const uint16_t PROGMEM combo_control_alt[] = {KC_LCPO, KC_A, COMBO_END};
const uint16_t PROGMEM combo_control_shift_alt[] = {KC_LCPO, KC_S, KC_A, COMBO_END};
const uint16_t PROGMEM combo_right_alt[] = {KC_LALT, KC_G, COMBO_END};

// --
const uint16_t PROGMEM combo_a_grave[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_grave[] = {CS_EACUTE, KC_E, COMBO_END};
const uint16_t PROGMEM combo_u_grave[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_c_cedilla[] = {KC_E, KC_C, COMBO_END};

const uint16_t PROGMEM combo_ea[] = {CS_EACUTE, KC_A, COMBO_END};
const uint16_t PROGMEM combo_eo[] = {CS_EACUTE, KC_O, COMBO_END};

const uint16_t PROGMEM combo_a_circumflex[] = {KC_C, KC_R, KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_circumflex[] = {KC_C, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_i_circumflex[] = {KC_C, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo_o_circumflex[] = {KC_C, KC_R, KC_O, COMBO_END};
const uint16_t PROGMEM combo_u_circumflex[] = {KC_C, KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM combo_e_diaeresis[] = {KC_T, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_i_diaeresis[] = {KC_T, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo_u_diaeresis[] = {KC_T, KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM combo_y_diaeresis[] = {KC_T, KC_R, KC_Y, COMBO_END};

// --
const uint16_t PROGMEM combo_ampersand[] = {KC_A, KC_P, COMBO_END};
const uint16_t PROGMEM combo_at[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM combo_backslash[] = {KC_D, KC_R, COMBO_END};
const uint16_t PROGMEM combo_circumflex[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_double_quote[] = {KC_D, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {KC_E, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_grave[] = {KC_G, KC_R, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_H, KC_S, COMBO_END};
const uint16_t PROGMEM combo_percent[] = {KC_P, KC_C, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_P, KC_E, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM combo_star[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM combo_tiret[] = {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_S, KC_R, COMBO_END};

// --
const uint16_t PROGMEM combo_dollar[] = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_euro[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_pound[] = {KC_P, KC_D, COMBO_END};

// With macros !
// const uint16_t PROGMEM combo_mail_short[] = {KC_M, KC_S, COMBO_END};
// const uint16_t PROGMEM us_combo_mail_short[] = {KC_M, KC_S, COMBO_END};

// const uint16_t PROGMEM combo_mail_long[] = {KC_M, KC_L, COMBO_END};
// const uint16_t PROGMEM us_combo_mail_long[] = {KC_M, KC_L, COMBO_END};


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys
combo_t key_combos[] = {

    [LAYER_ADJUST] = COMBO(combo_adjust, MO(_ADJUST)),
    [LAYER_FN] = COMBO(combo_fn_osl, MO(_FN)),

    // --
    [ENTER_SHIFTED] = COMBO(combo_enter_shifted, S(KC_ENT)),
    [CONTROL_SHIFT] = COMBO(combo_control_shift, C(S(XXXXXXX))),
    [CONTROL_ALT] = COMBO(combo_control_alt, C(A(XXXXXXX))),
    [CONTROL_SHIFT_ALT] = COMBO(combo_control_shift_alt, C(S(A(XXXXXXX)))),
    [RIGHT_ALT] = COMBO(combo_right_alt, KC_RALT),

    // French
    [A_GRAVE] = COMBO(combo_a_grave, CS_AGRAVE),
    [E_GRAVE] = COMBO(combo_e_grave, CS_EGRAVE),
    [U_GRAVE] = COMBO(combo_u_grave, CS_UGRAVE),
    [C_CEDILLA] = COMBO(combo_c_cedilla, CS_CCEDILLA),

    [E_A] = COMBO(combo_ea, CS_AE),
    [E_O] = COMBO(combo_eo, CS_OE),

    [A_CIRCUMFLEX] = COMBO(combo_a_circumflex, CS_ACIRCUMFLEX),
    [E_CIRCUMFLEX] = COMBO(combo_e_circumflex, CS_ECIRCUMFLEX),
    [I_CIRCUMFLEX] = COMBO(combo_i_circumflex, CS_ICIRCUMFLEX),
    [O_CIRCUMFLEX] = COMBO(combo_o_circumflex, CS_OCIRCUMFLEX),
    [U_CIRCUMFLEX] = COMBO(combo_u_circumflex, CS_UCIRCUMFLEX),

    [E_DIAERESIS] = COMBO(combo_e_diaeresis, CS_EDIAERESIS),
    [I_DIAERESIS] = COMBO(combo_i_diaeresis, CS_IDIAERESIS),
    [U_DIAERESIS] = COMBO(combo_u_diaeresis, CS_UDIAERESIS),
    [Y_DIAERESIS] = COMBO(combo_y_diaeresis, CS_YDIAERESIS),

    // --
    [AMPERSAND] = COMBO(combo_ampersand, KC_AMPR),

    [AT] = COMBO(combo_at, KC_AT),
    [BACKSLASH] = COMBO(combo_backslash, KC_BSLS),
    [CIRCUMFLEX] = COMBO(combo_circumflex, KC_CIRC),
    [DOUBLE_QUOTE] = COMBO(combo_double_quote, KC_DQUO),
    [EQUAL] = COMBO(combo_equal, KC_EQL),
    [GRAVE] = COMBO(combo_grave, KC_GRV),
    [HASH] = COMBO(combo_hash, KC_HASH),
    [PERCENT] = COMBO(combo_percent, KC_PERC),
    [PIPE] = COMBO(combo_pipe, KC_PIPE),
    [PLUS] = COMBO(combo_plus, KC_PLUS),
    [SLASH] = COMBO(combo_slash, KC_SLSH),
    [STAR] = COMBO(combo_star, KC_ASTR),
    [TILDE] = COMBO(combo_tilde, KC_TILD),
    [TIRET] = COMBO(combo_tiret, KC_MINS),
    [UNDERSCORE] = COMBO(combo_underscore, KC_UNDS),

    // --
    [DOLLAR] = COMBO(combo_dollar, KC_DLR),
    [EURO] = COMBO(combo_euro, CS_EURO),
    [POUND] = COMBO(combo_pound, CS_POUND),

    // --
    // [MAIL_SHORT] = COMBO_ACTION(combo_mail_short),
    // [MAIL_LONG] = COMBO_ACTION(combo_mail_long),

    // [KC_MAIL_SHORT] = COMBO_ACTION(us_combo_mail_short),
    // [KC_MAIL_LONG] = COMBO_ACTION(us_combo_mail_long),
};


// --------------------------------------------------
// --------------------------------------------------
// Macros !
// Impossible to use the 'sendstring_bepo.h' because of the conversion to us.
// So bepo versions have to be converted from us (see the keymap_bepo.h file to match characters)
// void process_combo_event(uint16_t combo_index, bool pressed) {

  // switch(combo_index) {


  // // switch(combo_index) {
        // // // Apparently, it works with us and bepo :o
    // // case MAIL_SHORT:
      // // if (pressed) {
        // // SEND_STRING("/6od;,sf;.foiv/l");
      // // }
      // // break;

    // // case MAIL_LONG:
      // // if (pressed) {
        // // SEND_STRING("/orlf;j6od;,sf;.foiv/l");
      // // }
      // // break;

    // // // case VIM_COLON:
      // // // if (pressed) {
        // // // SEND_STRING(SS_TAP(X_ESC) SS_LSFT("a") ":" SS_TAP(X_ESC));
      // // // }
      // // // break;

    // // // case VIM_NOH:
      // // // if (pressed) {
        // // // tap_code16(KC_ESC);
        // // // tap_code16(KC_COLN);
        // // // tap_code16(KC_N);
        // // // tap_code16(KC_O);
        // // // tap_code16(KC_H);
        // // // tap_code16(KC_ENTER);
      // // // }
      // // // break;
  // // }
// }

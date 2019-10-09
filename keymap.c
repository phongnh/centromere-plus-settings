#include "centromere_plus.h"

enum centromere_plus_layers {
    _PHONG,
    _V1,
    _V2,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum centromere_plus_keycodes {
    EPRM = SAFE_RANGE,
    LOWER,
    RAISE,
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

#define LWR_SPC LT(_LOWER, KC_SPC)      // Turn on _LOWER layer held, Space when tapped
#define RSE_ENT LT(_RAISE, KC_ENT)      // Turn on _RAISE layer held, Enter when tapped
#define RSE_BSP LT(_RAISE, KC_BSPC)     // Turn on _RAISE layer held, Backspace when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_SCL LCTL_T(KC_SCLN)         // Left Control when held, ; when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, " when tapped
#define SFT_ENT RSFT_T(KC_ENT)          // Right Shift when held, Enter when tapped
#define SFT_BSP RSFT_T(KC_BSPC)         // Right Shift when held, Backspace when tapped
#define SFT_BSL RSFT_T(KC_BSLS)         // Right Shift when held, \ when tapped
#define CAG_PUP LCAG_T(KC_PGUP)         // Ctrl+Alt+Gui when held, Page Up when tapped
#define CAG_PDN LCAG_T(KC_PGDN)         // Ctrl+Alt+Gui when held, Page Down when tapped
#define CAG_LBR LCAG_T(KC_LBRC)         // Ctrl+Alt+Gui when held, [ when tapped
#define CAG_RBR LCAG_T(KC_RBRC)         // Ctrl+Alt+Gui when held, ] when tapped

// Set default layer
#define PHONG DF(_PHONG)            // My default layout - adapt from ErgoDox-EZ
#define V1    DF(_V1)               // Variant 1
#define V2    DF(_V2)               // Variant 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │  Del   │           │   `    │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft/BkSp│
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │  Enter │││││RSE/BkSp│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_PHONG] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,    KC_DEL,   KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    CAG_PUP,  CAG_PDN,  KC_H,     KC_J,     KC_K,     KC_L,     MOU_SCL,  GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,     KC_V,     KC_B,    XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_SLS,  SFT_BSP },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC,  KC_HOME,  KC_SPC,  XXXXXXX,  XXXXXXX,  KC_BSPC,  KC_END,   RSE_ENT,  KC_LALT,  XXXXXXX,  XXXXXXX }
    },


    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   `    │   1    │   2    │   3    │   4    │   5    │   -    │           │   =    │   6    │   7    │   8    │   9    │   0    │ BkSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   [    │           │   ]    │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │  PgUp  │           │  PgDn  │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│ Shift  │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │ Enter  │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_V1] = {
        { KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,      KC_5,    KC_MINS,  KC_EQL,   KC_6,     KC_7,    KC_8,     KC_9,     KC_0,      KC_BSPC },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,    KC_LBRC,  KC_RBRC,  KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,      KC_BSLS },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,    KC_F,      KC_G,    CAG_PUP,  CAG_PDN,  KC_H,     KC_J,    KC_K,     KC_L,     MOU_SCL,   GUI_QUO },
        { KC_LSFT,  CTL_Z,    KC_X,     KC_C,    KC_V,      KC_B,    XXXXXXX,  XXXXXXX,  KC_N,     KC_M,    KC_COMM,  KC_DOT,   CTL_SLS,   KC_RSFT },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC, KC_HOME,   KC_SPC,  XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,  RSE_ENT,  KC_LALT,  XXXXXXX,   XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │  Del   │           │   `    │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │ BkSpace│           │   \    │   Y    │   U    │   I    │   O    │   P    │ BkSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │   [    │           │   ]    │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││  Home  │       │  End   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft / \ │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │ Enter  │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_V2] = {
        { KC_EQL,   KC_1,     KC_2,     KC_3,    KC_4,      KC_5,    KC_DEL,   KC_GRV,   KC_6,     KC_7,    KC_8,     KC_9,     KC_0,      KC_MINS },
        { KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,    KC_BSPC,  KC_BSLS,  KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,      KC_BSPC },
        { CTL_ESC,  KC_A,     KC_S,     KC_D,    KC_F,      KC_G,    CAG_LBR,  CAG_RBR,  KC_H,     KC_J,    KC_K,     KC_L,     MOU_SCL,   GUI_QUO },
        { KC_LCTL,  CTL_Z,    KC_X,     KC_C,    KC_V,      KC_B,    XXXXXXX,  XXXXXXX,  KC_N,     KC_M,    KC_COMM,  KC_DOT,   CTL_SLS,   SFT_BSL },
        { XXXXXXX,  XXXXXXX,  KC_LGUI,  LWR_SPC, KC_HOME,   KC_SPC,  XXXXXXX,  XXXXXXX,  KC_ENT,   KC_END,  RSE_ENT,  KC_LALT,  XXXXXXX,   XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   ~    │   !    │   @    │   #    │   $    │   %    │        │           │        │   ^    │   &    │   *    │   (    │   )    │  Del   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │   `    │   1    │   2    │   3    │   4    │   5    │        │           │        │   6    │   7    │   8    │   9    │   0    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ CAPS   │        │  Left  │ Right  │   Up   │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │  Down  │        │││  PgUp  │       │  PgDn  │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │ LOWER  │││││        │       │  APP   │││││ RAISE  │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_LOWER] = {
        { KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  XXXXXXX,  XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL  },
        { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXXXXXX,  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS },
        { KC_CAPS,  XXXXXXX,  KC_LEFT,  KC_RGHT,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  LOWER,    KC_PGUP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_APP,   KC_PGDN,  RAISE,    XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │  F12   │   F1   │   F2   │   F3   │   F4   │   F5   │        │           │        │   F6   │   F7   │   F8   │   F9   │  F10   │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │   Up   │        │        │        │        │           │        │        │        │   Up   │        │        │   |    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │ Left   │  Down  │  Right │        │        │        │           │        │        │  Left  │  Down  │  Right │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││  PgUp  │       │  PgDn  │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │ LOWER  │││││  MENU  │       │        │││││ RAISE  │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_RAISE] = {
        { KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11  },
        { XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  KC_PIPE },
        { XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  LOWER,    KC_PGUP,  KC_MENU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGDN,  RAISE,    XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │ POWER  │  PHONG │   V1   │   V2   │        │        │  F14   │           │  F15   │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ RESET  │        │        │        │        │        │  F21   │           │  F20   │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │  Vol-  │  Vol+  │  Mute  │        │ AU_OFF │ AG_NORM│           │ AG_SWAP│ AU_ON  │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_ADJUST] = {
        { KC_PWR,   PHONG,    V1,       V2,       XXXXXXX,  XXXXXXX,  KC_F14,   KC_F15,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F21,   KC_F20,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  AU_OFF,   AG_NORM,  AG_SWAP,  AU_ON,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │ MClick │  MS_U  │ RClick │        │        │           │        │        │ RClick │  WH_U  │ MClick │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │ LClick │  MS_L  │  MS_D  │  MS_R  │ LClick │        │           │        │ LClick │  WH_L  │  WH_D  │  WH_R  │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_MOUSE] = {
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  KC_BTN3,  KC_MS_U,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BTN2,  KC_WH_U,  KC_BTN3,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  KC_BTN2,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,  XXXXXXX,  XXXXXXX,  KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
        { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX }
    },

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │           │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬──────┴─┐       ┌─┴──────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    // [_SAMPLE] = {
    //     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
    //     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
    //     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
    //     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX },
    //     { XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX }
    // },

};


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    return;
}

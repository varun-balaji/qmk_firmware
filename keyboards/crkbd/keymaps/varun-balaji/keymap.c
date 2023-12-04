#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
// The base layer is Mac focused miryoku style
#define _L1 1
#define _L2 2
#define _L3 3

// Mod tap
// Caps lock is escape when tapped, control when held
#define ESC_CTL LCTL_T(KC_ESC)
// Left space is backspace when tapped, gui/super/win/command when held
#define BSP_GUI LGUI_T(KC_BSPC)
// Right space is space when tapped, shift when held
#define SPC_SFT LSFT_T(KC_SPC)

// Layer tap
// Left mod key is tab when tapped, layer when held
#define TAB_L1 LT(_L1, KC_TAB)
// Right mod key is enter when tapped, layer when held
#define ENT_L2 LT(_L2, KC_ENT)

// Home row mods on miryoku layer
// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)
// Additional binds for apple layer, swapping Ctrl and Gui
#define CTL_A LCTL_T(KC_A)
#define GUI_D LGUI_T(KC_D)
#define GUI_K RGUI_T(KC_K)
#define CTL_SCL RCTL_T(KC_SCLN)

// Do we even need this?
enum custom_keycodes {
  QWERTY = SAFE_RANGE
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                       KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     // ESC_CTL , GUI_A  , ALT_S  , CTL_D  , SFT_F  ,  KC_G  ,                       KC_H  , SFT_J  , CTL_K  , ALT_L  ,GUI_SCL ,KC_QUOT ,
     ESC_CTL , CTL_A  , ALT_S  , GUI_D  , SFT_F  ,  KC_G  ,                       KC_H  , SFT_J  , GUI_K  , ALT_L  ,CTL_SCL ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                       KC_N  ,  KC_M  ,KC_COMM , KC_DOT ,KC_SLSH ,KC_RSFT ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                          TAB_L1 ,BSP_GUI ,MO(_L3) ,   MO(_L3) ,SPC_SFT , ENT_L2
                                      //└────────┴────────┴────────┘  └────────┴────────┴────────┘

  ),

    [_L1] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                       KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,_______ ,                     KC_LEFT ,KC_DOWN , KC_UP  ,KC_RGHT ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,G(KC_Z) ,G(KC_X) ,G(KC_C) ,G(KC_V) ,_______ ,                     KC_HOME ,KC_PGDN ,KC_PGUP , KC_END ,_______ ,_______ ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         _______ ,_______ ,_______ ,   _______ ,MO(_L3) ,_______
                                      //└────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),

    [_L2] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,KC_UNDS ,KC_PLUS ,KC_LBRC ,KC_RBRC ,                     KC_BTN1 ,KC_BTN2 ,KC_BTN3 ,KC_BTN4 ,KC_SLSH ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_MINS , KC_EQL ,KC_LPRN ,KC_RPRN ,                     KC_MS_L ,KC_MS_D ,KC_MS_U ,KC_MS_R ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_BSLS ,KC_PIPE ,KC_LCBR ,KC_RCBR ,                     KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,_______ ,_______ ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         _______ ,MO(_L3) ,_______ ,   _______ ,_______ ,_______
                                      //└────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),

    [_L3] = LAYOUT_split_3x6_3(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,_______ ,_______ ,_______ ,_______ ,_______ ,                     _______ ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG ,RGB_HUI ,RGB_SAI ,RGB_VAI ,_______ ,_______ ,                     _______ ,  KC_4  ,  KC_5  ,  KC_5  ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD ,RGB_HUD ,RGB_SAD ,RGB_VAD ,_______ ,_______ ,                     _______ ,  KC_1  ,  KC_2  ,  KC_3  ,_______ ,_______ ,
  //└────────┴────────┴────────┴────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         KC_LGUI ,_______ , KC_SPC ,    KC_ENT ,_______ ,KC_RALT
                                      //└────────┴────────┴────────┘  └────────┴────────┴────────┘
  )
};

// Tap repeat hold for homerow keys
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
            return true;
        case ALT_S:
            return true;
        case CTL_D:
            return true;
        case SFT_F:
            return true;
        case GUI_SCL:
            return true;
        default:
            return false;
    }
}

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0 // Slightly modified QUERTY layout
#define _CUSTOM 1 // Neo2 inspired Layout
#define _UMLAUT 2 // German Umlauts
#define _CMD 3    // Command keys (arrows)
#define _RAISE 4
#define _EXTRA 5
#define _ADJUST 16

enum custom_keycodes {
  QUERTZ = SAFE_RANGE,
  CUSTOM,
  UMLAUT,
  CMD,   // Command keys (arrows)
  RAISE, // Numbers and Fn keys
  EXTRA, // Special characters
  ADJUST,// QMK specific keys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Umlaut|  CMD |Extra |Space |Raise | Vol- |  ||> | Vol+ |Ctrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, UMLAUT,  CMD,     EXTRA,   KC_SPC,  RAISE,   KC_VOLD, KC_MPLY, KC_VOLU, KC_RCTL \
),

/* Custom
 * German
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Ü  |   P  |   L  |   W  |   K  |   H  |   G  |   F  |   Q  |   ß  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   Z  |   B  |   M  |   ,  |   .  |   J  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Umlaut|  CMD |Extra |Space |Raise | Vol- |  ||> | Vol+ |Ctrl  |
 * `-----------------------------------------------------------------------------------'

 ISO/keycodes
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   [  |   P  |   L  |   W  |   K  |   H  |   G  |   F  |   Q  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   Y  |   B  |   M  |   ,  |   .  |   J  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Umlaut| CMD  |Extra |Space |Raise | Vol- |  ||> | Vol+ |Ctrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_CUSTOM] = LAYOUT( \
  KC_ESC,  KC_LBRC, KC_P,    KC_L,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_MINS, KC_BSPC, \
  KC_TAB,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_Y,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, UMLAUT,  CMD,     EXTRA,   KC_SPC,  RAISE,   KC_VOLD, KC_MPLY, KC_VOLU, KC_RCTL \
),

/* Umlaut
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  Ä   |   Ü  |  Ö   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |      |      |      |      |      |      |      |Ctrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_UMLAUT] = LAYOUT( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_BSLS, KC_LBRC, KC_SCLN, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL \
),

/* CMD
 * ,-----------------------------------------------------------------------------------.
 * |  ESC | HOME | Bksp |  UP  |  Del | END  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |PG_UP | LEFT | DOWN |RIGHT |PG_DOW|      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * ISO
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |PG_UP | Bksp |  UP  |  Del |PG_DN |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | HOME | LEFT | DOWN |RIGHT | END  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |Enter |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CMD] = LAYOUT( \
  KC_ESC,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
  KC_DEL,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,  KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  \
),

/* Extra (for german)
 * ,-----------------------------------------------------------------------------------.
 * |      |  _   |  [   |   ]  |   ^  |   !  |  <   |   >  |  =   |  &   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  \   |   /  |   {  |   }  |   *  |  ?   |  (   |  )   |  -   |   @  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  #   |   $  |  |   |   ~  |   `  |  +   |  %   |  "   |  '   |  ;   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * Maybe KC_NONUS_BSLASH is needed in some places...
 */
[_EXTRA] = LAYOUT( \
    KC_NO, LSFT(KC_SLSH), RALT(KC_8), RALT(KC_9),    KC_GRV,        LSFT(KC_1),    KC_BSLS,    LSFT(KC_BSLS), LSFT(KC_0),    LSFT(KC_6),      KC_NO,       KC_NO, \
    KC_NO, RALT(KC_MINS), RALT(KC_7), RALT(KC_0),    LSFT(KC_RBRC), LSFT(KC_MINS), LSFT(KC_8), LSFT(KC_9),    KC_SLSH,       LSFT(KC_DOT),    RALT(KC_Q),  KC_NO, \
    KC_NO, KC_BSLS,       LSFT(4),    RALT(KC_BSLS), RALT(KC_RBRC), KC_RBRC,       LSFT(KC_5), LSFT(KC_2),    LSFT(KC_BSLS), LSFT(KC_COMM),   KC_NO,       KC_NO, \
    KC_NO, KC_NO,         KC_NO,      KC_NO,         KC_NO,         KC_NO,         KC_NO,      KC_NO,         KC_NO,         KC_NO,           KC_NO,       KC_NO \
),

/* Adjust (CMD + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|QUERTZ|CUSTOM|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  RESET,    QUERTZ,  CUSTOM,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QUERTZ:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case CUSTOM:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_CUSTOM);
      }
      return false;
      break;
    case CMD:
      if (record->event.pressed) {
        layer_on(_CMD);
        update_tri_layer(_CMD, _RAISE, _ADJUST);
      } else {
        layer_off(_CMD);
        update_tri_layer(_CMD, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_CMD, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_CMD, _RAISE, _ADJUST);
      }
      return false;
      break;
    case EXTRA:
      if (record->event.pressed) {
        layer_on(_EXTRA);
      } else {
        layer_off(_EXTRA);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

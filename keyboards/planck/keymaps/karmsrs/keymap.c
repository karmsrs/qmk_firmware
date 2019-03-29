/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD
};

enum planck_keycodes {
  NUMPAD = SAFE_RANGE,
  RGB_DYN,
  EXT_NUM,
  PRELUDE,
  GAMEOVER,
  TREASURE,
  CLOSE_E,
  MARCH,
  VICTORY
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NUMPAD| Ctrl | Alt  | GUI  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    NUMPAD,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |      |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   (  |   )  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  _______, _______, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LPRN, KC_RPRN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
* ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, _______, _______, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, RGB_DYN,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, PRELUDE, GAMEOVER,
    _______, _______, _______, _______, _______, _______, _______, _______, TREASURE, CLOSE_E, MARCH,   VICTORY
),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |   7  |   8  |   9  |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |   -  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   *  |   /  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |   0  |      |   .  |Enter |Space | Bksp |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9,   XXXXXXX,        XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_PLUS,     KC_KP_MINUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_ASTERISK, KC_KP_SLASH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    EXT_NUM, KC_KP_0, XXXXXXX, KC_KP_DOT, KC_KP_ENTER,    KC_SPC,      KC_BSPC, LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
)

};


#ifdef RGB_MATRIX_H
  rgb_config_t rgb_matrix_config;
  int rgb_dynamic = 0;

  void rgb_layer_gradient(int layer) {
  	int16_t layer_hue;
    int *rgb_layer;
    int array_size;

    /* |----+----+----+----+----+----+----+----+----+----+----+----|
     * |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 |
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | 36 | 37 | 38 | 39 | 40 | 41,42,43| 44 | 45 | 46 | 47 | 48 |
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * Set indices below of led's you want for each layer
     * Note: use 41 and 43 for GRID layout, 42 for MIT.
     * Each Layer case needs to be mapped.
     */

    int RGB_LOWER[] =   {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 
                                 13, 14, 15, 16, 17, 18, 19, 20,         23, 
                                 25, 26, 27, 28, 29, 30,     32, 33, 
                                                             45, 46, 47, 48};

    int RGB_RAISE[] =   {0,  1,  2,  3,  4,  5,  6,  7,  8,          11, 
                                 13, 14, 15, 16, 17, 18, 19, 20,         23, 
                                 25, 26, 27, 28, 29, 30,     32, 33, 
                                                             45, 46, 47, 48};

    int RGB_ADJUST[] =  {    1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 
                                     14, 15, 16, 17, 18, 
                                 25, 26, 27, 28, 29, 30, 31, 32,     34, 35, 
                                                             45, 46, 47, 48};

    int RGB_NUMPAD[] =  {    1,  2,  3,                              11, 
                                 13, 14, 15, 16, 17, 
                                 25, 26, 27, 28, 29, 
                             36, 37,     39, 40, 41, 43, 44, 45, 46, 47, 48};

    int RGB_DEFAULT[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 
                             12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 
                             24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 
                             36, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 48};

  	switch(layer) {
      case _LOWER: 
        array_size = sizeof(RGB_LOWER) / sizeof(RGB_LOWER[0]);
        rgb_layer = RGB_LOWER;
        layer_hue = (rgb_matrix_config.hue - 90) % 360;
        break;
  		case _RAISE:
        array_size = sizeof(RGB_RAISE) / sizeof(RGB_RAISE[0]);
        rgb_layer = RGB_RAISE;
  			layer_hue = (rgb_matrix_config.hue + 90) % 360;
  			break;
  		case _ADJUST:
        array_size = sizeof(RGB_ADJUST) / sizeof(RGB_ADJUST[0]);
        rgb_layer = RGB_ADJUST;
  			layer_hue = (rgb_matrix_config.hue + 180) % 360;
  			break;
  		case _NUMPAD:
        array_size = sizeof(RGB_NUMPAD) / sizeof(RGB_NUMPAD[0]);
        rgb_layer = RGB_NUMPAD;
        layer_hue = (rgb_matrix_config.hue + 225) % 360;
        break;
      case _QWERTY:
  		default:
        array_size = sizeof(RGB_DEFAULT) / sizeof(RGB_DEFAULT[0]);
  			rgb_layer = RGB_DEFAULT;
        layer_hue = rgb_matrix_config.hue;
        break;
  	}

    int16_t h1 = layer_hue;
    int16_t h2 = (layer_hue + 180) % 360;
    int16_t deltaH = h2 - h1;

    // Take the shortest path between hues
    if ( deltaH > 127 )
    {
        deltaH -= 256;
    }
    else if ( deltaH < -127 )
    {
        deltaH += 256;
    }
    // Divide delta by 4, this gives the delta per row
    deltaH /= 4;

    int16_t s1 = rgb_matrix_config.sat;
    int16_t s2 = layer_hue;
    int16_t deltaS = ( s2 - s1 ) / 4;

    HSV hsv = { .h = 0, .s = 255, .v = rgb_matrix_config.val };
    RGB rgb;
    Point point;
    for ( int i=0; i<DRIVER_LED_TOTAL; i++ )
    {
  	  if (i == 42)
  	  {
  		  rgb_matrix_set_color( i, 0, 0, 0 );
  	  } else {
  		  int found = 0;
  		  for ( int j=0; j<array_size; j++)
  		  {
  			  if (rgb_layer[j] == i)
  			  {
  				  found = 1;
  				  break;
  			  }
  		   }

  		  if (found == 1)
  		  {
    			// map_led_to_point( i, &point );
    			point = g_rgb_leds[i].point;
    			// The y range will be 0..64, map this to 0..4
    			uint8_t y = (point.y>>4);
    			// Relies on hue being 8-bit and wrapping
    			hsv.h = layer_hue + ( deltaH * y );
    			hsv.s = rgb_matrix_config.sat + ( deltaS * y );
    			rgb = hsv_to_rgb( hsv );
    			rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    		} else {
    			rgb_matrix_set_color( i, 0, 0, 0 );
    		}
  	  }
    }
  }

  void rgb_matrix_indicators_user(void) {
  	if (rgb_dynamic == 0)
  	{
  		rgb_layer_gradient(biton32(layer_state));
  	}

  	// Disable light in middle of 2U position
      rgb_matrix_set_color(42, 0, 0, 0);
  }
#endif

#ifdef AUDIO_ENABLE
  float comm_song[][2]     = SONG(CLOSE_ENCOUNTERS_5_NOTE);
  float unlock_song[][2]   = SONG(ZELDA_TREASURE);
  float prelude_song[][2]  = SONG(FF_PRELUDE);
  float gameover_song[][2] = SONG(MARIO_GAMEOVER);
  float treasure_song[][2] = SONG(ZELDA_TREASURE);
  float close_e_song[][2]  = SONG(CLOSE_ENCOUNTERS_5_NOTE);
  float march_song[][2]    = SONG(IMPERIAL_MARCH);
  float victory_song[][2]  = SONG(VICTORY_FANFARE_SHORT);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      }
      return false;
      break;
    case EXT_NUM:
      if (record->event.pressed) {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case PRELUDE:
      if (record->event.pressed) {
        PLAY_SONG(prelude_song);
      }
      return false;
      break;
    case GAMEOVER:
      if (record->event.pressed) {
        PLAY_SONG(gameover_song);
      }
      return false;
      break;
    case TREASURE:
      if (record->event.pressed) {
        PLAY_SONG(treasure_song);
      }
      return false;
      break;
    case CLOSE_E:
      if (record->event.pressed) {
        PLAY_SONG(close_e_song);
      }
      return false;
      break;
    case MARCH:
      if (record->event.pressed) {
        PLAY_SONG(march_song);
      }
      return false;
      break;
    case VICTORY:
      if (record->event.pressed) {
        PLAY_SONG(victory_song);
      }
      return false;
      break;
	 case RGB_DYN:
    if (record->event.pressed) {
      rgb_dynamic = 1 - rgb_dynamic;
    }
		return false;
		break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(comm_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(unlock_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

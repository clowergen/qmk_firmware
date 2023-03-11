/*
Copyright 2021 Peter C. Park <peter@stenokeyboards.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "keymap_uk.h"

enum polyglot_layers {
 _STENO_DEFAULT = 0
 ,_QWERTY
 ,_NUMSL
 ,_SYMSL
 ,_FUNCS
};

enum polyglot_keycodes {
  STENO = SAFE_RANGE
 ,QWERTY
 ,NUMSL
 ,SYMSL
 ,FUNCS
 ,CTLESC
 ,SFTSPC
 ,BACK
};

#define STENO LALT_T(KC_NO)
#define QWERTY LT(0, KC_NO)
#define NUMSL MO(_NUMSL)
#define SYMSL LT(_SYMSL, KC_APP)
#define FUNCS MO(_FUNCS)
#define CTLESC LCTL_T(KC_ESC)
#define SFTSPC LSFT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_STENO_DEFAULT] = LAYOUT( // temp and permanent QWERTY
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1, 			 STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_GESC,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2, 			 STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       QWERTY, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_SPC,    			 KC_VOLD, KC_LEFT, KC_DOWN, KC_UP ,KC_RIGHT,  KC_VOLU,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  STN_N1,   STN_A,   STN_O,          		   STN_E,   STN_U, STN_N2
                                       //`--------------------------'  `--------------------------'

   ),

  [_QWERTY] = LAYOUT( //STENO includes LALT
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,                         UK_Y,    UK_U,    UK_I,    UK_O,   UK_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTLESC,    UK_A,    UK_S,    UK_D,    UK_F,    UK_G,                         UK_H,    UK_J,    UK_K,    UK_L, UK_SCLN, UK_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       STENO,    UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,                         UK_N,    UK_M, UK_COMM,  UK_DOT, UK_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LGUI,   NUMSL,  SFTSPC,                       KC_SPC,   SYMSL, KC_ALGR
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMSL] = LAYOUT( //number layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, KC_HOME,   KC_UP,  KC_END, _______,                      KC_PPLS,    UK_7,    UK_8,    UK_9, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_PGUP, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,                      KC_PMNS,    UK_4,    UK_5,    UK_6, _______, UK_HASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_PGDN, _______, KC_VOLD, KC_MPLY, KC_VOLU, KC_MUTE,                      KC_PEQL,    UK_1,    UK_2,    UK_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,                         UK_0,   FUNCS, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMSL] = LAYOUT( //symbol layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      UK_GRV, UK_EXLM, UK_DQUO,  UK_PND,  UK_DLR, UK_PERC,                      UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_CAPS, _______, _______, _______, UK_EURO, _______,                      UK_MINS,  UK_EQL, _______, UK_LBRC, UK_RBRC, UK_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     UK_PIPE, UK_BSLS, _______, _______, _______, _______,                      UK_UNDS, UK_PLUS, _______, UK_LCBR, UK_RCBR, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, XXXXXXX, _______,    		        _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_FUNCS] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______,   KC_F1,   KC_F2,   KC_F3,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,   			_______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->tap.count && record->event.pressed) { //tapped
      	//tap_code(UK_W); //debug
	layer_move(_QWERTY);
      } else if (record->event.pressed) { //held
      	register_code(KC_LCTL);
      	layer_on(_QWERTY);
      } else { // released
      	layer_off(_QWERTY);
      	unregister_code(KC_LCTL);
      }
      return false;
    case STENO:
      if (record->tap.count && record->event.pressed) { //tapped
        layer_move(_STENO_DEFAULT);
        return false;
      }
      break;
  }
  return true;
}

// initialize steno protocol
void keyboard_post_init_user(void)
{
  steno_set_mode(STENO_MODE_GEMINI);
}

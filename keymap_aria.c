/*
Copyright 2016 November Taylor Dickson

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
#include "keymap_common_aria.h"

#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = KEYMAP(\
        ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC  , GRV, \
        TAB , Q, W, E, R, T, Y, U, I, O, P, LBRC,RBRC,BSLASH, DEL, \
        CAPS , A, S, D, F, G, H, J, K, L, SCLN,QUOT,    ENT, PGUP,\
        FN2  , Z, X, C, V, B, N, M, COMM,DOT, SLSH,FN3, UP,PGDN,\
        LCTL,FN0,LALT,    SPC,           RALT,RCTL,LEFT,DOWN,RIGHT \
      ),
      [1] = KEYMAP(\
        FN1, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, TRNS  , TRNS, \
        TRNS , TRNS, MYCM, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS, MUTE, \
        TRNS , TRNS, PSCR, SLCK, PAUS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS,TRNS, VOLU,\
        TRNS  , MPRV, MPLY, MNXT, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, PGUP,VOLD,\
        TRNS,TRNS,LGUI,    TRNS,      RGUI,TRNS,HOME,PGDN,END \
      ),
      [2] = KEYMAP(\
        GRV, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS  , TRNS, \
        TRNS , TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS, TRNS, \
        TRNS , TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS,TRNS, TRNS,\
        TRNS  , TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, TRNS,TRNS,\
        TRNS,TRNS,TRNS,    TRNS,      TRNS,TRNS,TRNS,TRNS,TRNS \
      ),
};

#define ACTION_LEDS_ALL 1

const action_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_FUNCTION(ACTION_LEDS_ALL),
    [2] = ACTION_LAYER_MODS(2, MOD_LSFT),
    [3] = ACTION_LAYER_MODS(2, MOD_LSFT),
};

/* custom action function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_LEDS_ALL:
        if(record->event.pressed) {
          // signal the LED controller thread
          chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
        }
      break;
  }
}
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0; 

enum custom_keycodes {
    UNNAV = SAFE_RANGE,
    UNNUM,
    ALT_TAB,
    ALT_BTAB,
    SW_AP,
    SEL_LINE,
    FN_COLN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { 
    case UNNAV: if (record->event.pressed) {layer_off(NAV);} break;

    case UNNUM: if (record->event.pressed) {layer_off(NUM);} break;

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          unregister_code(KC_LSFT);
          register_code(KC_LALT);
        }
        else if (is_alt_tab_active) {
          register_code(KC_LALT);
          unregister_code(KC_LSFT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
    } break;

    case ALT_BTAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {  
          is_alt_tab_active = true;
          register_code(KC_LALT);
          register_code(KC_LSFT);
        }
        else if (is_alt_tab_active) {
          register_code(KC_LALT);
          register_code(KC_LSFT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
        unregister_code(KC_LSFT);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
    } break;

    case SW_AP:
     if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
        unregister_code(KC_LALT); 
      }
      return false;

    case SEL_LINE:
      if (record->event.pressed) {
        tap_code(KC_HOME);
        register_code(KC_LSFT);
        tap_code(KC_END);
        unregister_code(KC_LSFT);
      } return false;
    
/*    case MAC_DQUO:
      if (record->event.pressed) {
        tap_code(DE_DQUO);
        set_oneshot_layer(LAYER, ONESHOT_START);
      } return false;....................................................*/

    case LT(0,KC_A):
      if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                tap_code16(KC_A);
                return false;
            }
            return true;

    case LT(0,KC_E):
      if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                tap_code16(KC_E);
                return false;
            }
            return true;

    case LT(0,KC_I):
      if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                tap_code16(KC_I);
                return false;
            }
            return true;

    case LT(0,KC_O):
      if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                tap_code16(KC_O);
                return false;
            }
            return true;

    case LT(0,KC_U):
      if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                tap_code16(KC_U);
                return false;
            }
            return true;

    case LT(0,DE_ODIA):
      if (!record->tap.count && record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_3);
                tap_code(KC_KP_3);
                tap_code(KC_KP_7);
                unregister_code(KC_LALT);
                return false;
            }
            return true;

    case LT(0,DE_UDIA):
      if (!record->tap.count && record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_3);
                tap_code(KC_KP_6);
                tap_code(KC_KP_9);
                unregister_code(KC_LALT);
                return false;
            }
            return true;

    case LT(1,S(KC_A)):
      if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_A));
            } else if (record->event.pressed) {
                tap_code16(KC_EQL);
                register_code(KC_LSFT);
                tap_code16(KC_A);
                unregister_code(KC_LSFT);
            }
            return false;

    case LT(1,S(KC_E)):
     if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_E));
            } else if (record->event.pressed) {
                tap_code16(KC_EQL);
                register_code(KC_LSFT);
                tap_code16(KC_E);
                unregister_code(KC_LSFT);
            }
            return false;

    case LT(1,S(KC_I)):
     if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_I));
            } else if (record->event.pressed) {
                tap_code16(KC_EQL);
                register_code(KC_LSFT);
                tap_code16(KC_I);
                unregister_code(KC_LSFT);
            }
            return false;

    case LT(1,S(KC_O)):
     if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_O));
            } else if (record->event.pressed) {
                tap_code16(KC_EQL);
                register_code(KC_LSFT);
                tap_code16(KC_O);
                unregister_code(KC_LSFT);
            }
            return false;

    case LT(1,S(KC_U)):
     if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_U));
            } else if (record->event.pressed) {
                tap_code16(KC_EQL);
                register_code(KC_LSFT);
                tap_code16(KC_U);
                unregister_code(KC_LSFT);
            }
            return false;

    case LT(1,S(DE_ODIA)):
      if (record->tap.count && record->event.pressed) {
                tap_code16(S(DE_ODIA));
            } else if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_3);
                tap_code(KC_KP_3);
                tap_code(KC_KP_6);
                unregister_code(KC_LALT);
            }
            return false;

    case LT(1,S(DE_UDIA)):
      if (record->tap.count && record->event.pressed) {
                tap_code16(S(DE_UDIA));
            } else if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_3);
                tap_code(KC_KP_6);
                tap_code(KC_KP_8);
                unregister_code(KC_LALT);
            }
            return false;

    case LT(0,KC_N):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_N);
            } else if (record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
            }
            return false;

    case LT(0,KC_R):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_R);
            } else if (record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
            }
            return false;

    case LT(0,KC_L):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_L);
            } else if (record->event.pressed) {
                tap_code16(C(KC_T)); // Intercept hold function to send Ctrl-T
            }
            return false;

    case LT(0,KC_X):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_X);
            } else if (record->event.pressed) {
                tap_code16(DE_QUOT); // 
            }
            return false;

    case LT(0,KC_G):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_G);
            } else if (record->event.pressed) {
                tap_code16(KC_Q);
            }
            return false;

    case LT(0,KC_H):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_H);
            } else if (record->event.pressed) {
                tap_code16(S(KC_TAB));
            }
            return false;

    case LT(0,KC_M):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_M);
            } else if (record->event.pressed) {
                tap_code16(KC_TAB);
            }
            return false;

    case LT(1,S(KC_G)):
     if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_G));
            } else if (record->event.pressed) {
                tap_code16(S(KC_Q));
            }
            return false;

    case LT(0,KC_S):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_S);
            } else if (record->event.pressed) {
                tap_code16(DE_SS); 
            }
            return false;

    case LT(0,KC_COMM):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COMM);
            } else if (record->event.pressed) {
                tap_code16(DE_QUES); 
            }
            return false;

    case LT(0,KC_V):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_V);
            } else if (record->event.pressed) {
                tap_code16(DE_EXLM); 
            }
            return false;

    case LT(1,C(KC_PGDN)): //fett
     if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_PGDN));
            } else if (record->event.pressed) {
                tap_code16(C(S(KC_F)));
            }
            return false;

    case LT(1,KC_NO): //kurisv
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_NO);
            } else if (record->event.pressed) {
                tap_code16(C(S(KC_K)));
            }
            return false;

    case LT(1,KC_F5): //underline
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F5);
            } else if (record->event.pressed) {
                tap_code16(C(S(KC_U)));
            }
            return false;

    case LT(1,KC_3):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_3);
            } else if (record->event.pressed) {
                tap_code16(DE_COMM);
            }
            return false;

    case LT(0,KC_J):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_J);
            } else if (record->event.pressed) {
                tap_code16(QK_BOOT);
            }
            return false;

    case LT(1,KC_HOME):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PGUP);
            } else if (record->event.pressed) {
                tap_code16(KC_HOME);
            }
            return false;

    case LT(1,KC_END):
     if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PGDN);
            } else if (record->event.pressed) {
                tap_code16(KC_END);
            }
            return false;

    case LT(1,FN_STREAM):
     if (record->tap.count && record->event.pressed) {
                tap_code16(FN_STREAM);
            } else if (record->event.pressed) {
                tap_code16(FN_PROJECT);
            }
            return false;

    case LT(1,FN_FFXTAB):
     if (record->tap.count && record->event.pressed) {
                tap_code16(FN_FFXTAB);
            } else if (record->event.pressed) {
                tap_code16(FN_FFRECOV);
            }
            return false;

    case FN_COLN:
     if (record->event.pressed) {
                tap_code16(DE_COLN);
                tap_code16(KC_SPACE);
                set_oneshot_layer(SHIF, ONESHOT_START);
            } 
            return false;



  }
  return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
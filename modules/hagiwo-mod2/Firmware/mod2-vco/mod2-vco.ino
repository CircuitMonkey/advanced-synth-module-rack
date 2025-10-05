/*
  An ASMR implementation of the Hagiwo MOD2 synth module.
  by Mark J Koch (CircuitMonkey at Github)
  October 2025
  GitHub: https://github.com/CircuitMonkey/advanced-synth-module-rack/tree/main/modules/hagiwo-mod2

  Arduino "Raspberry Pi Pico 2" board type.

  Added:
      -OLED Display to show mode and frequency
      -Two navigation buttons.

  To be implemented:
      - MIDI from backplane
      - Slot identification
      - I2C basic ASMR functions.

  ## LICENSE ####################################################
  CC0 1.0 Universal (CC0 1.0) Public Domain Dedication
  You can copy, modify, distribute and perform the work, even 
  for commercial purposes, all without asking permission.
  ###############################################################

*/
#include "hagiwo-vco.h"
#include "oled.h"

HagiwoVCO hagiwoVCO;
OLED oled;

#define NAV_BTN_UP 14
#define NAV_BTN_DN 15

int loopCount = 0;

void setup() {
  pinMode(NAV_BTN_UP, INPUT_PULLUP);  // Navigate up
  pinMode(NAV_BTN_DN, INPUT_PULLUP);  // Navigate down

  hagiwoVCO.begin();
  oled.begin();
  oledUI_hagiwoSplash();
  oled.display.display();
}

void loop() {
  hagiwoVCO.loop();
  oled.loop();
  if (loopCount == 0) {
    oledUI_freqDisplay(hagiwoVCO.waveSel, hagiwoVCO.freq);
    oled.display.display();
    loopCount++;
  } else {
    loopCount++;
    if (loopCount > 3000) loopCount = 0;
  }
}

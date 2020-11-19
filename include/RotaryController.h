/**
 * @file RotaryController.h
 * @class RotaryController
 *
 * @defgroup   ROTARYCONTROLLER Rotary Controller
 *
 * @brief       The Controller for the Rotary Encoder.
 *
 * @author     Manuel Braun
 * @date       2020-10-14
 *
 * @version 1.0.3
 *
 * @copyright Copyright (c) 2020 - Manuel Braun & HappyShooting Community
 */

#pragma once
#define Schwurbler_DEF_RotaryEncoderController_Active
#include <SchwurblerController.h> // Definitionsheader
#include <Encoder.h>

#ifndef ARDUINO
#include "Arduino.h" // Arduino Header
#endif // ARDUINO
// typedef struct RotaryEncoder SchwurblerRotaryEncoder;

/**
 * Definiton of Callback Value Change Callback
 * @param int MidiKey to be sent to
 * @param byte MidiValue
 */
typedef void (*MidiValueChangeCallbackHandler)(int, byte);

/**
 * Class manages RotaryController
 * After construct needs to be configured with Informations about
 * which Pin to Listen and where to send. SendsMidi Events on getData
 * triggered if status changed
 */
class RotaryController {
 public:
  /**
   * RotaryController constructor
   * @warning Not yet completed
   * @attention You shall not use this by now
   */
  RotaryController() {
    for (int i = 0; i <= Schwurbler_DEF_RotaryEncoderController_Amount; i++) {
      this->rotaryPositionStore[i] = -999;
      this->rotaryEncoder[i] = new Encoder(this->getPin(i), this->getPin2(i));
    };
  }

  ~RotaryController() {}

 private:
  const uint8_t kAmount = Schwurbler_DEF_RotaryEncoderController_Amount;
  const int pins[Schwurbler_DEF_RotaryEncoderController_Amount] = Schwurbler_DEF_RotaryEncoderController_Pins;
  const int pins2[Schwurbler_DEF_RotaryEncoderController_Amount] = Schwurbler_DEF_RotaryEncoderController_Pins2;
  const int midiKeys[Schwurbler_DEF_RotaryEncoderController_Amount] = Schwurbler_DEF_RotaryEncoderController_Keys;
  int rotaryPositionStore[Schwurbler_DEF_RotaryEncoderController_Amount];
  Encoder *rotaryEncoder[Schwurbler_DEF_RotaryEncoderController_Amount];
  MidiValueChangeCallbackHandler midiValueChangeCallback;

 public:
  /**
   * Returns Buttons amount of controller
   */
  int getAmount();

  /**
   * Returns the Pin matching to Button
   * @param identifier Identfies a button
   */
  int getPin(int identifier);

  /**
   * Returns the Pin matching to Button
   * @param identifier Identfies a button
   */
  int getPin2(int identifier);

  /**
   * Sets the callbackfunction to be called while getData
   * @param _midiValueChangeCallback
   * void *(int MidiKey, byte Midivalue);
   * pointer to a function
   */
  void handleMidiValueChangeCallback(MidiValueChangeCallbackHandler _midiValueChangeCallback);

  /**
   * Itterates over all buttons and checks for status changes.
   * uses callback function change
   */
  void getData();
};

/**
 * @file ButtonController.h
 * @class ButtonController
 *
 * @defgroup   BUTTONCONTROLLER Button Controller
 *
 * @brief       The Controller for the Buttons.
 *
 * @author     Manuel Braun
 * @date       2020-10-14
 *
 * @version 1.0.3
 *
 * @copyright Copyright (c) 2020 - Manuel Braun & HappyShooting Community
 */

#pragma once
#include <SchwurblerController.h> // Definitionsheader
#include <Bounce2.h>  // Dependent library header

#ifndef ARDUINO
#include "Arduino.h" // Arduino Header
#endif // ARDUINO

// typedef struct Bounce SchwurblerButton;

/**
 * Definiton of Callback Midi Trigger Callback
 * \param[int] MidiKey to be sent to
 * \param[bool] Trigger active or stop
 */
typedef void (*MidiTriggerCallbackHandler)(int, bool);

/**
 * Class manages Pushbuttons
 * After construct needs to be configured with Informations about
 * which Pin to Listen and where to send. SendsMidi Events on getData
 * triggered if status changed
 */

class ButtonController {
 public:
  /**
   * Buttoncontroller constructor
   * @param amount amount of Buttons the controller should be able to handle
   * @param pinList List of pin numbers matches Button by Button e.g. {1, 2, 3}
   * @param midiValueList List of Midivalues matches Button by Button e.g. {21,
   * 22, 23} Hint on Buttonmapping:
   * First Entry of pinList will be matched to first entry of
   * midiValueList etc.
   *
   * Based on pinlist a debounced Array will be created in button
   */

  ButtonController() {
    for (int i = 0; i <= kAmount; i++) {
      this->buttons[i] = Bounce(this->pins[i], this->kBounceTime);
    }
  }

  ~ButtonController() {
    #ifndef Schwurbler_DEF_ButtonController_Pins
    delete[] this->pins;
    #endif // Schwurbler_DEF_ButtonController_Pins
    #ifndef Schwurbler_DEF_ButtonController_Keys
    delete[] this->midiKeys;
    #endif // Schwurbler_DEF_ButtonController_Keys
  }

 private:
  const uint8_t kAmount = Schwurbler_DEF_ButtonController_Amount;
  const int pins[Schwurbler_DEF_ButtonController_Amount] = Schwurbler_DEF_ButtonController_Pins;
  const int midiKeys[Schwurbler_DEF_ButtonController_Amount] = Schwurbler_DEF_ButtonController_Keys;
  Bounce buttons[Schwurbler_DEF_ButtonController_Amount];
  MidiTriggerCallbackHandler midiTriggerCallback;
  const uint8_t kBounceTime = Schwurbler_DEF_ButtonController_BounceTime;

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
   * Sets the callbackfunction to be called while getData
   * \param midiTriggerCallback
   * void *(int inControlNumber, bool isActive)
   * pointer to a function
   */
  void handleMidiTriggerCallback(
      MidiTriggerCallbackHandler midiTriggerCallback);

  /**
   * Itterates over all buttons and checks for status changes.
   * uses callback function change
   */
  void getData();
};

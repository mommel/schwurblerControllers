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
#include <ResponsiveAnalogRead.h>  // Dependent library header

#ifndef ARDUINO
#include "Arduino.h" // Arduino Header
#endif // ARDUINO
// typedef struct ResponsiveAnalogRead SchwurblerPoti;

/**
 * Definiton of Callback Value Change Callback
 * @param int MidiKey to be sent to
 * @param byte MidiValue
 */
typedef void (*MidiValueChangeCallbackHandler)(int, byte);

/**
 * Class manages PotiController
 * After construct needs to be configured with Informations about
 * which Pin to Listen and where to send. SendsMidi Events on getData
 * triggered if status changed
 */
class PotiController {
 public:
  // PotiController constructor
  // Creates for each poti ResponsiveAnalogRead on matching pin.
  PotiController() {
    for (int i = 0; i <= Schwurbler_DEF_PotiController_Amount; i++) {
      this->potis[i]=ResponsiveAnalogRead(this->pins[i], true);
      this->potiValueStore[i] = 0;
      this->potiValueLagStore[i] = 0;
    }
  }

  ~PotiController() {
    #ifndef Schwurbler_DEF_PotiController_Pins
    delete[] this->pins;
    #endif // Schwurbler_DEF_PotiController_Pins
    #ifndef Schwurbler_DEF_PotiController_Keys
    delete[] this->midiKeys;
    #endif // Schwurbler_DEF_PotiController_Keys
  }

 private:
  // The amount of Potis handled by the controller
  const uint8_t kAmount = Schwurbler_DEF_PotiController_Amount;
  // Constant Array holding all Potis pins 1o1 match
  const int pins[Schwurbler_DEF_PotiController_Amount] = Schwurbler_DEF_PotiController_Pins;
  // Constant Array holding all Potis midiKeys 1o1 match
  const int midiKeys[Schwurbler_DEF_PotiController_Amount] = Schwurbler_DEF_PotiController_Keys;
  // Array holding all Potis last value
  byte potiValueStore[Schwurbler_DEF_PotiController_Amount];
  // Array holding all Potis lag value
  byte potiValueLagStore[Schwurbler_DEF_PotiController_Amount];
  // Array holding all Potis pins through a ResponsiveAnalogRead
  ResponsiveAnalogRead potis[Schwurbler_DEF_PotiController_Amount];
  // Callback Handler will be called on midi value changes
  MidiValueChangeCallbackHandler midiValueChangeCallback;

  // Private function to write a poti's value into store
  // @param identifier int representing the poti's id
  // @param value int representing the poti's value
  void setPotiValueStore(int identifier, int value);
  // Private function to get a poti's value from store
  // @param identifier int representing the poti's id
  int getPotiValueStore(int identifier);
  // Private function to write a poti's lag value into store
  // @param identifier int representing the poti's id
  // @param value int representing the poti's value
  void setPotiLagStore(int identifier, int value);
  // Private function to get a poti's lag value from store
  // @param identifier int representing the poti's id
  int getPotiLagStore(int identifier);

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
   * @param _midiValueChangeCallback
   * void *(int MidiKey, byte Midivalue);
   * pointer to a function
   */
  void handleMidiValueChangeCallback(
      MidiValueChangeCallbackHandler _midiValueChangeCallback);

  /**
   * Itterates over all buttons and checks for status changes.
   * uses callback function change
   */
  void getData();
};

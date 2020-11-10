/**
  * @package SchwurblerControllers
  * 
  * @file ButtonController.h
  *
  * @version 1.0.0 - Nov 05 2020
  *
  * @brief Handles all about the Pushbuttons
  *
  * @author Manuel Braun
  * Contact: github.com/mommel
  *
  * @copyright Manuel Braun & HappyShooting Community 
  *  
  * @section DESCRIPTION
  * 
  * Der Schwurbler
  *
  * This product includes software developed by the
  * HappyShooting Community (http://happyshooting.de/).
  *
  * @section LICENSE
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the (CC BY-NC-SA 4 0)
  * Creative Commons Attribution-NonCommercial-ShareAlike 4 0 International
  * as published by Creative Commons Corporation; either version 4 of the
  * License, or (at your option) any later version
  *
  * @section DISCLAIMER
  * 
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT IN
  * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
  * USE OR OTHER DEALINGS IN THE SOFTWARE
  *
  */

#pragma once
#ifndef SCHWURBLER_CONTROLLERS_BUTTONCONTROLLER_H_
#define SCHWURBLER_CONTROLLERS_BUTTONCONTROLLER_H_
#include <SchwurblerController.h> // Definitionsheader
#include <Bounce2.h>  // Dependent library header

#ifndef ARDUINO
#include "Arduino.h" // Arduino Header
#endif // ARDUINO
// typedef struct Bounce SchwurblerButton;

/*
 * Definiton of Callback Midi Trigger Callback
 * @param[int] MidiKey to be sent to
 * @param[bool] Trigger active or stop
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
  /* 
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
   * @param midiTriggerCallback
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

#endif  // SCHWURBLER_CONTROLLERS_BUTTONCONTROLLER_H_

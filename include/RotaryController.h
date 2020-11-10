/**
  * @package SchwurblerControllers
  * 
  * @file RotaryEncoder.h
  *
  * @version 1.0.0 - Nov 05 2020
  *
  * @brief Handles all about the Rotary Encoder
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
#define Schwurbler_DEF_RotaryEncoderController_Active
#ifndef SCHWURBLERCONTROLLERS_ROTARYCONTROLLER_H_
#define SCHWURBLERCONTROLLERS_ROTARYCONTROLLER_H_
#include <SchwurblerController.h> // Definitionsheader
#include <RotaryEncoder.h>  // Dependent library header

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
   * @param amount amount of Buttons the controller should be able to handle
   * @param pinList List of pin numbers matches Button by Button e.g. {1, 2, 3}
   * @param midiValueList List of Midivalues matches Button by Button e.g. {21,
   * 22, 23} Hint on Buttonmapping:
   * First Entry of pinList will be matched to first entry of
   * midiValueList etc.
   *
   */
  RotaryController() { 
      for (int i = 0; i <= Schwurbler_DEF_RotaryEncoderController_Amount / 2; i++) {
       
      }
   }

  ~RotaryController() {}

 private:
  const uint8_t kAmount = Schwurbler_DEF_RotaryEncoderController_Amount;
  const int pins[Schwurbler_DEF_RotaryEncoderController_Amount] = Schwurbler_DEF_RotaryEncoderController_Pins;
  const int midiKeys[Schwurbler_DEF_RotaryEncoderController_Amount] = Schwurbler_DEF_RotaryEncoderController_Keys;
  // RotaryEncoder rotaryEncoder[Schwurbler_DEF_RotaryEncoderController_Amount];
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
   * Sets the callbackfunction to be called while getData
   * @param midiTriggerCallback
   * void *(int MidiKey, byte Midivalue);
   * pointer to a function
   */
  void handleMidiValueChangeCallback(MidiValueChangeCallbackHandler midiValueChangeCallback);

  /**
   * Itterates over all buttons and checks for status changes.
   * uses callback function change
   */
  void getData();
};
#endif  // SCHWURBLERCONTROLLERS_ROTARYCONTROLLER_H_

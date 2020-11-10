/**
 * SchwurblerControllers
 * Example: ControlPoti
 * Date:    Nov 05 2020
 * Name:    Manuel Braun
 * Email:   mommel@gmx de
 * 
 * This product includes software developed by the
 * HappyShooting Community (http://happyshooting.de/).
 *
 * LICENSE
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the (CC BY-NC-SA 4 0)
 * Creative Commons Attribution-NonCommercial-ShareAlike 4 0 International
 * as published by Creative Commons Corporation; either version 4 of the
 * License, or (at your option) any later version
 *
 * DISCLAIMER
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE
 *
 * @file ControlPoti.ino/.cpp
 *
 * @brief Example to Control Buttons
 *
 * @author Manuel Braun
 * Contact: github.com/mommel
 */
#include "ControlPoti.h"

// Lets have a pointable uninitialized pointer for our Buttoncontroller
// we eill use it later to create and interact with the buttons
// @see PotiController
PotiController* potiController;

// This MIDI_CREATE_INSTANCE createds an instance of usbMIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

// Having a Midichannel defined as constant is the way to to go as we are using
// them in the Midi and Controller functions
const int kMidiChannel = 7;

// The implementation of the Midi send function fom usbMidi that will be linked
// as callback to the controller
// @param int inControlNumber describes the Midi Key to send
// @param byte controllerValue secribes the value to be send
void sendMidiValueChange(int inControlNumber, byte controllerValue) {
  usbMIDI.sendControlChange(inControlNumber, controllerValue, kMidiChannel);
}

void setup() {
  // As normal when communicating with Midi we have to define the
  // MidiChannel we want to speak with
  MIDI.begin(kMidiChannel);
  // As we don't have a Midi Thru we turn it off
  MIDI.turnThruOff();

  // Inside the setup loop we need to initialize an instance
  // PotiController needs to know the amount of buttons to be
  // initialized as first param, as second param an int list matching the
  // midi Keys and an int list matching the pins they are connected to
  // the midi keys will be matched 1:1 to the pins respecting the order in
  // the list
  potiController = new PotiController(3,
    {A9, A8, A7}, {21, 22, 23});

  // As last part of the setup we need to invoke the SendMidi funtion
  // as callback into the controller
  potiController->handleMidiValueChangeCallback(&sendMidiValueChange);
}

void loop() {
  // In the loop we just need to run getData on the controller
  // The rest is done by the Controller
  potiController->getData();

  // We need to read usbMidi otherwise its going crazy
  while (usbMIDI.read()) {
  }  // ignore incoming messages
}

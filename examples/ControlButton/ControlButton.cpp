/**
 * SchwurblerControllers
 * Example: ControlButton
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
 * @file ControlButton.ino/.cpp
 *
 * @brief Example to Control Buttons
 *
 * @author Manuel Braun
 * Contact: github.com/mommel
 */
#include <ControlButton.h>

// Lets have a pointable uninitialized pointer for our Buttoncontroller
// we eill use it later to create and interact with the buttons
// @see ButtonController 
// e.g. ButtonController* buttonController;
// If the define configurations will be used the Controller can be initialized directly
ButtonController *buttonController = new ButtonController;

// This MIDI_CREATE_INSTANCE createds an instance of usbMIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

// Having the values for the velocity the midi event will trigger on button push
// and the Midichannel defined as constant is the way to to go as we are using
// them in the Midi and Controller functions
const int kOnVelocity = Schwurbler_DEF_ButtonController_TriggerVelocity;
const int kMidiChannel = Schwurbler_DEF_SendTo_MidiChannel;

// The implementation of the Midi send function fom usbMidi that will be linked
// as callback to the controller
// @param int inControlNumber describes the Midi Key to send
// @param bool isActive desctibes if it's the push or release event
void sendMidiTrigger(int inControlNumber, bool isActive) {
  if (isActive) {
    usbMIDI.sendNoteOn(inControlNumber, kOnVelocity, kMidiChannel);
  } else {
    usbMIDI.sendNoteOff(inControlNumber, 0, kMidiChannel);
  }
  if (isActive) {
    Serial.println((String) "Function sendMidiTrigger called with " +
                   inControlNumber + " ACTIVE");
  } else {
    Serial.println((String) "Function sendMidiTrigger called with " +
                   inControlNumber + " INACTIVE");
  }
}

void setup() {
  // As normal when communicating with Midi we have to define the
  // MidiChannel we want to speak with
  MIDI.begin(kMidiChannel);
  // As we don't have a Midi Thru we turn it off
  MIDI.turnThruOff();

 if (!Serial) {
    Serial.begin(57600);
  }

  // Inside the setup loop we need to initialize an instance
  // ButtonController needs to know the amount of buttons to be
  // initialized as first param, as second param an int list matching the
  // midi Keys and an int list matching the pins they are connected to
  // the midi keys will be matched 1:1 to the pins respecting the order in
  // the list
  // buttonController = new ButtonController(3,
  //   {0, 1, 2},
  //   {1, 2, 3});

  // As the Buttoncontoller are all digitalpins we need to set them to
  // INPUT, better INPUT_PULLUP
  for (int controllerID = 0; controllerID < buttonController->getAmount();
       controllerID++) {
    pinMode(buttonController->getPin(controllerID), INPUT_PULLUP);
  }

  // As last part of the setup we need to invoke the SendMidi funtion
  // as callback into the controller
  buttonController->handleMidiTriggerCallback(&sendMidiTrigger);
}

void loop() {
  // In the loop we just need to run getData on the controller
  // The rest is done by the Controller
  buttonController->getData();

  // We need to read usbMidi otherwise its going crazy
  while (usbMIDI.read()) {
  }  // ignore incoming messages
}

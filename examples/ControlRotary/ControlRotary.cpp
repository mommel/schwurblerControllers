/**
  * Version: Schwurbler - RotaryController                                     *
  * Date:    Oct 14 2020                                                       *
  * Name:    Manuel Braun                                                      *
  *                                                                            *
  * @file RotaryController.cpp
  *
  * @class RotaryController
  */

#include "ControlRotary.h"

// Lets have a pointable uninitialized pointer for our RotaryController
// we will use it later to create and interact with the buttons
// \see RotaryController
RotaryController* rotaryController = new RotaryController();

// This MIDI_CREATE_INSTANCE createds an instance of usbMIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

// Having a Midichannel defined as constant is the way to to go as we are using
// them in the Midi and Controller functions
const int kMidiChannel = 7;

/**
 * @param inControlNumber 
 * @param controllerValue 
 * @return * The 
 * as callback to the controller
 * @param int inControlNumber describes the Midi Key to send
 * @param byte controllerValue secribes the value to be send
 */
void sendMidiValueChange(int inControlNumber, byte controllerValue) {
  usbMIDI.sendControlChange(inControlNumber, controllerValue, kMidiChannel);
}

void setup() {
  // As normal when communicating with Midi we have to define the
  // MidiChannel we want to speak with
  MIDI.begin(kMidiChannel);
  // As we don't have a Midi Thru we turn it off
  MIDI.turnThruOff();

  // As the RotaryController are all digitalpins we need to set them to
  // INPUT, better INPUT_PULLUP
  for (int controllerID = 0; controllerID < rotaryController->getAmount();
       controllerID++) {
    pinMode(rotaryController->getPin(controllerID), INPUT_PULLUP);
  }

  // As last part of the setup we need to invoke the SendMidi funtion
  // as callback into the controller
  rotaryController->handleMidiValueChangeCallback(&sendMidiValueChange);
}

void loop() {
  // In the loop we just need to run getData on the controller
  // The rest is done by the Controller
  rotaryController->getData();

  // We need to read usbMidi otherwise its going crazy
  while (usbMIDI.read()) {
  }  // ignore incoming messages
}

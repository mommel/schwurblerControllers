/**
  * Version: Schwurbler - PotiController                                     *
  * Date:    Oct 14 2020                                                       *
  * Name:    Manuel Braun                                                      *
  *
  * @file PotiController.cpp
  *
  * @class PotiController
  */

#include "ControlPoti.h"

/**
 * we eill use it later to create and interact with the buttons
 * @see PotiController
 */
PotiController* potiController = new PotiController();

// This MIDI_CREATE_INSTANCE createds an instance of usbMIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

// Having a Midichannel defined as constant is the way to to go as we are using
// them in the Midi and Controller functions
const int kMidiChannel = Schwurbler_DEF_SendTo_MidiChannel;

/** The implementation of the Midi send function fom usbMidi that will be linked
  * as callback to the controller
  * @param inControlNumber int describes the Midi Key to send
  * @param controllerValue byte secribes the value to be send
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

  if (!Serial) {
    Serial.begin(57600);
  }

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

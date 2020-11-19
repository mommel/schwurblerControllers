/**                                                                           *
  * Version: Schwurbler - ButtonController                                     *
  * Date:    Oct 14 2020                                                       *
  * Name:    Manuel Braun                                                      *
  *                                                                            *
  * @file ButtonController.cpp
  *
  * @class ButtonController
  */

#include "ControlButton.h"

/**
 * we eill use it later to create and interact with the buttons
 * @see ButtonController
 * e.g. ButtonController* buttonController;
 * If the define configurations will be used the Controller can be initialized directly
 */
ButtonController *buttonController = new ButtonController;

// This MIDI_CREATE_INSTANCE createds an instance of usbMIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

// Having the values for the velocity the midi event will trigger on button push
// and the Midichannel defined as constant is the way to to go as we are using
// them in the Midi and Controller functions
const int kOnVelocity = Schwurbler_DEF_ButtonController_TriggerVelocity;
const int kMidiChannel = Schwurbler_DEF_SendTo_MidiChannel;

/**
 * as callback to the controller
 * @param inControlNumber int describes the Midi Key to send
 * @param isActive bool desctibes if it's the push or release event
 */
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

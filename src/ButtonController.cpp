/**
 * Version: Schwurbler - ButtonController                                     *
 * Date:    Oct 14 2020                                                       *
 * Name:    Manuel Braun                                                      *
 *
 * @file ButtonController.cpp
 *
 * @class ButtonController
 */

#include "ButtonController.h"

int ButtonController::getAmount() {
  return this->kAmount;
}

int ButtonController::getPin(int identifier) {
  return this->pins[identifier];
}

void ButtonController::handleMidiTriggerCallback(
    MidiTriggerCallbackHandler midiTriggerCallback) {
  this->midiTriggerCallback = midiTriggerCallback;
}

void ButtonController::getData() {
  for (int buttonIdentifier = 0; buttonIdentifier < this->kAmount;
       buttonIdentifier++) {
      this->buttons[buttonIdentifier].update();
      if (this->buttons[buttonIdentifier].fallingEdge() ||
          this->buttons[buttonIdentifier].risingEdge()) {

        int midiValue = this->midiKeys[buttonIdentifier];

        bool is_active = (this->buttons[buttonIdentifier].fallingEdge() &&
                          !this->buttons[buttonIdentifier].risingEdge());
        Serial.println("callback");
        this->midiTriggerCallback(midiValue, is_active);
      }
  }
}

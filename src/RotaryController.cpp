/**                                                                          *
 * Version: Schwurbler - RotaryController                                       *
 * Date:    Oct 14 2020                                                       *
 * Name:    Manuel Braun                                                      *
 *
 * @file RotaryController.cpp
 *
 * @class RotaryController
 */

#include "RotaryController.h"

int RotaryController::getAmount() {
  return this->kAmount;
}

int RotaryController::getPin(int identifier) {
  return this->pins[identifier];
}

int RotaryController::getPin2(int identifier) {
  return this->pins2[identifier];
}

void RotaryController::handleMidiValueChangeCallback(
    MidiValueChangeCallbackHandler _midiValueChangeCallback) {
  this->midiValueChangeCallback = _midiValueChangeCallback;
}

void RotaryController::getData() {
  for (int rotaryIdentifier = 0; rotaryIdentifier < this->kAmount;
       rotaryIdentifier++) {
         Encoder interimEnc = *(this->rotaryEncoder)[rotaryIdentifier];
    long newPos = interimEnc.read();
    if (newPos != this->rotaryPositionStore[rotaryIdentifier]) {
      this->rotaryPositionStore[rotaryIdentifier] = newPos;
      this->midiValueChangeCallback(this->midiKeys[rotaryIdentifier], newPos);
    }
  }
}


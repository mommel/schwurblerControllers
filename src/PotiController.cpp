/**                                                                          *
 * Version: Schwurbler - PotiController                                       *
 * Date:    Oct 14 2020                                                       *
 * Name:    Manuel Braun                                                      *
 *
 * @file PotiController.cpp
 *
 * @class PotiController
 */

#include "PotiController.h"

void PotiController::setPotiValueStore(int identifier, int value) {
  this->potiValueStore[ identifier ] = value;
}

int PotiController::getPotiValueStore(int identifier) {
  return this->potiValueStore[ identifier ];
}

void PotiController::setPotiLagStore(int identifier, int value) {
  this->potiValueLagStore[ identifier ] = value;
}

int PotiController::getPotiLagStore(int identifier) {
  return this->potiValueLagStore[ identifier ];
}

int PotiController::getAmount() {
  return this->kAmount;
}

int PotiController::getPin(int identifier) {
  return this->pins[identifier];
}

void PotiController::handleMidiValueChangeCallback(
    MidiValueChangeCallbackHandler _midiValueChangeCallback) {
  this->midiValueChangeCallback = _midiValueChangeCallback;
}

void PotiController::getData() {
  for (int potiIdentifier = 0; potiIdentifier < this->kAmount;
       potiIdentifier++) {
    this->potis[potiIdentifier].update();
    if (this->potis[potiIdentifier].hasChanged()) {
      int activePotiValue = this->potis[potiIdentifier].getValue() >> 3;
      this->setPotiValueStore(potiIdentifier, activePotiValue);

      if (activePotiValue != this->getPotiLagStore(potiIdentifier)) {
        this->setPotiLagStore(potiIdentifier, activePotiValue);
        this->midiValueChangeCallback(this->midiKeys[potiIdentifier],
          activePotiValue);
      }
    }
  }
}

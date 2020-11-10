/**
  * @package SchwurblerControllers
  * 
  * @file PotiController.cpp‚‚‚
  *
  * @version 1.0.0 - Nov 05 2020
  *
  * @brief Handles all about the Potentiometers
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
  *
  ******************************************************************************
  *            :+==+                                           -:              *
  *       -+#=+-  -=-    -*                             -@:   +W+              *
  *    -=#+-     -=-     =*         =:                 -@:   =*@-              *
  *  -#*-               -#:   :*    =--:               +#  -#-*#               *
  * -#:           :=@#=+:@+#= =*=@--= #+ ++     *W@#*++#==*@- =* *@: -=W@#*++*-*
  *  :=====**+::=*-+#:==+W* =-*@+-@#: #==-*#+*=**@-    :-:W=  #+-@===:*@-      *
  *          :#::#-     :=   -                  --      :W*   #:      --       *
  *        -=+ -=+                                            -:               *
  *       -=-+#+                                                               *
  *        --                                                                  *
  ******************************************************************************
  *                                                                            *
  * Version: Schwurbler - PotiController                                     *
  * Date:    Oct 14 2020                                                       *
  * Name:    Manuel Braun                                                      *
  * Email:   mommel@gmx de                                                     *
  *                                                                            *
  ******************************************************************************
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

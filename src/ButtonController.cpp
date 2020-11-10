/**
  * @package SchwurblerControllers
  * 
  * @file ButtonController.cpp
  *
  * @version 1.0.0 - Nov 05 2020
  *
  * @brief Handles all about the Pushbuttons
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
  * Version: Schwurbler - Buttoncontroller                                     *
  * Date:    Oct 14 2020                                                       *
  * Name:    Manuel Braun                                                      *
  * Email:   mommel@gmx de                                                     *
  *                                                                            *
  ******************************************************************************
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

/**
 *! @file ButtonController.h
 *! @author Manuel Braun (mommel.devOgmail.com)
 *! @brief Example how to use Buttons
 *! @version 1.0.3
 *! @date 2020-10-14
 *
 *! @copyright Copyright (c) 2020 - Manuel Braun & HappyShooting Community
 *
 *! @class ButtonController
 */

#ifndef __CONTROLBUTTON_H__
#define __CONTROLBUTTON_H__

#ifndef ARDUINO
#include "Arduino.h"
#endif  // ARDUINO

#include <ButtonController.h>
#include <SchwurblerController.h>
#include <MIDI.h>

void sendMidiTrigger(int inControlNumber, bool is_active);

#endif // __CONTROLBUTTON_H__

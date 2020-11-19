/**
 * @file PotiController.h
 * @author Manuel Braun (mommel.devOgmail.com)
 * @brief Example how to use Potis
 * @version 1.0.3
 * @date 2020-10-14
 *
 * @copyright Copyright (c) 2020 - Manuel Braun & HappyShooting Community
 *
 * @class PotiController
 */

#ifndef ARDUINO
#include "Arduino.h"
#endif  // ARDUINO

#include <PotiController.h>
#include <MIDI.h>

void SendMidiTrigger(int inControlNumber, bool is_active);

void sendMidiValueChange(int inControlNumber, byte controllerValue,
                         int sendChannelID);

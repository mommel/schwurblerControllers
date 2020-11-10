#pragma once
#ifndef SCHWURBLER_CONTROLLERS_SCHWURBLERCONTROLLER_H_
#define SCHWURBLER_CONTROLLERS_SCHWURBLERCONTROLLER_H_

#ifndef ARDUINO
#include "Arduino.h" // Arduino Header
#endif // ARDUINO
#define Schwurbler_DEF_ButtonController_Active 
#define Schwurbler_DEF_PotiController_Active

/**
 * After a longer thought about how having the libary as easy as possible for non programmers, i came to the decission
 * to break with the abstract thinking and keep it simple stupid.
 * Wihthing this header all needed headers will be set to get a runnable Schuwurbler.
 * 
 * The customization runs completly with definitions, it's intended to set a clickable interface on top maybe.
 * So here all definitions will be set that are not set in the main.h
 */

// Set's the Midi Channel - Der Schwurbler uses to communicate
#ifndef Schwurbler_DEF_SendTo_MidiChannel
#define Schwurbler_DEF_SendTo_MidiChannel                       7
#endif // Schwurbler_DEF_SendTo_MidiChannel

// ------------------------------------          ButtonController Definitions          ------------------------------------ //
// If active is defined all needed  will be checked
#ifdef Schwurbler_DEF_ButtonController_Active

#ifndef Schwurbler_DEF_ButtonController_Amount
// Set's the Pins for the Buttons
#define Schwurbler_DEF_ButtonController_Amount                  14
#endif // Schwurbler_DEF_ButtonController_Amount

#ifndef Schwurbler_DEF_ButtonController_Pins
// Set's the Pins for the Buttons
#define Schwurbler_DEF_ButtonController_Pins                    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14}
#endif // Schwurbler_DEF_ButtonController_Pins

#ifndef Schwurbler_DEF_ButtonController_Keys
// Set's the MidiKeys for the Buttons
#define Schwurbler_DEF_ButtonController_Keys                    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
#endif // Schwurbler_DEF_ButtonController_Keys

#ifndef Schwurbler_DEF_ButtonController_BounceTime
// Set's the time each button gets debounced
// The sensor will check for falling and raising edges
// But as the signal isn't always top notch
// we need to debounce it to get valid status changes
#define Schwurbler_DEF_ButtonController_BounceTime              7
#endif // Schwurbler_DEF_ButtonController_BounceTime

#ifndef Schwurbler_DEF_ButtonController_TriggerVelocity
// Set's the velocity the ON Trigger gets send with over MIDI
#define Schwurbler_DEF_ButtonController_TriggerVelocity         99
#endif // Schwurbler_DEF_ButtonController_TriggerVelocity


// ------------------------------------          ButtonController Definitions          ------------------------------------ //
#endif // Schwurbler_DEF_ButtonController_Active

// ------------------------------------            PotiController Definitions          ------------------------------------ //
// If active is defined all needed  will be checked
#ifdef Schwurbler_DEF_PotiController_Active

#ifndef Schwurbler_DEF_PotiController_Amount
// Set's the Pins for the Buttons
#define Schwurbler_DEF_PotiController_Amount                  9
#endif // Schwurbler_DEF_PotiController_Amount

#ifndef Schwurbler_DEF_PotiController_Pins
// Set's the Pins for the Buttons
#define Schwurbler_DEF_PotiController_Pins                    { A9, A8, A7, A6, A5, A4, A3, A2, A1 }
#endif // Schwurbler_DEF_PotiController_Pins

#ifndef Schwurbler_DEF_PotiController_Keys
// Set's the MidiKeys for the Buttons
#define Schwurbler_DEF_PotiController_Keys                    { 21, 22, 23, 25, 26, 27, 28, 30, 31 }
#endif // Schwurbler_DEF_PotiController_Keys

// ------------------------------------            PotiController Definitions          ------------------------------------ //
#endif // Schwurbler_DEF_PotiController_Active

// ------------------------------------            PotiController Definitions          ------------------------------------ //
// If active is defined all needed  will be checked
#ifdef Schwurbler_DEF_RotaryEncoderController_Active

#ifndef Schwurbler_DEF_RotaryEncoderController_Amount
// Set's the Pins for the Buttons
#define Schwurbler_DEF_RotaryEncoderController_Amount                  4
#endif // Schwurbler_DEF_RotaryEncoderController_Amount

#ifndef Schwurbler_DEF_RotaryEncoderController_Pins
// Set's the Pins for the Buttons
#define Schwurbler_DEF_RotaryEncoderController_Pins                    { 23, 21, 19, 17 }
#endif // Schwurbler_DEF_RotaryEncoderController_Pins

#ifndef Schwurbler_DEF_RotaryEncoderController_Pins2
// Set's the Pins for the Buttons2
#define Schwurbler_DEF_RotaryEncoderController_Pins2                   { 22, 20, 18, 16 }
#endif // Schwurbler_DEF_RotaryEncoderController_Pins2

#ifndef Schwurbler_DEF_RotaryEncoderController_Keys
// Set's the MidiKeys for the Buttons
#define Schwurbler_DEF_RotaryEncoderController_Keys                    { 21, 22, 23, 25 }
#endif // Schwurbler_DEF_RotaryEncoderController_Keys


// ------------------------------------            PotiController Definitions          ------------------------------------ //
#endif // Schwurbler_DEF_RotaryEncoderController_Active
//                                                                                                                          //
//                                                                                                                          //
//                                                                                                                          //
// ------------------------------------               HELPER Definitions               ------------------------------------ //
#ifndef Schwurbler_DEF_arrayCount
#define Schwurbler_DEF_arrayCount(x) (sizeof(x) / sizeof(x)[0])
#endif // Schwurbler_DEF_arrayCount
// ------------------------------------               HELPER Definitions               ------------------------------------ //
#endif // SCHWURBLER_CONTROLLERS_SCHWURBLERCONTROLLER_H_

/**
 * @file RotaryController.h
 * @class RotaryController
 *
 * @defgroup   ROTARYCONTROLLER Rotary Controller
 *
 * @brief       The Controller for the Rotary Encoder.
 *
 * @author     Manuel Braun
 * @date       2020-10-14
 *
 * @version 1.0.3
 *
 * @copyright Copyright (c) 2020 - Manuel Braun & HappyShooting Community
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
 * @section LOGO
 *
 ******************************************************************************
 *            :+==+                                           -:              *
 *       -+#=+-  -=-    -*                             -O|   +W+              *
 *    -=#+-     -=-     =*         =:                 -O|   =*O-              *
 *  -#*-               -#:   :*    =--:               +#  -#-*#               *
 * -#:           :=O#=+:O+#= =*=O--= #+ ++     *WO#*++#==*O- =* *O| -=WO#*++*-*
 *  :=====**+::=*-+#:==+W* =-*O+-O#: #==-*#+*=**O-    :-:W=  #+-O===:*O-      *
 *          :#::#-     :=   -                  --      :W*   #:      --       *
 *        -=+ -=+                                            -:               *
 *       -=-+#+                                                               *
 *        --                                                                  *
 ******************************************************************************
 */

#pragma once

#ifndef ARDUINO
#include "Arduino.h" // Arduino Header
#endif // ARDUINO
#define Schwurbler_DEF_ButtonController_Active
#define Schwurbler_DEF_PotiController_Active

/**
 * After a longer thought about how having the library as easy as possible for non programmers, i came to the decission
 * to break with the abstract thinking and keep it simple stupid.
 * Withing this header all needed headers will be set to get a runnable Schwurbler.
 *
 * The customization runs completely with definitions, it's intended to set a click-able interface on top maybe.
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

/**
 * Amount of Rotary Encoders
 */
#ifndef Schwurbler_DEF_RotaryEncoderController_Amount
// Set's the Pins for the Buttons
#define Schwurbler_DEF_RotaryEncoderController_Amount                  4
#endif // Schwurbler_DEF_RotaryEncoderController_Amount

/**
 * List with Pins
 * All clock pins connected to a Rotary Encoder
 */
#ifndef Schwurbler_DEF_RotaryEncoderController_Pins
// Set's the Pins for the Buttons
#define Schwurbler_DEF_RotaryEncoderController_Pins                    { 23, 21, 19, 17 }
#endif // Schwurbler_DEF_RotaryEncoderController_Pins

/**
 * Second List with Pins
 * All not clock pins connected to a Rotary Encoder
 */
#ifndef Schwurbler_DEF_RotaryEncoderController_Pins2
// Set's the Pins for the Buttons2
#define Schwurbler_DEF_RotaryEncoderController_Pins2                   { 22, 20, 18, 16 }
#endif // Schwurbler_DEF_RotaryEncoderController_Pins2

/**
 * List with Midi Keys to send to
 */
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

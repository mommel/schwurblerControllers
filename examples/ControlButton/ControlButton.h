/**
 * @file ControlButton.ino/.cpp
 * 
 * @package SchwurblerControllers
 * 
 * @version 1.0.0 - Nov 05 2020
 *
 * @brief Example to Control Buttons
 *
 * @section DESCRIPTION
 *
 * The is an Example how to use the SchwurblerControllers ButtonController to control
 * Buttons
 * Example: ControlButton
 * 
 * @copyright Manuel Braun
 * 
 * @author Manuel Braun
 * Contact: github.com/mommel
 * 
 * Name:    Manuel Braun
 * Email:   mommel@gmx de
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
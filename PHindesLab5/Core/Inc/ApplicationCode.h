/*
 * ApplicationCode.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#include <Scheduler.h>

void applicationInit();
void greenLEDInit();
void redLEDInit();
void toggleGreenLED();
void toggleRedLED();
void activateGreenLED();
void activateRedLED();
void deactivateGreenLED();
void deactivateRedLED();

void syncButton();

#endif /* APPLICATIONCODE_H_ */

/*
 * ApplicationCode.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#define NAME_LEN 5
#define DELAY_MAG 250000

#include <LED_Driver.h>
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

void appDelay(uint32_t timeDelay);


#endif /* APPLICATIONCODE_H_ */

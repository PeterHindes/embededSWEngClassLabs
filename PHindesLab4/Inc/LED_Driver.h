/*
 * LED_Driver.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include <GPIO_Driver.h>

#define GREEN_LED 1
#define RED_LED 0

void LED_Init(uint8_t ledNum);
void ToggleLED(uint8_t ledNum);
void TurnOffLED(uint8_t ledNum);
void TurnOnLED(uint8_t ledNum);

// TODO add the 6.b steps here

#endif /* LED_DRIVER_H_ */

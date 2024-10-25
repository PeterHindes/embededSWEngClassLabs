/*
 * LED_Driver.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include <GPIO_Driver.h>
#include <Timer_Driver.h>

#define GREEN_LED 1
#define RED_LED 0

void LED_Init(uint8_t ledNum);
void ToggleLED(uint8_t ledNum);
void TurnOffLED(uint8_t ledNum);
void TurnOnLED(uint8_t ledNum);



void LED_InitTimer2();
void LED_StartTimer2();
void LED_StopTimer2();
void LED_ResetTimer2();

void LED_InitTimer5(bool callback);
void LED_StartTimer5();
void LED_StopTimer5();
void LED_ResetTimer5();

uint32_t LED_GetTimer5AutoReloadValue();
uint32_t LED_GetTimer5CountValue();
void LED_SetTimer5AutoReloadValue(uint32_t new_value);
void LED_StartTimer5WithStartValue(uint32_t start_value);

#endif /* LED_DRIVER_H_ */

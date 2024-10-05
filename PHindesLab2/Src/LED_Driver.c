/*
 * LED_Driver.c
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <LED_Driver.h>

void LED_Init(uint8_t ledNum) {
	// This might be redundant
	GPIO_ClockControl(LED_PORT,1); // Enable rcc for gpiog

	// Use the default values for our gpio
	GPIO_PinConfig_t temp = DEFAULT_PIN_CONFIG(0);
	temp.PinMode = OUTPUT;
	switch (ledNum) {
		case GREEN_LED:
			temp.PinNumber = GREEN_LED_PIN;
			break;
		case RED_LED:
			temp.PinNumber = RED_LED_PIN;
			break;
		default:
			break;
	}
	GPIO_Init(GPIOG, temp);
}

void TurnOffLED(uint8_t ledNum) {
	uint8_t pinNumber;
	switch (ledNum) {
		case GREEN_LED:
			pinNumber = GREEN_LED_PIN;
			break;
		case RED_LED:
			pinNumber = RED_LED_PIN;
			break;
		default:
			break;
	}
	GPIO_WriteToOutputPin(GPIOG, pinNumber, 0);
}
void TurnOnLED(uint8_t ledNum) {
	uint8_t pinNumber;
	switch (ledNum) {
		case GREEN_LED:
			pinNumber = GREEN_LED_PIN;
			break;
		case RED_LED:
			pinNumber = RED_LED_PIN;
			break;
		default:
			break;
	}
	GPIO_WriteToOutputPin(GPIOG, pinNumber, 1);
}

void ToggleLED(uint8_t ledNum) {
	uint8_t pinNumber;
	switch (ledNum) {
		case GREEN_LED:
			pinNumber = GREEN_LED_PIN;
			break;
		case RED_LED:
			pinNumber = RED_LED_PIN;
			break;
		default:
			break;
	}
	GPIO_ToggleOutputPin(GPIOG, pinNumber);
}

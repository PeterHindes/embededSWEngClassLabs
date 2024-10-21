/*
 * LED_Driver.c
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <LED_Driver.h>

void LED_Init(uint8_t ledNum) {
	// This might be redundant
	GPIO_ClockControl(LED_PORT, ENABLE);

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

	// Use the default values for our gpio (all zeros for our board so redundant)
	GPIO_PinConfig_t temp = DEFAULT_PIN_CONFIG(pinNumber);
	temp.PinMode = OUTPUT;

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

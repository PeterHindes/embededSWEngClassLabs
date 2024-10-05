/*
 * ApplicationCode.c
 *
 *  Created on: Aug 27, 2024
 *      Author: Peter Hindes
 */
#include <stdint.h>
#include <stdbool.h>

#define GPIOG_RCC_ENABLE_ADDRESS 0x40023830 // RCC_AHB1ENR register file contains the enable bits for the gpio group clocks
#define GPIOG_AHB1ENR_BIT_OFFSET 6 // bit 6 of that register enables gpio group g
#define GPIOG_MODER_ADDRESS 0x40021800
#define GPIOG_ODR_ADDRESS 0x40021814

#define RED_LED_MODER_BIT_OFFSET 26
#define RED_LED_OUT_MODE_BIT_VALUES 0b01 //General purpose output mode
#define RED_LED_ODR_BIT_OFFSET 13

#define LEN_OF_NAME 5 //peter

void AppDelay(uint32_t timeToDelay) {
	char name[LEN_OF_NAME] = "Peter";//{'P','e','t','e','r'};
	[[maybe_unused]] char destArray[LEN_OF_NAME];
	for (uint32_t j = 0; j<timeToDelay; j++){
		for (uint8_t i = 0; i < LEN_OF_NAME; i++) {
			destArray[i] = name[i];
		}
	}
}

void EnablePeripheralsAndClocks(){
	// Enable the clock for the GPIO G group
	uint32_t * gpiog_rcc_enable_address = (uint32_t*) GPIOG_RCC_ENABLE_ADDRESS;
	*(gpiog_rcc_enable_address) |= (1 << GPIOG_AHB1ENR_BIT_OFFSET);

	// Set the mode for pin 14 to output on the gpio g group
	uint32_t * gpiog_moder_address = (uint32_t*) GPIOG_MODER_ADDRESS;
	*(gpiog_moder_address) |= (RED_LED_OUT_MODE_BIT_VALUES << RED_LED_MODER_BIT_OFFSET);
}

void TurnOnRedLED(){
	// Set group g pin 14 high
	uint32_t * gpiog_odr_address = (uint32_t*) GPIOG_ODR_ADDRESS;
	*(gpiog_odr_address) |= (1 << RED_LED_ODR_BIT_OFFSET);
}

void TurnOffRedLED(){
	// Set group g pin 14 low
	uint32_t * gpiog_odr_address = (uint32_t*) GPIOG_ODR_ADDRESS;
	*(gpiog_odr_address) &= ~(1 << RED_LED_ODR_BIT_OFFSET);
}

void ToggleRedLED(){
//	// Simple implementation
//	static bool ledOn;
//
//	if (ledOn) {
//		TurnOnRedLED();
//	} else {
//		TurnOffRedLED();
//	}
//	ledOn = ~ledOn;

	// Alternative Implementation
	// Read the current value from the odr
	uint32_t * gpiog_odr_address = (uint32_t*) GPIOG_ODR_ADDRESS;
	uint32_t odrVal = *gpiog_odr_address;
	// Remove bits that arent at 14
	odrVal <<= 15 - RED_LED_ODR_BIT_OFFSET;
	odrVal >>= 15;
	// Convert to bool so the debuger is nice lol
	bool ledOn = odrVal;

	if (ledOn) {
		TurnOffRedLED();
	} else {
		TurnOnRedLED();
	}
}

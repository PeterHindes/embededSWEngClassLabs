/*
 * Button_Driver.c
 *
 *  Created on: Sep 26, 2024
 *      Author: user
 */

#include <Button_Driver.h>

// Init also sets the clock in this driver
void BUT_Init(uint8_t TriggerType) {
	// This might be redundant
	GPIO_ClockControl(UBUT_PORT, ENABLE);
	// Use the default values for our gpio (all zeros for our board so redundant)
	// It defaults to input. we could set it explicitly to input if we wanted, but for this to be a problem DEFAULT_PIN_CONFIG would have to change.
	GPIO_PinConfig_t temp = DEFAULT_PIN_CONFIG(UBUT_PIN); // dont worry this is valid for pin zero of port a just not some other pins

	temp.PinInteruptMode = TriggerType;


	GPIO_Init(UBUT_PORT,temp);
}

bool BUT_Pressed() {
	uint32_t bpreseed = GPIO_ReadFromInputPin(UBUT_PORT, UBUT_PIN);
	return (bool) bpreseed;
}

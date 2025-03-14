/*
 * ApplicationCode.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <ApplicationCode.h>

void greenLEDInit(){
	LED_Init(GREEN_LED);
}
void redLEDInit(){
	LED_Init(RED_LED);
}

void applicationInit(){
	LED_Init(GREEN_LED);
	LED_Init(RED_LED);

	addSchedulerEvent(LED_TOGGLE_EVENT);
	addSchedulerEvent(DELAY_EVENT);
}

void toggleGreenLED(){
	ToggleLED(GREEN_LED);
}
void toggleRedLED(){
	ToggleLED(RED_LED);
}
void activateGreenLED(){
	TurnOnLED(GREEN_LED);
}
void activateRedLED(){
	TurnOnLED(RED_LED);
}
void deactivateGreenLED(){
	TurnOffLED(GREEN_LED);
}
void deactivateRedLED(){
	TurnOffLED(RED_LED);
}

void appDelay(uint32_t timeDelay) {
	char name[NAME_LEN] = {'P', 'e', 't', 'e', 'r'};
	[[maybe_unused]] char cname[NAME_LEN];
	for (uint32_t l = 0; l < timeDelay; l++) {
		for (uint32_t i = 0; i < NAME_LEN; i++) {
			cname[i]=name[i];
		}
	}
}

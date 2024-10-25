/*
 * LED_Driver.c
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <LED_Driver.h>

// Specific to lab 4
#define BLINK_TIME_SEC 5

// Generic
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

// Specific to lab 4
void LED_InitTimer2() {
	TimerEnableDisable(TIM2, true);

	GPTimer_Config_t config = DEFAULT_TIM_CONFIG();
	config.Auto_Reload_Value = CLOCK_BASE_FREQ * BLINK_TIME_SEC;
	config.Interrupt_update_enablement = true;

	TimerInit(TIM2,config);
}
void LED_InitTimer5(bool callback) {
	TimerEnableDisable(TIM5, true);

	GPTimer_Config_t config = DEFAULT_TIM_CONFIG();
	config.Interrupt_update_enablement = callback;

	TimerInit(TIM5, config);
}


void LED_StartTimer2(){
	TimerStart(TIM2);
}
void LED_StopTimer2(){
	TimerStop(TIM2);
}
void LED_ResetTimer2(){
	TimerReset(TIM2);
}

void LED_StartTimer5(){
	TimerStart(TIM5);
}
void LED_StopTimer5(){
	TimerStop(TIM5);
}
void LED_ResetTimer5(){
	TimerReset(TIM5);
}
uint32_t LED_GetTimer5AutoReloadValue(){
	return TimerReadARR(TIM5);
}
uint32_t LED_GetTimer5CountValue(){
	return TimerReadCurent(TIM5);
}
void LED_SetTimer5AutoReloadValue(uint32_t new_value){
	TimerWriteARR(TIM5,new_value);
}
void LED_StartTimer5WithStartValue(uint32_t start_value){
	TimerWriteCurrent(TIM5,start_value);
	LED_StartTimer5();
}

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
	TurnOffLED(GREEN_LED);
	TurnOffLED(RED_LED);

#if DAUL_TIMER_USAGE == 0
	LED_InitTimer2();
	LED_StartTimer2();
#else
	BUT_Init(RISING_EDGE_INTERRUPT);
	LED_InitTimer5(false);
#endif
}

#if DAUL_TIMER_USAGE == 0
void TIM2_IRQHandler(){
	// disable further interrupts while processing
	IRQ_disable(TIM2_IRQ_NUMBER);

	// do work
	toggleRedLED();

	// Clear the pending interrupt from timer and nvic and then reenable this interrupt
	IRQ_tim_line_clear(2);
	IRQ_clear(TIM2_IRQ_NUMBER);
	IRQ_enable(TIM2_IRQ_NUMBER);
}
#elif DAUL_TIMER_USAGE == 1
bool valSaved = false;
void TIM5_IRQHandler(){
	// disable further interrupts while processing
	IRQ_disable(TIM5_IRQ_NUMBER);

	// do work
	if (valSaved != true)
		HANG();
	toggleGreenLED();

	// Clear the pending interrupt from timer and nvic and then reenable this interrupt
	IRQ_tim_line_clear(5);
	IRQ_clear(TIM5_IRQ_NUMBER);
	IRQ_enable(TIM5_IRQ_NUMBER);
}
void EXTI0_IRQHandler() {
	static bool falling = false;
	// disable further interrupts while processing
	IRQ_disable(EXTI0_IRQ_NUMBER);

	// Clear the pending interrupt from exti and nvic
	IRQ_exti_line_clear(UBUT_PIN);
	IRQ_clear(EXTI0_IRQ_NUMBER);

	// do work
	if (!falling){
		BUT_Init(FALLING_EDGE_INTERRUPT);
		LED_StartTimer5();
		falling = true;
		IRQ_enable(EXTI0_IRQ_NUMBER);
	} else {
		// Save timer count and enable the interrupts
		LED_InitTimer5(true);
		LED_SetTimer5AutoReloadValue(LED_GetTimer5CountValue());
		// Reset the timer (necessary)
		LED_StartTimer5WithStartValue(0);
		// change the led to on for instant feedback
		toggleGreenLED();
		valSaved = true;
	}

	// dont reenable the irq if were done
}
#endif

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

void syncButton(){
	bool pressed = BUT_Pressed();
	pressed ? activateGreenLED() : deactivateGreenLED();
}

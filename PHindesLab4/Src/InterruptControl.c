/*
 * InterruptControl.c
 *
 *  Created on: Sep 28, 2024
 *      Author: user
 */

#include <InterruptControl.h>

// ExtiNumber can be found with GPIO_PortToIndex function
void IRQ_EXTI_pin_picker(uint8_t ExtiNumber, uint8_t portNumber){
	uint32_t temp;
	temp = (portNumber << ((ExtiNumber * 4) % 16));

	// Integer division
	SYSCFG->EXTICR[ExtiNumber/4] &= ~(0b1111 << ((ExtiNumber * 4) % 16));
	SYSCFG->EXTICR[ExtiNumber/4] |= temp;
}

void IRQ_Init(){
	EN_SYSCFG_CLK; // Enable Syscfg clock
	// Dont need to enable exti through rcc
}

void IRQ_enable(uint8_t irqNum){
	(* NVIC_ISER0)[irqNum/32] |= (1 << (irqNum%32));
}
void IRQ_disable(uint8_t irqNum){
	(* NVIC_ICER0)[irqNum/32] |= (1 << (irqNum%32));
}
void IRQ_set(uint8_t irqNum){
	(* NVIC_ISPR0)[irqNum/32] |= (1 << (irqNum%32));
}
void IRQ_clear(uint8_t irqNum){
	(* NVIC_ICPR0)[irqNum/32] |= (1 << (irqNum%32));
}

void IRQ_exti_line_clear(uint8_t lineNum) {
	(EXTI->PR) |= (1 << lineNum);
}
void IRQ_tim_line_clear(uint8_t timNum){
	if (timNum==2)
		TIM2->SR &= ~1;
	if (timNum==5)
		TIM5->SR &= ~1;
}

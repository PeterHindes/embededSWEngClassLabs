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
	RCC->AHB2EN |= (1<<14); // Enable Syscfg
	IRQ_enable(EXTI0_IRQ_NUMBER);
	IRQ_EXTI_pin_picker(0,0);
}

// TODO Dont use or
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

/*
 * InterruptControl.h
 *
 *  Created on: Sep 28, 2024
 *      Author: user
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include <STM32F429i.h>

#define EXTI0_IRQ_NUMBER 6
#define TIM2_IRQ_NUMBER 28
#define TIM5_IRQ_NUMBER 50

/*
 * Bits 22:0 PRx: Pending bit
 * 0: No trigger request occurred
 * 1: selected trigger request occurred
 * This bit is set when the selected edge event arrives on the external interrupt line.
 * This bit is cleared by programming it to ‘1’.
*/

void IRQ_Init();
void IRQ_EXTI_pin_picker(uint8_t ExtiNumber, uint8_t portNumber);
void IRQ_enable(uint8_t irqNum);
void IRQ_disable(uint8_t irqNum);
void IRQ_set(uint8_t irqNum);
void IRQ_clear(uint8_t irqNum);

void IRQ_exti_line_clear(uint8_t lineNum);
void IRQ_tim_line_clear(uint8_t timNum);

#endif /* INTERRUPTCONTROL_H_ */

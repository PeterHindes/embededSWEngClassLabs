/*
 * GPIO_Driver.c
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <GPIO_Driver.h>

#define FOUR_BIT_REG_WIDTH 4
#define TWO_BIT_REG_WIDTH 2

void setFourBitReg(volatile uint32_t (*reg)[2], uint8_t subPos, uint32_t bits){
	uint32_t temp;
	temp = (bits << (FOUR_BIT_REG_WIDTH * subPos));

	// Move up by 4 bytes if we are over halfway through, thats what [(subPos > 7)] does

	// Clear the mode with two zeros in our pin related bits
	(*reg)[(subPos > 7)] &= ~(0b1111 << (FOUR_BIT_REG_WIDTH * subPos));

	// Set the mode from our args
	(*reg)[(subPos > 7)] |= temp;
}
void setTwoBitReg(volatile uint32_t * reg, uint8_t subPos, uint32_t bits){
	uint32_t temp;
	temp = (bits << (TWO_BIT_REG_WIDTH * subPos));

	// Clear the mode with two zeros in our pin related bits
	(*reg) &= ~(0b11 << (TWO_BIT_REG_WIDTH * subPos));

	// Set the mode from our args
	(*reg) |= temp;
}
void setOneBitReg(volatile uint32_t * reg, uint8_t subPos, uint32_t bits){
	uint32_t temp;
	temp = (bits << subPos);

	// Clear the mode with two zeros in our pin related bits
	(*reg) &= ~(0b1 << subPos);

	// Set the mode from our args
	(*reg) |= temp;
}

void GPIO_Init(GPIO_RegDef_t * port, GPIO_PinConfig_t config){
	setTwoBitReg(&(port->MODER), config.PinNumber, config.PinMode);
	setTwoBitReg(&(port->OSPEEDR), config.PinNumber, config.PinSpeed);
	setTwoBitReg(&(port->PUPDR), config.PinNumber, config.PinPuPdControl);

	setOneBitReg(&(port->OTYPER), config.PinNumber, config.OPType);

	if (port->MODER == 0b10) {
		setFourBitReg(&(port->AFRL), config.PinNumber, config.PinAltFunMode);
	}
}

void GPIO_ClockControl(GPIO_RegDef_t * port, uint8_t enableDisable) {
	// Safety for our limited implementation
	if (port == GPIOG){
		if (enableDisable == 1){ // Enable it
			RCC->AHB1EN |= (1 << GPIOG_AHB1ENR_BIT_OFFSET) ;
		} else {
			RCC->AHB1EN &= ((!1) << GPIOG_AHB1ENR_BIT_OFFSET) ;
		}
	}
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t * port, uint8_t pinNumber) {
	if ( (((port->MODER) & (0b11<<pinNumber*2)) >> pinNumber*2) == OUTPUT) {
		return ((port->ODR) & (1<<pinNumber)) >> pinNumber;
	} else if ( (((port->MODER) & (0b11<<pinNumber*2)) >> pinNumber*2) == INPUT) {
		return ((port->IDR) & (1<<pinNumber)) >> pinNumber;
	} else {
		return 0;
	}
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t * port, uint8_t pinNumber, uint8_t value) {
	// Safety for our limited implementation
	if (port == GPIOG) {
		if (value == 0){
			(port->ODR) &= (!(1) << pinNumber);
		} else {
			(port->ODR) |= (1 << pinNumber);
		}
	}
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t * port, uint8_t pinNumber) {
	// Safety for our limited implementation
		if (port == GPIOG) {
			if (GPIO_ReadFromInputPin(port, pinNumber) == 0) {
				GPIO_WriteToOutputPin(port, pinNumber, 1);
			} else {
				GPIO_WriteToOutputPin(port, pinNumber, 0);
			}
		}
}

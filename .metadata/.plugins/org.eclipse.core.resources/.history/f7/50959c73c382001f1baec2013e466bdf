/*
 * GPIO_Driver.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include <STM32F429i.h>

#define GPIO_PIN_NUM_0  0
#define GPIO_PIN_NUM_1  1
#define GPIO_PIN_NUM_2  2
#define GPIO_PIN_NUM_3  3
#define GPIO_PIN_NUM_4  4
#define GPIO_PIN_NUM_5  5
#define GPIO_PIN_NUM_6  6
#define GPIO_PIN_NUM_7  7
#define GPIO_PIN_NUM_8  8
#define GPIO_PIN_NUM_9  9
#define GPIO_PIN_NUM_10 10
#define GPIO_PIN_NUM_11 11
#define GPIO_PIN_NUM_12 12
#define GPIO_PIN_NUM_13 13
#define GPIO_PIN_NUM_14 14
#define GPIO_PIN_NUM_15 15
#define GPIO_PIN_NUM_16 16

enum GPIO_MODE {
	INPUT,
	OUTPUT,
	ALT_MODE,
	ANALOG
};

enum GPIO_OUTPUT_TYPE {
	PUSH_PULL,
	OPEN_DRAIN
};

enum GPIO_OUTPUT_SPEED {
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED
};

enum GPIO_BIAS_TYPE {
	NO_PU_PD,
	PULL_UP,
	PULL_DOWN
};

enum GPIO_INTERRUPT_MODE {
	NO_INTERRUPT,
	FALLING_EDGE_INTERRUPT,
	RISING_EDGE_INTERRUPT,
	FALLING_OR_RISING_EDGE_INTERRUPT
};

typedef struct {
	uint8_t PinNumber;
	uint8_t PinMode;
	uint8_t OPType; // Output Type
	uint8_t PinSpeed;
	uint8_t PinPuPdControl; // Pin Push up/ Pull Down Control
	uint8_t PinAltFunMode;
	uint8_t PinInteruptMode;
} GPIO_PinConfig_t ;

// NOT VALID FOR PORT A OR PORT B
#define DEFAULT_PIN_CONFIG(pinNum) { \
	pinNum, \
	INPUT, \
	PUSH_PULL, \
	LOW_SPEED, \
	NO_PU_PD, \
	0 \
}

void GPIO_Init(GPIO_RegDef_t * port, GPIO_PinConfig_t pinConfig);
void GPIO_ClockControl(GPIO_RegDef_t * port, uint8_t on);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t * port, uint8_t pinNumber);
uint8_t GPIO_PortToIndex(GPIO_RegDef_t * port);
void GPIO_WriteToOutputPin(GPIO_RegDef_t * port, uint8_t pinNumber, uint8_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t * port, uint8_t pinNumber);

#endif /* GPIO_DRIVER_H_ */

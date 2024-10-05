/*
 * STM32F429i.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

// The leds are on port g, pin13 is green and pin14 is red

#ifndef STM32F429I_H_
#define STM32F429I_H_

#include <stdint.h>

#define AHB1_BUSS_BASE_ADDR 0x40020000
#define RCC_PERIF_BASE_ADDR (AHB1_BUSS_BASE_ADDR + 0x3800)
#define GPIOG_AHB1ENR_BIT_OFFSET 6
#define GPIOG_PERIF_BASE_ADDR (AHB1_BUSS_BASE_ADDR + 0x1800)

typedef struct GPIO_RegDef_t {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL[2];
} GPIO_RegDef_t ;

typedef struct RCC_RegDef_t {
	volatile uint32_t C;
	volatile uint32_t PLLCFG;
	volatile uint32_t CFG;
	volatile uint32_t CI;
	volatile uint32_t AHB1RST;
	volatile uint32_t AHB2RST;
	volatile uint32_t AHB3RST;
	volatile uint32_t RESERVED0;
	volatile uint32_t APB1RST;
	volatile uint32_t APB2RST;
	volatile uint32_t RESERVED1;
	volatile uint32_t RESERVED2;
	volatile uint32_t AHB1EN;
	volatile uint32_t AHB2EN;
	volatile uint32_t AHB3EN;
	volatile uint32_t RESERVED3;
	volatile uint32_t APB1EN;
	volatile uint32_t APB2EN;
	volatile uint32_t RESERVED4;
	volatile uint32_t RESERVED5;
	volatile uint32_t AHB1LPEN;
	volatile uint32_t AHB2LPEN;
	volatile uint32_t AHB3LPEN;
	volatile uint32_t RESERVED6;
	volatile uint32_t APB1LPEN;
	volatile uint32_t APB2LPEN;
	volatile uint32_t RESERVED7;
	volatile uint32_t RESERVED8;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED9;
	volatile uint32_t RESERVED10;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFG;
} RCC_RegDef_t ;


#define GPIOG ((GPIO_RegDef_t *) GPIOG_PERIF_BASE_ADDR)
#define RCC ((RCC_RegDef_t *) RCC_PERIF_BASE_ADDR)

#define LED_PORT GPIOG
#define GREEN_LED_PIN 13
#define RED_LED_PIN 14

//#define GPIOG_CLK_ENABLE  RCC->AHB1EN |= (1 << 6)
//#define GPIOG_CLK_DISABLE RCC->AHB1EN &= ((!1) << 6)

#define ACTIVE 1
#define NON_ACTIVE 0
#define SET 1
#define RESET 0
#define ENABLE SET
#define DISABLE RESET

#endif /* STM32F429I_H_ */

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
#include <stdbool.h>

#define AHB1_BUSS_BASE_ADDR 0x40020000
#define APB1_BUSS_BASE_ADDR 0x40000000
#define GPIO_START_ADDR AHB1_BUSS_BASE_ADDR // the base addr of the first gpio perif
#define GPIO_END_ADDR 0x40022800 // the base addr of the last gpio perif
#define RCC_PERIF_BASE_ADDR (AHB1_BUSS_BASE_ADDR + 0x3800)
#define GPIOG_PERIF_BASE_ADDR (AHB1_BUSS_BASE_ADDR + 0x1800)
#define TIM2_PERFI_BASE_ADDR (APB1_BUSS_BASE_ADDR + 0x0000)
#define TIM5_PERFI_BASE_ADDR (APB1_BUSS_BASE_ADDR + 0x0C00)

#define EN_SYSCFG_CLK (RCC->AHB2EN |= (1<<14))
#define DA_SYSCFG_CLK (RCC->AHB2EN &= ~(1<<14))

#define EN_TIM_CLK(tim_num) (RCC->APB1ENR |= (1<<(tim_num-2))) // valid for tim2 through tim7
#define DA_TIM_CLK(tim_num) (RCC->APB1ENR &= ~(1<<(tim_num-2))) // valid for tim2 through tim7

// Interrupts section
#define NVIC_ISER0 ((volatile uint32_t (*)[8]) 0xE000E100)
#define NVIC_ICER0 ((volatile uint32_t (*)[8]) 0XE000E180)
#define NVIC_ISPR0 ((volatile uint32_t (*)[8]) 0XE000E200)
#define NVIC_ICPR0 ((volatile uint32_t (*)[8]) 0XE000E280)

#define AHB2_BUSS_BASE_ADDR 0x40013800
#define SYSCFG_BASE_ADDR (AHB2_BUSS_BASE_ADDR + 0x000)
#define EXTI_BASE_ADDR (AHB2_BUSS_BASE_ADDR + 0x400)

typedef struct GPTIMR_RegDef_t {
	volatile uint32_t CR[2];
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR[2];
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t CCR[4];
	volatile uint32_t RESERVED;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t OR; // hint, different offset for tim2 vs tim5
} GPTIMR_RegDef_t;

typedef struct SYSCFG_RegDef_t {
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4]; // each of these only uses half of its bits and wraps around to the next one, each thing is 4 bits wide
	volatile uint32_t RESERVED[2];
	volatile uint32_t CMPCR;
} SYSCFG_RegDef_t;

typedef struct EXTI_RegDef_t {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_RegDef_t;

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

#define GPIO_SEPPARATION_BYTES 0x400
#define GPIOA ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*0 )))
#define GPIOB ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*1 )))
#define GPIOC ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*2 )))
#define GPIOD ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*3 )))
#define GPIOE ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*4 )))
#define GPIOF ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*5 )))
#define GPIOG ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*6 )))
#define GPIOH ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*7 )))
#define GPIOI ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*8 )))
#define GPIOJ ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*9 )))
#define GPIOK ((GPIO_RegDef_t *) (GPIO_START_ADDR + (GPIO_SEPPARATION_BYTES*10)))

#define TIM2 ((GPTIMR_RegDef_t *) TIM2_PERFI_BASE_ADDR)
#define TIM5 ((GPTIMR_RegDef_t *) TIM5_PERFI_BASE_ADDR)

#define EXTI ((EXTI_RegDef_t *) EXTI_BASE_ADDR)
#define SYSCFG ((SYSCFG_RegDef_t *) SYSCFG_BASE_ADDR)

#define RCC ((RCC_RegDef_t *) RCC_PERIF_BASE_ADDR)

#define LED_PORT GPIOG
#define GREEN_LED_PIN 13
#define RED_LED_PIN 14

#define UBUT_PORT GPIOA
#define UBUT_PORT_NUMBER 0
#define UBUT_PIN 0
#define UBUT_ACTIVE_VAL 1 // active high when pushed

#define CKD_BIT_OFFSET 8
#define ARPE_BIT_OFFSET 7
#define DIR_BIT_OFFSET 4
#define CMS_BIT_OFFSET 5
#define OPM_BIT_OFFSET 3
#define UDIS_BIT_OFFSET 1

#define MMS_BIT_OFFSET 4

#define ACTIVE 1
#define NON_ACTIVE 0
#define SET 1
#define RESET 0
#define ENABLE SET
#define DISABLE RESET

uint32_t HANG();

#endif /* STM32F429I_H_ */

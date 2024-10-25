/*
 * Timer_Driver.h
 *
 *  Created on: Oct 15, 2024
 *      Author: user
 */

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

#include <STM32F429i.h>
#include <InterruptControl.h>

#define setBit(pos,bit,offset) \
	(pos) &= ~((0b1 & bit) << offset); \
	(pos) |= ((0b1 & bit) << offset);

#define timNumToOffset()

enum COUNTING_MODES {
	TIM_CMODE_UPCOUNT,
	TIM_CMODE_DOWNCOUNT,
	TIM_CMODE_CENTERALDOWN,
	TIM_CMODE_CENTERALUP,
	TIM_CMODE_CENTERALBOTH,
};

enum MASTER_MODES {
	TIM_MMODE_RESET,
	TIM_MMODE_ENABLE,
	TIM_MMODE_UPDATE,
	TIM_MMODE_COMPARE_PULSE,
	TIM_MMODE_COMPARE_OC1REF,
	TIM_MMODE_COMPARE_OC2REF,
	TIM_MMODE_COMPARE_OC3REF,
	TIM_MMODE_COMPARE_OC4REF,
};

enum CLK_DIV_MODES {
	TIM_DIV_BASE,
	TIM_DIV_HALF,
	TIM_DIV_FOURTH,
};

typedef struct GPTimer_Config_t { // These are applied across the two cr registers, the psc register and the arr register as well as calling TimerInterruptEnableDisable
	uint32_t Auto_Reload_Value;
	uint8_t Master_Mode_Selection;
	uint8_t Clock_Division_Selection;
	uint16_t Prescaler_Value;
	uint8_t Counting_Mode;
	bool Auto_reload_buffer_enablement;
	bool Interrupt_update_enablement;
	bool Disable_update_event;
	bool One_pulse_mode_enablement;
} GPTimer_Config_t;

// Only valid for tim5 and tim2
#define DEFAULT_TIM_CONFIG() { \
	0xFFFFFFFF, \
	TIM_MMODE_RESET, \
	TIM_DIV_BASE, \
	0, \
	TIM_CMODE_UPCOUNT, \
	0, \
	0, \
	0, \
	0, \
}

void TimerInit(GPTIMR_RegDef_t * tim, GPTimer_Config_t config);
void TimerEnableDisable(GPTIMR_RegDef_t * tim, bool enable);
void TimerStart(GPTIMR_RegDef_t * tim);
void TimerStop(GPTIMR_RegDef_t * tim);
void TimerReset(GPTIMR_RegDef_t * tim);

uint32_t TimerReadCurent(GPTIMR_RegDef_t * tim);
void TimerWriteCurrent(GPTIMR_RegDef_t * tim, uint32_t val);


void TimerInterruptEnableDisable(GPTIMR_RegDef_t * tim, bool enable);

uint32_t TimerReadARR(GPTIMR_RegDef_t * tim);
void TimerWriteARR(GPTIMR_RegDef_t * tim, uint32_t val);

#endif /* TIMER_DRIVER_H_ */

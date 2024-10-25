/*
 * Timer_Driver.c
 *
 *  Created on: Oct 15, 2024
 *      Author: user
 */

#include <Timer_Driver.h>

void TimerInit(GPTIMR_RegDef_t * tim, GPTimer_Config_t config){
//	static bool calledBefore;
//	if (!calledBefore){
//		TimerEnableDisable(tim,true);
//		calledBefore = true;
//	}

	setBit(tim->CR[0], config.Clock_Division_Selection, CKD_BIT_OFFSET)
	setBit(tim->CR[0], (config.Clock_Division_Selection>>1), (CKD_BIT_OFFSET+1))

	switch (config.Counting_Mode) {
		case TIM_CMODE_UPCOUNT:
			setBit(tim->CR[0], 0, DIR_BIT_OFFSET)
			setBit(tim->CR[0], 0, CMS_BIT_OFFSET)
			setBit(tim->CR[0], 0, (CMS_BIT_OFFSET+1))
			break;
		case TIM_CMODE_DOWNCOUNT:
			setBit(tim->CR[0], 1, DIR_BIT_OFFSET)
			setBit(tim->CR[0], 0, CMS_BIT_OFFSET)
			setBit(tim->CR[0], 0, (CMS_BIT_OFFSET+1))
			break;
		case TIM_CMODE_CENTERALDOWN:
			setBit(tim->CR[0], 0, (CMS_BIT_OFFSET+1))
			setBit(tim->CR[0], 1, CMS_BIT_OFFSET)
			break;
		case TIM_CMODE_CENTERALUP:
			setBit(tim->CR[0], 1, (CMS_BIT_OFFSET+1))
			setBit(tim->CR[0], 0, CMS_BIT_OFFSET)
			break;
		case TIM_CMODE_CENTERALBOTH:
			setBit(tim->CR[0], 1, (CMS_BIT_OFFSET+1))
			setBit(tim->CR[0], 1, CMS_BIT_OFFSET)
			break;
	}

	setBit(tim->CR[0], config.Auto_reload_buffer_enablement, ARPE_BIT_OFFSET)

	setBit(tim->CR[0], config.One_pulse_mode_enablement, OPM_BIT_OFFSET)

	setBit(tim->CR[0], config.Disable_update_event, UDIS_BIT_OFFSET)

	// next cr2

	setBit(tim->CR[1], (config.Master_Mode_Selection >> 0), (MMS_BIT_OFFSET + 0))
	setBit(tim->CR[1], (config.Master_Mode_Selection >> 1), (MMS_BIT_OFFSET + 1))
	setBit(tim->CR[1], (config.Master_Mode_Selection >> 2), (MMS_BIT_OFFSET + 2))

	tim->PSC = config.Prescaler_Value;

	tim->ARR = config.Auto_Reload_Value; // might only work on tim2&5

	TimerInterruptEnableDisable(tim,config.Interrupt_update_enablement);
	tim->DIER |= config.Interrupt_update_enablement;
	tim->DIER &= config.Interrupt_update_enablement;
}

void TimerInterruptEnableDisable(GPTIMR_RegDef_t * tim, bool enable){
	if (tim==TIM2)
		IRQ_enable(TIM2_IRQ_NUMBER);
	else if (tim==TIM5)
		IRQ_enable(TIM5_IRQ_NUMBER);
}

void TimerEnableDisable(GPTIMR_RegDef_t * tim, bool enable){
	uint8_t timNum;
	if (tim == TIM2)
		timNum=2;
	else if (tim == TIM5)
		timNum=5;
	else
		HANG();

	if (enable){ // Enable it
		RCC->APB1EN |= (1 << (timNum-2));
	} else { // Disable it
		RCC->APB1EN &= ((!1) << (timNum-2));
	}
}

void TimerStart(GPTIMR_RegDef_t * tim){
	tim->CR[0] |= 1;
}
void TimerStop(GPTIMR_RegDef_t * tim){
	tim->CR[0] &= ~1;
}

void TimerReset(GPTIMR_RegDef_t * tim){
	tim->CNT = 0;
}

uint32_t TimerReadCurent(GPTIMR_RegDef_t * tim){
	return tim->CNT;
}


uint32_t TimerReadARR(GPTIMR_RegDef_t * tim){
	return tim->ARR; // might not be set yet or somehow over written elsewhere
}

void TimerWriteCurrent(GPTIMR_RegDef_t * tim, uint32_t val){
	tim->CNT = val;
}

void TimerWriteARR(GPTIMR_RegDef_t * tim, uint32_t val){
	tim->ARR = val;
}


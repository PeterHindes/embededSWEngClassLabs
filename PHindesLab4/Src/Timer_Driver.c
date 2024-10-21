/*
 * Timer_Driver.c
 *
 *  Created on: Oct 15, 2024
 *      Author: user
 */

#include <Timer_Driver.h>

void TimerInit(GPTIMR_RegDef_t * tim, GPTimer_Config_t config){
//	cr1 |= ((0b11 & config.Clock_Division_Selection) << CKD_BIT_OFFSET);
	setBit(tim->CR[0], config.Clock_Division_Selection, CKD_BIT_OFFSET)
	setBit(tim->CR[0], (config.Clock_Division_Selection>>1), (CKD_BIT_OFFSET+1))
//	cr1 |= ((0b1 & config.Auto_reload_buffer_enablement) << ARPE_BIT_OFFSET);
	setBit(tim->CR[0], config.Auto_reload_buffer_enablement, ARPE_BIT_OFFSET)

	switch (config.Counting_Mode) {
		case TIM_CMODE_UPCOUNT:
			setBit(tim->CR[0], 0, DIR_BIT_OFFSET);
			setBit(tim->CR[0], 0, CMS_BIT_OFFSET);
			setBit(tim->CR[0], 0, (CMS_BIT_OFFSET+1));
			break;
		case TIM_CMODE_DOWNCOUNT:
			setBit(tim->CR[0], 1, DIR_BIT_OFFSET);
			setBit(tim->CR[0], 0, CMS_BIT_OFFSET);
			setBit(tim->CR[0], 0, (CMS_BIT_OFFSET+1));
			break;
		case TIM_CMODE_CENTERALDOWN:
			setBit(tim->CR[0], 0, (CMS_BIT_OFFSET+1));
			setBit(tim->CR[0], 1, CMS_BIT_OFFSET);
			break;
		case TIM_CMODE_CENTERALUP:
			setBit(tim->CR[0], 1, (CMS_BIT_OFFSET+1));
			setBit(tim->CR[0], 0, CMS_BIT_OFFSET);
			break;
		case TIM_CMODE_CENTERALBOTH:
			setBit(tim->CR[0], 1, (CMS_BIT_OFFSET+1));
			setBit(tim->CR[0], 1, CMS_BIT_OFFSET);
			break;
	}

	setBit(tim->CR[0], config.One_pulse_mode_enablement, OPM_BIT_OFFSET)

	setBit(tim->CR[0], config.Disable_update_event, UDIS_BIT_OFFSET)

	// next cr2

	setBit(tim->CR[1], (config.Master_Mode_Selection >> 0), (MMS_BIT_OFFSET + 0))
	setBit(tim->CR[1], (config.Master_Mode_Selection >> 1), (MMS_BIT_OFFSET + 1))
	setBit(tim->CR[1], (config.Master_Mode_Selection >> 2), (MMS_BIT_OFFSET + 2))

}

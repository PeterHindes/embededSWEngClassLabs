/*
 * Button_Driver.h
 *
 *  Created on: Sep 26, 2024
 *      Author: user
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include <GPIO_Driver.h>

#define BUTTON_PUSHED UBUT_ACTIVE_VAL
#define BUTTON_UNPUSHED ~UBUT_ACTIVE_VAL

void BUT_Init();
//void BUT_ClkEn();
bool BUT_Pressed();

#endif /* BUTTON_DRIVER_H_ */

/*
 * Gyro.h
 *
 *  Created on: Oct 29, 2024
 *      Author: user
 */

#ifndef INC_GYRO_H_
#define INC_GYRO_H_

#include "stm32f4xx_hal.h"
#include <ErrorHandling.h>
#include <stdio.h>

#define GYRO_WHO_AM_I 0b10001111
#define GYRO_OUT_TEMP 0b10100110
#define GYRO_DUMMY_MESSAGE 0b10000000

// awakens and sets odr to 800hz
#define GYRO_AWAKEN_MESSAGE 0b00100000
#define GYRO_AWAKEN_DATA 0b00011111

#define GYRO_SPI_NUM 5 // SPI5
#define GYRO_CS_PIN_NUM GPIO_PIN_1
#define GYRO_CS_PORT GPIOC


void Gyro_Init();
void Gyro_Get_Id();
void Gyro_Power_On();
void Gyro_Get_Temp();
void Gyro_Config_Reg();
void Gyro_Read_Reg();
void Gyro_Verify_Spi_Status(HAL_StatusTypeDef status);
void Gyro_Await_Spi_Status(HAL_StatusTypeDef status);
void Gyro_Enable_Slave_Comms();
void Gyro_Disable_Slave_Comms();
void Gyro_Import_Hspi5(SPI_HandleTypeDef * ihspi5);

#endif /* INC_GYRO_H_ */

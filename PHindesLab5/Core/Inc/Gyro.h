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
#include <types.h>

#define GYRO_WRITE_BIT (0<<7)
#define GYRO_READ_BIT (1<<7)

#define GYRO_CTRL_REG1 0b0100000
#define GYRO_WHO_AM_I 0b0001111

#define GYRO_SPI_NUM 5 // SPI5
#define GYRO_CS_PIN_NUM GPIO_PIN_1
#define GYRO_CS_PORT GPIOC


void Gyro_Init();
void Gyro_Get_Id();
void Gyro_Power_On();
void Gyro_Enable_Fifo();
void Gyro_Get_Temp();
void Gyro_Verify_Spi_Status(HAL_StatusTypeDef status);
void Gyro_Await_Spi_Status(HAL_StatusTypeDef status);
void Gyro_Enable_Slave_Comms();
void Gyro_Disable_Slave_Comms();
void Gyro_Import_Hspi5(SPI_HandleTypeDef * ihspi5);
void Gyro_Write(uint8_t addr, uint8_t data);
uint8_t Gyro_Read(uint8_t addr);

#endif /* INC_GYRO_H_ */

/*
 * Gyro.c
 *
 *  Created on: Oct 29, 2024
 *      Author: user
 */
#include <Gyro.h>

SPI_HandleTypeDef hspi1;

void SPI5_Init() {
    hspi1.Instance = SPI5;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 10;
    APPLICATION_ASSERT(HAL_SPI_Init(&hspi1) == HAL_OK);
}

void Gyro_Init(){
	SPI5_Init();

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET); // Pull The cs pin low to set spi mode

	HAL_Delay(500);

	Gyro_Power_On();

	HAL_Delay(500);
}
void Gyro_Power_On(){
	// Send GYRO_AWAKEN_MESSAGE
	uint8_t TX_Buffer [] = {GYRO_AWAKEN_MESSAGE, GYRO_AWAKEN_DATA};
	HAL_SPI_Transmit(&hspi1, TX_Buffer, 1, 1000);
}
void Gyro_Get_Id(){
	uint8_t TX_Buffer [] = {GYRO_WHO_AM_I, GYRO_DUMMY_MESSAGE};
	HAL_SPI_Transmit(&hspi1, TX_Buffer, 1, 1000);
	uint8_t RX_Buffer [1] ;
	HAL_SPI_Receive(&hspi1, RX_Buffer, 1, 1000);
	printf("%d", RX_Buffer[0]);
}

void Gyro_Get_Temp();
void Gyro_Config_Reg();
void Gyro_Read_Reg();
void Gyro_Verify_Spi_Status();
void Gyro_Enable_Slave_Comms();
void Gyro_Disable_Slave_Comms();

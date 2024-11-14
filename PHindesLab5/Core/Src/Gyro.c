/*
 * Gyro.c
 *
 *  Created on: Oct 29, 2024
 *      Author: user
 */
#include <Gyro.h>

SPI_HandleTypeDef smhspi5;
void SPI5_Init(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	smhspi5.Instance = SPI5;
	smhspi5.Init.Mode = SPI_MODE_MASTER;
	smhspi5.Init.Direction = SPI_DIRECTION_2LINES;
	smhspi5.Init.DataSize = SPI_DATASIZE_8BIT;
	smhspi5.Init.CLKPolarity = SPI_POLARITY_HIGH;
	smhspi5.Init.CLKPhase = SPI_PHASE_2EDGE;
	smhspi5.Init.NSS = SPI_NSS_SOFT;
	smhspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	smhspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
	smhspi5.Init.TIMode = SPI_TIMODE_DISABLE;
	smhspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	smhspi5.Init.CRCPolynomial = 10;
	APPLICATION_ASSERT(HAL_SPI_Init(&smhspi5) == HAL_OK);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GYRO_CS_PIN_NUM;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GYRO_CS_PORT, &GPIO_InitStruct);
}
//static SPI_HandleTypeDef * ghspi5;
//void Gyro_Import_Hspi5(SPI_HandleTypeDef * ihspi5){
//	ghspi5 = ihspi5;
//	APPLICATION_ASSERT(ghspi5 == ihspi5);
//}

void Gyro_Init(){
	SPI5_Init();

	HAL_Delay(500);

	Gyro_Power_On();

	HAL_Delay(500);
}
void Gyro_Power_On(){
	// Send GYRO_AWAKEN_MESSAGE
//	uint8_t TX_Buffer [] = {GYRO_AWAKEN_MESSAGE, GYRO_AWAKEN_DATA}; // should be 0x820
	uint16_t tx = 0xf20;
	Gyro_Enable_Slave_Comms();
	HAL_StatusTypeDef status = HAL_SPI_Transmit(&smhspi5, (uint8_t*) &tx, 2, 1000);
	Gyro_Disable_Slave_Comms();
	Gyro_Await_Spi_Status(status);
	Gyro_Verify_Spi_Status(status);
}
void Gyro_Enable_Fifo(){
	uint16_t tx = 0xf20;
	HAL_StatusTypeDef status = HAL_SPI_Transmit(&smhspi5, (uint8_t*) &tx, 2, 1000);
	Gyro_Await_Spi_Status(status);
	Gyro_Verify_Spi_Status(status);
}
void Gyro_Get_Id(){
	uint8_t TX_Buffer = GYRO_WHO_AM_I; // should be 0x8f
	uint8_t RX_Buffer[2];
	Gyro_Enable_Slave_Comms();
	HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(&smhspi5, & TX_Buffer, RX_Buffer, 2, HAL_MAX_DELAY);
	Gyro_Disable_Slave_Comms();
	Gyro_Await_Spi_Status(status);
	Gyro_Verify_Spi_Status(status);
//	printf("Junk: %x\n", RX_Buffer[0]);
	printf("ID: %X\n", RX_Buffer[1]);
}
void Gyro_Get_Temp(){
//	uint8_t TX_Buffer = GYRO_OUT_TEMP; // should be 0xa6
	uint16_t tx = 0xa6;
	uint8_t RX_Buffer;
	Gyro_Enable_Slave_Comms();
	HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(&smhspi5, (uint8_t*) &tx, &RX_Buffer, 2, HAL_MAX_DELAY);
	Gyro_Disable_Slave_Comms();
	Gyro_Await_Spi_Status(status);
	Gyro_Verify_Spi_Status(status);
	printf("Temp: %d\n", RX_Buffer);
}
//void Gyro_Config_Reg();
//void Gyro_Read_Reg();
void Gyro_Verify_Spi_Status(HAL_StatusTypeDef status){
	APPLICATION_ASSERT(status == HAL_OK);
}
void Gyro_Await_Spi_Status(HAL_StatusTypeDef status){
	while (status == HAL_BUSY){
		continue;
	}
}

void Gyro_Enable_Slave_Comms(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET); // Pull The cs pin low to set spi mode
	// await actual turn on
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1) != GPIO_PIN_RESET){
		continue;
	}
}
void Gyro_Disable_Slave_Comms(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET); // Pull The cs pin low to set spi mode
	// await actual turn on
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1) != GPIO_PIN_SET){
		continue;
	}
}

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
void Gyro_Write(uint8_t addr, uint8_t data){
	uint8_t  tx [2] = {(GYRO_WRITE_BIT | addr) , data};

	Gyro_Enable_Slave_Comms();
	HAL_StatusTypeDef status = HAL_SPI_Transmit(&smhspi5, (uint8_t*) &tx, 2, 1000);
	Gyro_Disable_Slave_Comms();
	Gyro_Await_Spi_Status(status);
	Gyro_Verify_Spi_Status(status);

	uint8_t returnedData = Gyro_Read(addr);
	if (returnedData != data){
		printf("\n\nFailure to Write, Sent: %X But Got: %X\n\n",data, returnedData);
	}
}
uint8_t Gyro_Read(uint8_t addr){
	uint8_t tx = (GYRO_READ_BIT | addr);

	uint8_t RX_Buffer[2];
	Gyro_Enable_Slave_Comms();
	HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(&smhspi5, & tx, RX_Buffer, 2, HAL_MAX_DELAY);
	Gyro_Disable_Slave_Comms();
	Gyro_Await_Spi_Status(status);
	Gyro_Verify_Spi_Status(status);

	return RX_Buffer[1];
}

void Gyro_Init(){
	SPI5_Init();

	HAL_Delay(500);

	Gyro_Power_On();
	Gyro_Enable_Fifo();

	HAL_Delay(500);
}
void Gyro_Power_On(){
	// Set on bit and bandwith to 01 leaving the rest default
	Gyro_Write(GYRO_CTRL_REG1, 0b00011000);
}
void Gyro_Enable_Fifo(){
	uint8_t temp = Gyro_Read(0b0100100);
	temp |= 0b01000000;
	Gyro_Write(0b0100100, temp);
}
void Gyro_Get_Id(){
	printf("ID: %X\n", Gyro_Read(GYRO_WHO_AM_I));
}
int16_t convert_to_celsius(int8_t sensor_value) {
    // celcius
    const int16_t TEMP_MIN = -40;
    const int16_t TEMP_MAX = 85;

    const int16_t temp_range = TEMP_MAX-TEMP_MIN;
    const int16_t sensor_range = 255;

    int16_t temperature_celsius = TEMP_MAX - ((sensor_value + (sensor_range/2)) * temp_range) / sensor_range;

    return temperature_celsius;
}
void Gyro_Get_Temp(){
	int8_t temp = Gyro_Read(0b0100110);
	printf("Temperature: %d deg C\n", convert_to_celsius(temp));
}
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

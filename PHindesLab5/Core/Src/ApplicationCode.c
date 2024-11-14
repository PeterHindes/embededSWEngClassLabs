/*
 * ApplicationCode.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <ApplicationCode.h>

void applicationInit(){
	printf("\nInitializing Gyro\n");
	Gyro_Init();
	printf("Done\n");
	printf("\nInitializing Button\n");
	BUT_Init();
	printf("Done\n");
}


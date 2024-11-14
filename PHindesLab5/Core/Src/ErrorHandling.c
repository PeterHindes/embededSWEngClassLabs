/*
 * ErrorHandling.c
 *
 *  Created on: Oct 29, 2024
 *      Author: user
 */

#include <ErrorHandling.h>

void APPLICATION_ASSERT(bool pass){
	if(!pass) {
		printf("\n\nAsert Failed!!!!\n");
		__disable_irq();
	}
	while (!pass){
		continue;
	}
}

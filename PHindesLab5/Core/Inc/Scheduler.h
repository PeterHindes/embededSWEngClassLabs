/*
 * Scheduler.h
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

// Bit mask to be used with the and operator to isolate the desired bit or with the or operator to set that bit
#define LED_TOGGLE_EVENT (1 << 0)
#define DELAY_EVENT (1 << 1)
#define POLL_BTN_EVENT (1<<2)

uint32_t getScheduledEvents();
void addSchedulerEvent(uint32_t event);
void removeSchedulerEvent(uint32_t event);

#endif /* SCHEDULER_H_ */

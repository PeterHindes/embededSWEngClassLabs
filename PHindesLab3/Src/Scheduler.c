/*
 * Scheduler.c
 *
 *  Created on: Sep 12, 2024
 *      Author: user
 */

#include <Scheduler.h>

// a number who's bits represent the scheduled events
static uint32_t scheduledEvents;

void addSchedulerEvent(uint32_t event) {
	scheduledEvents |= event;
}

void removeSchedulerEvent(uint32_t event) {
	scheduledEvents &= ~event;
}

uint32_t getScheduledEvents() {
	return scheduledEvents;
}

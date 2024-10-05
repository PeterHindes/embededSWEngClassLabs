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
	// TODO could add code to check if the event is a single bit / a valid event but it would be slow
	scheduledEvents |= event;
}

void removeSchedulerEvent(uint32_t event) {
	scheduledEvents &= ~event;
}

uint32_t getScheduledEvents() {
	return scheduledEvents;
}

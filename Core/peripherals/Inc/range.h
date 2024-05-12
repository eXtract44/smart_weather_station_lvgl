
#ifndef PERIPHERALS_INC_DISTANCE_H_
#define PERIPHERALS_INC_DISTANCE_H

#define RANGE_STEP 12 // in cm
#define RANGE_MAX RANGE_STEP * 2 + 1 // in cm

#define RANGE_0 0
#define RANGE_1 1
#define RANGE_2 2

uint16_t read_standby_time();
void range_handler();

#endif /* PERIPHERALS_INC_DISTANCE_H_ */
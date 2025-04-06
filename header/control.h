#ifndef CONTROL_H
#define CONTROL_H
#include "init.h"

// control function prototypes
void set_filter(struct LPFilter_2 *filter, float fc, float Q);
void set_volume(float *buffer, int length, float dB);

#endif

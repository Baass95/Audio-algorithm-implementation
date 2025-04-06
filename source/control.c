#include "control.h"
#include "config.h"

void set_volume(float *buffer, int length, float dB) {
    float gain = pow(10,dB/20);
    // Should have implemented gradual volume changes to prevent audible clicks
    for (int i = 0; i < length; i++) {
        buffer[i] *= gain;
    }
}


void set_filter(struct LPFilter_2 *filter, float fc, float Q) {
    // bilinear transformation (from - Audio EQ Cookbook)
    filter->w0 = 2*PI*fc/(SAMPLE_RATE);
    filter->alpha = sin(filter->w0)/(2*Q);
    float b0 = (1 - cos(filter->w0))/2;
    float b1 = 1 - cos(filter->w0);
    float b2 = (1 - cos(filter->w0))/2;
    float a0 = 1 + filter->alpha;
    float a1 = -2*cos(filter->w0);
    float a2 = 1 - filter->alpha;
    // normalize the filter to have a[0] = 1
    filter->b[0] = b0/a0;
    filter->b[1] = b1/a0;
    filter->b[2] = b2/a0;
    filter->a[0] = 1;
    filter->a[1] = a1/a0;
    filter->a[2] = a2/a0;
}
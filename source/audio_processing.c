#include "audio_processing.h"
#include "control.h"
#include "config.h"

void audio_processing(struct LPFilter_2 *filter, float *x_packet,int packet_number,float *y){
    for (int i = 0; i < PACKET_SIZE; i++) {
        y[PACKET_SIZE*packet_number + i] = filter->b[0]*x_packet[i] + filter->b[1]*filter->x1 + filter->b[2]*filter->x2 - filter->a[1]*filter->y1 - filter->a[2]*filter->y2;
        // update the state variables
        filter->x2 = filter->x1;
        filter->x1 = x_packet[i];
        filter->y2 = filter->y1;
        filter->y1 = y[PACKET_SIZE*packet_number + i];
    }
}


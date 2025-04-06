
#include "init.h"
#include "control.h"
#include "audio_processing.h"
#include "config.h"

int main() {
    float y[2*NUMBER_SAMPLES]; // filter's output
    struct LPFilter_2 filter;
    struct VolumeFader fader;
    float Q = 1.493; // quality factor
    float fc = 1135; // cutoff frequency


    float *x = init(&filter,&fader);
    set_filter(&filter,fc,Q);

    for (int packet_number = 0; packet_number < 2*NUMBER_SAMPLES/PACKET_SIZE; packet_number++) {
        audio_processing(&filter,x + packet_number*PACKET_SIZE,packet_number,y);
    }
    set_volume(y,2*NUMBER_SAMPLES,fader.dB);
    
    free(x);

    return 0;
}

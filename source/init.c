#include "init.h"
#include "config.h"


float* init(struct LPFilter_2 *filter, struct VolumeFader *fader) {
    init_filter(filter);
    init_fader(fader,0);
    float *buffer_ch1 = generate_sine(100,-6); // 1000 Hz -6 dBFS
    float *buffer_ch2 = generate_sine(1000,-10); // 100 Hz -10 dBFS
    float *buffer = synthesize(buffer_ch1,buffer_ch2);

    free(buffer_ch1);
    free(buffer_ch2);

    return buffer;
}


void init_filter(struct LPFilter_2 *filter) {
    filter->a[0] = 1;
    filter->a[1] = 0;
    filter->a[2] = 0;
    filter->b[0] = 0;
    filter->b[1] = 0;
    filter->b[2] = 0;
    filter->y1 = 0;
    filter->y2 = 0;
    filter->x1 = 0;
    filter->x2 = 0;
    filter->w0 = 0;
    filter->alpha = 0;
}

void init_fader(struct VolumeFader *fader,float dB) {
    fader->dB = dB; 
    fader->gain = pow(10,dB/20);  
}

float* generate_sine(float freq,float dB){
    float* buffer = (float*)malloc(NUMBER_SAMPLES * sizeof(float));
    float gain = pow(10,dB/20);
    for (int i = 0; i < NUMBER_SAMPLES; i++) {
        buffer[i] = gain*sin(2*PI*freq*i/SAMPLE_RATE);
    }

    return buffer;
}

float* synthesize(float *buffer_1, float *buffer_2){
        float* buffer = (float*)malloc(2*NUMBER_SAMPLES * sizeof(float));
        for (int i = 0; i < NUMBER_SAMPLES; i++) {
            buffer[2*i] = buffer_1[i];
            buffer[2*i+1] = buffer_2[i];
        }
        return buffer;
}


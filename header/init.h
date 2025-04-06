#ifndef INIT_H
#define INIT_H

struct LPFilter_2{ 
    float a[3]; // denominator coefficients 
    float b[3]; // numerator coefficients
    float y1; // y[n-1]
    float y2; // y[n-2]
    float x1; // x[n-1]
    float x2; // x[n-2]
    float w0; // normalized angular frequency 
    float alpha; // factor
};

struct VolumeFader{
    float gain; // linear gain factor
    float dB; // gain in dB
};



float* init(struct LPFilter_2 *filter, struct VolumeFader *fader);
void init_filter(struct LPFilter_2 *filter);
void init_fader(struct VolumeFader *fader,float dB);
float* synthesize(float *buffer_1, float *buffer_2);
float* generate_sine(float freq, float dB);

#endif // INIT_H
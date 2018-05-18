#include "MainHeaders.h"

int main(){
    float *d;

    d = Measurement();

    for(int i =0; i<200; i++){
        printf("%f\n",d[i]);
    }
}
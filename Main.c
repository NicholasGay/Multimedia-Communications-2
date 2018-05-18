#include "MainHeaders.h"

int main(){

    float *d;       //Delcerations
    unsigned int sum = 0;

    d = Measurement();
    sum = MeasurementCount(d, sum);
    printf("Sum is : %d\n",sum);
}
#include "MainHeaders.h"

int main(){

    float *d;       //Delcerations
    unsigned int sum = 0;
    float start,width;
    
    start = 0;
    width = 0.1;

    d = Measurement();
    sum = MeasurementCount(d, sum,start,width);
    printf("Sum is : %d\n",sum);
}
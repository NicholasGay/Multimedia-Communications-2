#include "MainHeaders.h"

int main(){

    int i = 0;
    float *d;       //Delcerations
    int sum;
    int NumOfMeasurements = 0;
    float start,width,end;
    width = 0.1;
    end = 2;
    d = Measurement();      //Taking Measurements
    for(start = 0; start <= end; start += 0.1){
         sum = 0;
         NumOfMeasurements = MeasurementCount(d,sum,start,width);   //Summing Measurements
         i++;
         printf("Sum is : %d\n",NumOfMeasurements);
    }
}
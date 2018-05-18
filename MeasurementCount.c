int MeasurementCount(float *data, unsigned int sum){
    for(int i = 0; i < 200; i++){
        if(data[i]>0.2&&data[i]<0.5){
            sum ++;
        }
    }
    return sum;
}
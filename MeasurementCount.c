int MeasurementCount(float *data, unsigned int sum, float start, float width){
    float end = start + width;
    for(int i = 0; i < 200; i++){
        if(data[i]>start&&data[i]<end){
            sum ++;
        }
    }
    return sum;
}
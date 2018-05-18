int MeasurementCount(float *data,int sum, float start, float width){
    printf("MeasurementCount\n");
    float end = start + width;
    for(int i = 0; i < 200; i++){
        if(data[i]>start&&data[i]<end){
            sum ++;
        }
        //printf("Sum is %d\n",sum);
        //printf("index is %d\n",i);
    }
    return sum;
}
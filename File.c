
//int i = 1;
int WriteFile (double data){
    FILE * fpointer;
    fpointer = fopen("Results.txt","a");
    //fprintf(fpointer,"%d ",i);
    fprintf(fpointer,"%f\n",data);
    fclose(fpointer);
    //i ++;
    return 0;
}

int Overwritefile(){
    FILE * fpointer;
    fpointer = fopen("Results.txt","w");
    fprintf(fpointer,"Packet Size %d\n",packetsize);
    fclose(fpointer);
    //i = 1;
    return 0;
}
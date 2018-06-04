int WriteFile (char data[1500]){
    FILE * fpointer;
    fpointer = fopen("Textfile.txt","a");
    fprintf(fpointer,"%s",data);
    fclose(fpointer);
    //i ++;
    return 0;
}

int Overwritefile(){
    FILE * fpointer;
    fpointer = fopen("Textfile.txt","w");
    fclose(fpointer);
    //i = 1;
    return 0;
}

int Readfile(){
    FILE * fpointer;
    fpointer = fopen("Textfile.txt","r");
    
    char output[1500];

    while(fgets(output,1500,fpointer)!=NULL){
        printf("%s\n",output);
    }
    fclose(fpointer);
}
int WriteFile (uint8_t data[]){
    FILE * fpointer;
    fpointer = fopen("Music.mp3","a");
    fwrite(data,1,sizeof(data),fpointer);
    fclose(fpointer);
    
    return 0;
}

int Overwritefile(){
    FILE * fpointer;
    fpointer = fopen("Music.mp3","w");
    fclose(fpointer);
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
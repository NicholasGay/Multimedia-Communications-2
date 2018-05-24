int Test(int sock) {
    printf("Testing...\n");
    char outBuf[1500] = "TEST";
    char inBuf[1500];

    if ( send (sock, outBuf, 800, 0) > 0 ) {
        printf("SENDED\n");
} 

    if(recv(sock, inBuf,1500,0)>0){
        printf("%s\n", inBuf);
        return 0;
    }
    printf("KENA PROBLEM");
    return 0;
}
#include <stdio.h>
#include "connectsock.c"

int Test(int sock) {
    printf("Testing...\n");
    char outBuf[1500] = "TEST";
    char inBuf[1500];
    int count;
    if ( send (sock, outBuf, 800, 0) > 0 ) {
        printf("SENDED\n");
} 

    if(recv(sock, inBuf,1500,0)>0){
        printf("%s\n", inBuf);
        printf("Connection is Successful\n");
        return 0;
    }
    printf("KENA PROBLEM");
    return 0;
}

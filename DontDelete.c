#include <stdio.h>
#include "connectsock.c"

int main() {
    printf("Testing...\n");
    char outBuf[1500] = "TEST";
    char inBuf[1500];
    int count;
    int sock;
    
    sock = connectsock("129.187.223.200", "3000", "udp");

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
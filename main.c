#include "Headers.h"

void main(){
   sock = connectsock("129.187.223.200", "3000", "udp");

  Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);

  while(strcmp(msg,end) != 0){
    recv(sock, msg,1500,0);
    printf("%s\n",msg);
  
  }
  
  
}

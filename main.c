#include "Headers.h"

void main(){
   sock = connectsock("129.187.223.200", "3000", "udp");

  Test(sock);       //Testing program

  char command[1500] = "TEXT";
  char msg[1500];
  char end[1500] = "END";
  //int packet = 1;
  send(sock,command,1500,0);

  while(msg != end){
    //printf("Packet :%d\n",packet);
    recv(sock, msg,1500,0);
    printf("%s\n",msg);
    //packet++;
  }
  
  
}

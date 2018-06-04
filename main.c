#include "Headers.h"

void main(){

  Overwritefile(); 
  sock = connectsock("129.187.223.200", "3000", "udp");

  Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);

  while(1){
    recv(sock, msg,1500,0);
    if(strcmp(msg,end) == 0){
      break;
    }
    WriteFile(msg);
    
  }
  Readfile();
  
}

#include "Headers.h"

void main(){
  //Creating file object
  FILE *fp;
  fp = fopen("Music.mp3","w");

  sock = connectsock("129.187.223.200", "3000", "udp");

  Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);
  int index = 0;
  while(1){
    recv(sock, msg,1500,0);
    if(strcmp(msg,end) == 0){
      break;
    }
    
    //Storing packet
    input[index].seq = (msg[2]<<8)+msg[3];
    for(int i = 12; i<1500; i++){
        input[index].payload[i-12] = msg[i];
    }
    index++;   
  }

  for(int i=0;i<index;i++){
    if(input[i].seq = i){
      fwrite(input[i].payload,1,1500,fp);
    }
    else{
      int j = i;
      while(input[j].seq != i){
        j++;
        if(input[j].seq == i){
          fwrite(input[j].payload,1,1500,fp);
          i++;
          break;
        }
      }
    }
  }
 
}

#include "Headers.h"

void main(){
  //Creating file object
  FILE *fp;
  fp = fopen("Music.mp3","wb");

  sock = connectsock("129.187.223.200", "3000", "udp");

  Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);
  int index = 0;
  while(1){
    input[index].payload_size = recv(sock, msg,1500,0) -12;
    if(strcmp(msg,end) == 0){
      printf("index : %d\n",index);
      break;
    }
    
    //Storing packet
    input[index].seq = (msg[2]<<8)+msg[3];
    //printf("input[%d].seq is %d\n:",index,input[index].seq);
    memcpy(input[index].payload,&msg[12],input[index].payload_size);
    index++;   
  }

  struct data temp;
  int swapped;
  while(1){
    swapped = 0;
    for(int i = 0; i<index-1; i++){

      if(input[i].seq > input[i+1].seq){
          temp = input[i];
          input[i] = input[i+1];
          input[i+1] = temp;
          swapped = 1;
      }
    }

    if(swapped == 0){
      break;
    }
  }
      
  

 for(int i = 0; i<index; i++){
   if(input[i].seq != i){
     printf("Wrong\n");
   }
   else{
     fwrite(input[i].payload,1,input[i].payload_size,fp);
   }
 }
 fclose(fp);
 printf("%s\n",input[1].payload);
 
}

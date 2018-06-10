#include "Headers.h"

 void sort(struct data array[],int length){
  struct data temp;
  int swapped;
  while(1){
    swapped = 0;
    for(int i = 0; i<length-1; i++){

      if(array[i].seq > array[i+1].seq){
          temp = array[i];
          array[i] = array[i+1];
          array[i+1] = temp;
          swapped = 1;
      }
    }

    if(swapped == 0){
      break;
    }
  }
}

void Request(struct data array[],int length,int sock){

  for(int i = 0; i<length; i++){
   if(array[i].seq != i){

     char req[1500];
     uint8_t reqmsg[512];
     sprintf(req, "R %d",i);

     printf("Moving elements\n");
     for(int j = length-1; j>i;j--){
       array[j] = array[j-1]; 
     }
     printf("REQUESTING ");
     printf("%s\n", req);

     send(sock,req,1500,0);
     array[i].payload_size = recv(sock,reqmsg,sizeof(reqmsg),0)-12;
     array[i].seq = (reqmsg[2]<<8)+reqmsg[3];
     printf("Received packet number: %d for index %d\n",array[i].seq,i); 
     memcpy(array[i].payload,&reqmsg[12],input[i].payload_size);  
   }
 }
}



void main(){
  //Creating file object
  FILE *fp;
  fp = fopen("Video.264","wb");

  sock = connectsock("129.187.223.200", "3000", "udp");

  Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);
  int index = 0;
  while(1){
    input[index].payload_size = recv(sock, msg,sizeof(msg),0) -12;
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

  //Sorting
  sort(input,index);
  //input code here     

  //Request
  //Request(input,index,sock);

  //Writing
  for(int i = 0; i<index; i++){
     fwrite(input[i].payload,1,input[i].payload_size,fp); 
 }
  fclose(fp);
 
}

#include "Headers.h"

void main(){
   sock = connectsock("129.187.223.200", "3000", "udp");

   if(Test(sock) == 0){
       printf("yay\n");
   }
}
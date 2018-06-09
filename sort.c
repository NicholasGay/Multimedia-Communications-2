#include "Headers.h"
struct data sort(struct data array[]){
  
  //Declarations
  struct data temp;
  int swapped;

  //Sorting

  
  while(1){
    swapped = 0;
    for(int i = 0; i<index-1; i++){

      if(array[i].seq > input[i+1].seq){
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
#include <stdlib.h>
#include <stdint.h>

struct data {
    uint16_t seq;
    uint8_t value; 
    };

struct node{
    int value_of_node;
    struct node* next;
    };
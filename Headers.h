#include <stdio.h>
#include "connectsock.c"
#include "Test.c"


int sock;
char command[1500] = "VIDEO 03689338";

uint16_t seq;
uint8_t msg[512];
uint8_t end[1500] = "END";

struct data{
    uint16_t seq;
    uint8_t payload[512];
    unsigned int payload_size;
};

struct data input[2000];
unsigned int bytes;
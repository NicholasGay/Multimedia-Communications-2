#include <stdio.h>
#include "connectsock.c"
#include "Test.c"


int sock;
char command[1500] = "MUSIC 03689338";

uint16_t seq;
uint8_t msg[1500];
uint8_t end[1500] = "END";

struct data{
    uint16_t seq;
    uint8_t payload[1500];
};

struct data input[2000];
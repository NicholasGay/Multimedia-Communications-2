#include <stdio.h>
#include "connectsock.c"
#include "Test.c"

int sock;
char command[1500] = "TEXT";
char msg[1500];
char end[1500] = "END";
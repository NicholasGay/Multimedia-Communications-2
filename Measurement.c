#define packetsize 800

float Measurement() {
    int i;

    char Msg1[packetsize] = "49 49 Undefeated";
    char Msg2[packetsize] = "Playing Football The Arsenal Way";
    char Mail1[packetsize];
    char Mail2[packetsize];

    int sock;       //Handler for socket
    struct timeval start, end;      //For Gettime
    double t;       //Dispersion Time
    double Rate;       //Bottleneck Rate

    unsigned int Interations = 200;       //Number of Interations
    
    sock = connectsock("129.187.223.200", "2000", "udp");       //Creating Socket

    if(Test(sock)==0){
        for(i=1;i<=Interations;i++){

            send(sock,Msg1,packetsize,0);       //Sending first packet
            send(sock,Msg2,packetsize,0);       //Sending Second packet
            if(recv(sock,Mail1,packetsize,0)>0){
                gettimeofday(&start,NULL);      //Time starts on receiving first packet
            }
            if(recv(sock,Mail2,packetsize,0)>0){
                gettimeofday(&end,NULL);        //Time ends on receiving second packet
            }
            
            t = end.tv_usec - start.tv_usec;      //Calculating Dispersion Time
            Rate = packetsize/t;                    //Calculating Rate
            Data[i-1] = Rate;
            
            
        }
    }
    return 0;
}
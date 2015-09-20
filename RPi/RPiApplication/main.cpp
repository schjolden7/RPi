/* 
 * File:   main.cpp
 * Author: schjolden
 *
 * Created on 5. september 2015, 19:20
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include "tcp.h"
#include "blink.h"


int main(int argc, char *argv[])
{
    time_t ticks; 
    tcp_init();
    blink_setup();
    
    while(1)
    {
        tcp_handler();
        sleep(1);
    }
    blink_close();
}




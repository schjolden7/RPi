#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include "blink.h"
#include "tcp.h"

static int listenfd, connfd, n;
static struct sockaddr_in serv_addr; 

static char sendBuff[1024];
static char recBuffer[1024];
/*max message lengt is set to 512 bytes*/
static char messageBuffer[512];
static void clear_buffer(char *buffer);
void tcp_init(){
    listenfd = 0;
    connfd = 0;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10);

}

void tcp_handler(){
    int i = 0;
    static int ON_OFF = OFF;
    
    printf("hello \n");
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        
    n = recvfrom(connfd,recBuffer,(sizeof(recBuffer)-1),0,(struct sockaddr *)NULL,NULL);
        
    /*sort out the message string*/
    for(i = 0; i < (sizeof(recBuffer)-1); i++){
        /*search trough buffer to look for end of message*/
        if(recBuffer[i] == '\n')
            break;
        else
            messageBuffer[i] = recBuffer[i];
    }
       
    printf("recv from buffer %s, message %s \n" , recBuffer, messageBuffer);
        
    if(messageBuffer[0] != 'L'){
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n",messageBuffer/*ctime(&ticks)*/);
        write(connfd, sendBuff, strlen(sendBuff)); 
    }else{
        if(ON_OFF == OFF){
            printf("LED_ON\n");
            blink_set_high();
            ON_OFF = ON;
        }else{
            printf("LED_OFF\n");
            blink_set_low();
            ON_OFF = OFF;
        }
        
    }
    close(connfd);
            
    clear_buffer(messageBuffer);
    
}
static void clear_buffer(char *buffer){
    int i = 0;
    for(i = 0; i < sizeof(buffer); i++)
        buffer[i] = 0;
}
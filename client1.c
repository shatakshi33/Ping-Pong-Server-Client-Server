#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[])
{
	int sockfd=0,connfd=0;
	struct sockaddr_in serv_addr;
	char s[1024];
	char recvBuff[1024];
	//char ip[30];
 	if(argc != 2)
    	{
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    	} 
       
	memset(&serv_addr,'0',sizeof(serv_addr));
	memset(recvBuff,'0',sizeof(recvBuff));
	sockfd = socket(AF_INET, SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Socket did not created\n");
		return 1;
	}
	serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(5003); 
	printf("Server ip is %s\n",argv[1]);
	if(inet_pton(AF_INET,argv[1],&serv_addr.sin_addr)<=0)
	{
		printf("\n inet_pton error occured\n");
        	return 1;
        }
        connfd=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(connfd<0)
	{
		printf("\nconnection failed\n");
		return 1;
	}
        while(1)
        {
        	read(sockfd,recvBuff,1000);
		printf("\nServer : %s\n",recvBuff);
		scanf("%s",s);
		write(sockfd,s,1000);
	}	
}

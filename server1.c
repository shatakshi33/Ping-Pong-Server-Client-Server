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
	int listenfd=0,connfd=0;
	struct sockaddr_in serv_addr;
	char s[1024];
	char sendBuff[1024];
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	memset(&serv_addr,'0',sizeof(serv_addr));
	memset(sendBuff,'0',sizeof(sendBuff));
	serv_addr.sin_family = AF_INET;
   	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	serv_addr.sin_port = htons(5003);
	bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	listen(listenfd,3);

		connfd = accept(listenfd,(struct sockaddr *)NULL, NULL);
		printf("Hello\n");
		while(1)
		{
		scanf("%s",sendBuff);
		write(connfd,sendBuff,1000);
		read(connfd,s,1000);
		printf("\nclient : %s\n",s);
		}
		
		close(connfd);
}

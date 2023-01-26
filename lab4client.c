#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char*argv[])
{
 int socket_desc;
 struct sockaddr_in server;
 char user_input[1024];

 //Create socket

 socket_desc = socket(AF_INET,SOCK_STREAM, 0);
 

 server.sin_addr.s_addr=inet_addr("192.168.217.135");
 server.sin_family=AF_INET;
 server.sin_port=htons(8080);

 //Connect to remote server

 connect(socket_desc,(struct sockaddr*)&server, sizeof(server));

 printf("Enter a string:");
 scanf("%s", user_input);
 send(socket_desc, user_input, strlen(user_input), 0);

 char buffer[1024];
 int bytes_received = recv(socket_desc, buffer, sizeof(buffer),0);
 buffer[bytes_received] = '\0';
 printf("Received from server: %s\n", buffer);


 return 0;
}

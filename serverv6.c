/*
 * Khushboo Tekchandani
 * Test if we can create multiple connections via separate interfaces
 * Server part of the program
 */

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#define BUFFERSIZE 256
#define MAXCLIENTS 5

int main(int argc, char **argv){

   int server_sock, server_port, client_sock;
   socklen_t client_len;
   char *interface = argv[1];

   struct sockaddr_in server_addr, client_addr;

   char message_buffer[BUFFERSIZE];
   int message_size;

   if (argc != 3){
      printf ("Usage: ./server <portno>\n");
      exit(1);
   }

   /*Local port*/
   server_port = atoi(argv[2]);
   /*Create a socket*/
   server_sock = socket(AF_INET6, SOCK_STREAM, 0);
   if (server_sock < 0){
      perror("socket:");
      exit(1);
   }

   /*Construct server_addr*/
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET6; /*Internet address*/
   server_addr.sin_port = htons(server_port);

   setsockopt(server_sock, SOL_SOCKET, SO_BINDTODEVICE, interface, strlen(interface));

   /*bind server_addr to the socket*/
   if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) <
         0){
      perror("bind:");
      exit(1);
   }

   /*listen on the socket for clients*/
   if (listen(server_sock, MAXCLIENTS) < 0){
      perror("listen:");
      exit(1);
   }

   client_len = sizeof(client_addr);

   /*accept client connection*/
   if ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, 
               &client_len)) < 0){ 
      perror("accept:");
      exit(1);  
   }

   printf ("Receiving messages\n");

   while(1){

      memset(message_buffer, 0, sizeof(message_buffer));
      if ((message_size = recv(client_sock, message_buffer, BUFFERSIZE, 0)) <
            0){
         perror("recv:");
         exit(1);
      }

      if (message_size == 0){
         printf ("Exiting...\n");
         close(client_sock);
         break;
      }

      else
         printf("%s\n", message_buffer);

   }

   return 0;
}


#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUFFERSIZE 50
#define LATENCY 5

int main(int argc, char** argv){

   int server_sock, server_port;

   struct sockaddr_in server_addr;
   char* server_ip;

   char message_buffer[BUFFERSIZE];
   int message_size;

   if(argc != 3){
      printf("Usage: ./client <server ip> <port>\n");
      exit(1);
   }

   /*Inputs from commandline*/
   server_ip = argv[1];
   server_port = atoi(argv[2]);

   /*Create socket*/
   if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
      perror("socket:");
      exit(1);
   }

   /*Construct server_addr*/
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = inet_addr(server_ip);
   server_addr.sin_port = htons(server_port);

   /*Establish connection*/
   if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
      perror("connect:");
      exit(1);
   }

   printf ("Initiating message passing service.\n");

   while(1) {

      /*Get message from the console*/
      printf ("Enter your message:\n");
      memset (message_buffer, 0, sizeof(message_buffer));
      fgets (message_buffer, sizeof(message_buffer), stdin);
      message_size = strlen(message_buffer);

      if (strcasecmp (message_buffer, "quit\n") == 0){
         if (send(server_sock, message_buffer, message_size, 0) != message_size){
            perror("send:");
            exit(1);
         }
         printf ("Exiting...\n");
         break;
      }

      else {

         if (send(server_sock, message_buffer, message_size, 0) != message_size){
            perror("send:");
            exit(1);
         }

      }
   }

   close(server_sock);
   return 0;
}

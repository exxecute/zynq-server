#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BYTE_MASK               (0xFFU)
#define BITS_IN_BYTE            (8U)
#define GET_BYTE(reg, shift)    ((reg >> (shift * BITS_IN_BYTE)) & BYTE_MASK)

#define PORT                    (22U)
#define ADDRESS                 ("192.168.122.115") // server address
#define MAXLINE                 (1024U)

int main(void) 
{
        printf("Zynq server (15.1654)\n");
        int sockfd;
        char buffer[MAXLINE];
        char *hello = "Hello from server";
        struct sockaddr_in servaddr, cliaddr;
 
        printf("Creating socket file descriptor\n");
        if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
                printf("socket creation failed\n");
                exit(EXIT_FAILURE);
        }
 
        memset(&servaddr, 0, sizeof(servaddr));
        memset(&cliaddr, 0, sizeof(cliaddr));

        printf("Filling server information\n");
        servaddr.sin_family = AF_INET; // IPv4 
        servaddr.sin_addr.s_addr = inet_addr;
        servaddr.sin_port = htons(PORT);
        printf("IPv4 req: %s:%d\n", ADDRESS, PORT);

        printf("Bind the socket with the server address\n");
        printf("sockfd: %d\n", sockfd);
        uint32_t bind_answer = bind(sockfd, (const struct sockaddr *)&servaddr,
                        sizeof(servaddr));
        if (bind_answer < 0 )
        {
            printf("bind failed error: %d\n", bind_answer);
            exit(EXIT_FAILURE);
        }
 
        int len, n,cport;
        char addr_buffer[20];
        n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                                &len);
        buffer[n] = '\0';
        printf("Client : %s\n", buffer);
        inet_ntop(AF_INET,&(cliaddr.sin_addr.s_addr),addr_buffer,len);
        cport=ntohs(cliaddr.sin_port);
        printf("caddr=%x\n",cliaddr.sin_addr.s_addr);
        printf("addr=%s, len=%d\n",addr_buffer,len);
        printf("c family=%d\n",cliaddr.sin_family);
        printf("c port=%d and=%d\n",cliaddr.sin_port,cport);
        sendto(sockfd, (const char *)hello, strlen(hello),
                MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
                        len);
        printf("Hello message sent.\n");
 
        return 0;
}
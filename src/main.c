#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BYTE_MASK   (0xFFU)
#define GET_BYTE(reg, shift)    ((reg >> shift) & BYTE_MASK)

#define PORT        (22U)
#define ADDRESS     (0xC2A87A73U)
#define MAXLINE     (1024U)

int main(int argc,char** argv) {
        printf("Zynq server (15.1430)\n");
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
        servaddr.sin_addr.s_addr = ADDRESS;
        servaddr.sin_port = htons(PORT);
        printf("IPv4 req: %d.%d.%d.%d:%d\n", GET_BYTE(ADDRESS, 3), GET_BYTE(ADDRESS, 2),
        GET_BYTE(ADDRESS, 1), GET_BYTE(ADDRESS, 0), PORT);
        printf("IPv4 : %d.%d.%d.%d:%d\n", GET_BYTE(servaddr.sin_addr.s_addr, 3), GET_BYTE(servaddr.sin_addr.s_addr, 2),
        GET_BYTE(servaddr.sin_addr.s_addr, 1), GET_BYTE(servaddr.sin_addr.s_addr, 0), servaddr.sin_port);
 
        int sport;
        if(argc>1)
        {
            int sport;
            sscanf(argv[1],"%d",&sport);
            printf("port is %d\n",sport);
            servaddr.sin_port=htons(sport);
        }

        printf("Bind the socket with the server address\n");
        printf("sockfd: %d", sockfd);
        if ( bind(sockfd, (const struct sockaddr *)&servaddr,
                        sizeof(servaddr)) < 0 )
        {
                printf("bind failed\n");
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
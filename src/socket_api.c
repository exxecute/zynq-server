#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#include "socket_api.h"


int SOCKET_API_create_file_desc(int __domain, int __type, int __protocol)
{
    int _sockfd;
    printf("[Socket API] Creating socket file descriptor\n");
    printf("[Socket API] Domain: %d\n", __domain);
    printf("[Socket API] Type: %d\n", __type);
    printf("[Socket API] Protocol: %d\n", __protocol);
    if ( (_sockfd = socket(__domain, __type, __protocol)) < 0 ) {
        printf("[Socket API] ERROR! Socket creation failed\n");
    }
    else
    {
        printf("[Socket API] Socket creation success\n");
    }
    return _sockfd;
}

int SOCKET_API_bind_socket(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
{
    int answer = true;
    printf("[Socket API] Bind the socket with the server address\n");
    if(bind(__fd, __addr, __len) < 0)
    {
        printf("[Socket API] ERROR! Bind failed\n");
        answer = false;
    }
    else
    {
        printf("[Socket API] Bind success\n");
    }
    return answer;
}

ssize_t SOCKET_API_wait_message(int __fd, void *__restrict __buf, size_t __n,
            __SOCKADDR_ARG __addr,
            socklen_t *__restrict __addr_len)
{
    printf("[Socket API] wait answer...\n");
    int recieve_bytes = 0;
    recieve_bytes = recvfrom(__fd, (uint8_t*) __buf, __n, MSG_WAITALL,
    ( struct sockaddr *) &__addr, &__addr_len);
}

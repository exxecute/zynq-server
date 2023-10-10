#ifndef SOCKET_H
#define SOCKET_H

#include <netinet/in.h>


#define SOCKET_MAXIMUM_BUFFER_SIZE      (64U)

typedef struct SOCKET_t
{
    int sockfd;
    struct sockaddr_in address;
}SOCKET_t;

typedef struct CLIENT_t
{
    struct sockaddr_in address;
    int address_len;
    uint8_t buffer[SOCKET_MAXIMUM_BUFFER_SIZE];
    uint32_t buffer_size;
}CLIENT_t;

void SOCKET_init_socket(SOCKET_t *this, uint32_t __address, uint32_t __port);
void SOCKET_wait_message(SOCKET_t *this, CLIENT_t *__client);
uint32_t SOCKET_send_message(SOCKET_t *this, CLIENT_t *__client, uint8_t *__buffer, uint32_t __size);
void SOCKET_close_socket(SOCKET_t *this);

#endif /* SOCKET_H */
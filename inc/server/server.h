#ifndef SERVER_H
#define SERVER_H

#include "socket.h"

#define MAXIMUM_CLIENTS     (10U)

typedef struct SERVER_ANSWERS_t
{
    uint32_t size;
    uint8_t buffer[SOCKET_MAXIMUM_BUFFER_SIZE];
}SERVER_ANSWERS_t;

typedef struct SERVER_t
{
    struct CLIENT_t clients[MAXIMUM_CLIENTS];
    struct SERVER_ANSWERS_t answers[MAXIMUM_CLIENTS];
    struct SOCKET_t recieve_socket;
    struct SOCKET_t answer_socket;
}SERVER_t;

void SERVER_init_server(SERVER_t *this, char *__address, uint32_t __recieve_port, uint32_t __answer_port);

void SERVER_wait_message(SERVER_t *this);

void SERVER_send_message(SERVER_t *this, uint32_t __client_index);

#endif /* SERVER_H */
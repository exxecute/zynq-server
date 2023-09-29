#include "server.h"

void SERVER_init_server(SERVER_t *this, char *__address, uint32_t __recieve_port, uint32_t __answer_port)
{
    SOCKET_init_socket(&this->recieve_socket, inet_addr(__address), __recieve_port);
}

void SERVER_wait_message(SERVER_t *this)
{
    SOCKET_wait_message(&this->recieve_socket, &this->clients[0]);
}
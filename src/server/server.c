#include "server.h"

void SERVER_init_server(SERVER_t *this, char *__address, uint32_t __recieve_port, uint32_t __answer_port)
{
    SOCKET_init_socket(&this->recieve_socket, inet_addr(__address), __recieve_port);
//    SOCKET_init_socket(&this->answer_socket, inet_addr(__address), __answer_port);
}

void SERVER_wait_message(SERVER_t *this)
{
    SOCKET_wait_message(&this->recieve_socket, &this->clients[0]);
    printf("package: ");
    for(int byte = 0; byte < this->clients[0].buffer_size; byte++)
    {
        printf("%X ", this->clients[0].buffer[byte]);
    }
    printf("\n");
}

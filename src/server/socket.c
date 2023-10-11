#include <sys/socket.h>

#include "socket.h"
#include "stdbool.h"


static void _create_file_descriptor(SOCKET_t *this, int __domain, int __type, int __protocol)
{
    printf("[Socket API] Creating socket file descriptor\n");
    if ( (this->sockfd = socket(__domain, __type, __protocol)) < 0 ) {
        printf("[Socket API] ERROR! Socket creation failed\n");
    }
    else
    {
        printf("[Socket API] Socket creation success\n");
    }
}

static int _bind_socket(SOCKET_t *this)
{
    int answer = true;
    printf("[Socket API] Bind the socket with the server address\n");
    if(bind(this->sockfd, (const struct sockaddr *)&this->address, sizeof(this->address)) < 0)
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

static void _filling_server_info(SOCKET_t *this, uint32_t __address, uint32_t __port)
{
    printf("[Server API] Filling server information\n");
    printf("IPv4 req: %X:%d\n", __address, __port);

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = __address;
    this->address.sin_port = htons(__port);
}

void SOCKET_init_socket(SOCKET_t *this, uint32_t __address, uint32_t __port)
{
    _create_file_descriptor(this, AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    memset(&this->address, 0, sizeof(this->address));

    _filling_server_info(this, __address, __port);

    _bind_socket(this);
}

void SOCKET_wait_message(SOCKET_t *this, CLIENT_t *__client)
{
	struct sockaddr _client_address;
    char str[INET_ADDRSTRLEN];
    printf("[Socket API] wait answer...\n");
    __client->buffer_size = recvfrom(this->sockfd, __client->buffer, SOCKET_MAXIMUM_BUFFER_SIZE,
                MSG_WAITALL, (struct sockaddr*) &(_client_address),
                &__client->address_len);
    memcpy(&__client->address, &_client_address, sizeof(struct sockaddr));
    inet_ntop(AF_INET, &(__client->address.sin_addr), str, INET_ADDRSTRLEN);
    printf("[Socket API] clients IP address: %s\n", str);
}

uint32_t SOCKET_send_message(SOCKET_t *this, CLIENT_t *__client, uint8_t *__buffer, uint32_t __size)
{
    char str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(__client->address.sin_addr), str, INET_ADDRSTRLEN);
    __client->address.sin_port = this->address.sin_port;
    __client->address.sin_family = AF_INET;
    printf("[Socket API] send message to %s...\n", str);
    int _bytes = 0;
    _bytes = sendto(this->sockfd, (uint8_t*) __buffer, __size, MSG_WAITALL,
                (struct sockaddr*) &__client->address, __client->address_len);
    return _bytes;
}

void SOCKET_close_socket(SOCKET_t *this)
{
    close(this->sockfd);
}

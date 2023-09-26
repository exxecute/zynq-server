#include <string.h>

#include "server_api.h"
#include "socket_api.h"
#include "config.h"

#include <stdio.h>
#include <netinet/in.h>

static struct sockaddr_in _server_address;
static struct sockaddr_in _client_address;

static int _sockfd;

void _reset_addresses(void)
{
    memset(&_server_address, 0, sizeof(_server_address));
    memset(&_client_address, 0, sizeof(_client_address));
}

void _filling_server_info(void)
{
    printf("[Server API] Filling server information\n");
    printf("IPv4 req: %s:%d\n", CONFIG_SERVER_ADDRESS, CONFIG_SERVER_PORT);

    _server_address.sin_family = AF_INET; // IPv4 
    _server_address.sin_addr.s_addr = inet_addr(CONFIG_SERVER_ADDRESS);
    _server_address.sin_port = htons(CONFIG_SERVER_PORT);
}

void SERVER_API_init(void)
{
    printf("[Server API] Initializing server\n");

    _sockfd = SOCKET_API_create_file_desc(AF_INET, SOCK_DGRAM, 0);

    _reset_addresses();

    _filling_server_info();

    SOCKET_API_bind_socket(_sockfd, (const struct sockaddr *)&_server_address,
                        sizeof(_server_address));
}

int SERVER_API_wait_message(uint8_t *__buffer, uint32_t size)
{
    printf("[Server API] waiting message..\n");
    int len;
    int bytes = SOCKET_API_wait_message(_sockfd, __buffer, size,
                                ( struct sockaddr *) &_client_address,
                                &len);
    return bytes;
}

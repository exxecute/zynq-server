#include <stdio.h>

#include "banner.h"
#include "server.h"
#include "package_api.h"

#include <string.h>

int main(void) 
{
    printf("%s", BANNER_MAIN);

    printf("Server struct size: %d\n", sizeof(SERVER_t));
    SERVER_t server = {0}; /* need find way to know which client wrote */
    PACKAGE_API_t package_api = {0};

    SERVER_init_server(&server, "192.168.122.115", 22, 23);
    SERVER_wait_message(&server);

    PACKAGE_API_init(&package_api, server.clients[0].buffer, server.clients[0].buffer_size);
    PACKAGE_API_find_package(&package_api);

    printf("recieve message from %X\n", server.clients[0].address);

    printf("recieved and encoded package: ");
    for(int _byte = package_api.start_package_byte; _byte < package_api.stop_package_byte; _byte++)
    {
        printf("%02X ", server.clients[0].buffer[_byte]);
    }
    printf("\n");

    memcpy(server.answers[0].buffer, server.clients[0].buffer + package_api.start_package_byte, server.clients[0].buffer_size + package_api.start_package_byte);
    server.answers[0].size = server.clients[0].buffer_size;


    printf("package to send: ");
    for(int _byte = 0; _byte < server.answers[0].size; _byte++)
    {
        printf("%02X ", server.answers[0].buffer[_byte]);
    }
    printf("\n");

    SERVER_send_message(&server, 0);

    return 0;
}

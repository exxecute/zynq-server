#include <stdio.h>

#include "banner.h"
#include "server.h"
#include "package_api.h"

int main(void) 
{
    printf("%s", BANNER_MAIN);

    printf("Server struct size: %d\n", sizeof(SERVER_t));
    SERVER_t server = {0}; /* need find way to know which client wroted */
    PACKAGE_API_t package_api = {0};

    SERVER_init_server(&server, "192.168.122.115", 22, 23);
    SERVER_wait_message(&server);

    PACKAGE_API_init(&package_api, server.clients[0].buffer, server.clients[0].buffer);
    PACKAGE_API_find_package(&package_api);

    printf("recieved and encoded package: ");
    for(int _byte = package_api.start_package_byte; _byte < package_api.stop_package_byte; _byte++)
    {
        printf("%02X ", server.clients[0].buffer[_byte]);
    }
    printf("\n");

    return 0;
}

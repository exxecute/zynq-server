#include <stdio.h>

#include "banner.h"
#include "server.h"
#include "protocol.h"

#include <string.h>

int main(void) 
{
    printf("%s", BANNER_MAIN);

    printf("Server struct size: %d\n", sizeof(SERVER_t));
    SERVER_t server = {0}; /* need find way to know which client wrote */

    SERVER_init_server(&server, "127.0.0.1", 6000, 6001);
    SERVER_wait_message(&server);

    server.answers[0].size = PROTOCOL_process_message(server.clients[0].buffer, server.clients[0].buffer_size, server.answers[0].buffer);

    printf("[MAIN] package to send: ");
    for(int _byte = 0; _byte < server.answers[0].size; _byte++)
    {
        printf("%02X ", server.answers[0].buffer[_byte]);
    }
    printf("\n");

    SERVER_send_message(&server, 0);

    SERVER_close_server(&server);

    return 0;
}

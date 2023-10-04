#include <stdio.h>

#include "banner.h"
#include "server.h"

int main(void) 
{
    printf("%s", BANNER_MAIN);

    printf("Server struct size: %d\n", sizeof(SERVER_t));
    SERVER_t server = {0};
    SERVER_init_server(&server, "192.168.122.115", 22, 23);
    SERVER_wait_message(&server);

    return 0;
}

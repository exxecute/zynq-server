#include <stdio.h>

#include "banner.h"
#include "server_api.h"

int main(void) 
{
    printf("%s", BANNER_MAIN);

    SERVER_API_init();
    uint8_t buffer[2048] = {0};
    int bytes = SERVER_API_wait_message(buffer, 2048);
    printf("bytes: %d\n", bytes);

    return 0;
}

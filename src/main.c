#include <stdio.h>

#include "banner.h"
#include "server_api.h"

int main(void) 
{
    printf("%s", BANNER_MAIN);

    SERVER_API_init();
    int bytes = SERVER_API_wait_message();
    printf("bytes: %d", bytes);

    return 0;
}

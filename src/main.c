#include <stdio.h>

#include "banner.h"
#include "server_api.h"
#include "message_buffer.h"
#include "slip_api.h"
#include "protocol.h"


#define BUFFERS_SIZE    (64U)


static uint8_t package_buffer[BUFFERS_SIZE] = {0};
static uint8_t package_size = 0;

static uint8_t encrypt_buffer[BUFFERS_SIZE] = {0};
static uint8_t encrypt_size = 0;


int main(void) 
{
    printf("%s", BANNER_MAIN);

    SERVER_API_init();

    while(1)
    {
        package_size = SERVER_API_wait_message(package_buffer, BUFFERS_SIZE);

        MESSAGE_BUFFER_process_data(package_buffer, package_size);
        package_size = MESSAGE_BUFFER_get_package(package_buffer);

        encrypt_size = SLIP_decode(package_buffer, package_size, encrypt_buffer);
        
        package_size = PROTOCOL_process_package(encrypt_buffer, encrypt_size, package_buffer);

        // encrypt_size = SLIP_code(package_buffer, package_size, encrypt_buffer);
        
    }

    return 0;
}

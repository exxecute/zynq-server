#include <stdio.h>

#include "banner.h"
#include "server.h"
#include "protocol.h"

#include <string.h>

int main(void) 
{
    uint8_t buffer[20] = {0};
    uint8_t answer_buffer[20] = {0};
    PROTOCOL_process_message(&buffer, sizeof(buffer), &answer_buffer);

    return 0;
}

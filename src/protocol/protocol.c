#include <stdint.h>
#include <stdbool.h>

#include "protocol.h"
#include "protocol_framebytes.h"

static void _select_protocol_message_type(uint8_t *__package)
{
    PROTOCOL_start_head_t (*_head) = (PROTOCOL_start_head_t*) __package;
    printf("[PROTOCOL] Message type: ");
    switch(_head->code)
    {
        case(PROTOCOL_CODE_TEST):
        {
            printf("test\n");
            break;
        }
        case(PROTOCOL_CODE_FILE):
        {
            printf("file\n");
            break;
        }
        default:
        {
            printf("ERROR!\n");
            break;
        }
    }
}

static uint8_t _validate_package(uint8_t *__package)
{
    PROTOCOL_start_head_t (*_head) = (PROTOCOL_start_head_t*) __package;
    uint8_t _package_size = sizeof(__package) - (sizeof(PROTOCOL_start_head_t) + sizeof(PROTOCOL_end_head_t));

    uint8_t answer = true;
    if(_package_size != _head->package_size)
    {
        answer = false;
    }

    return answer;
}

void PROTOCOL_process_message(uint8_t *__message)
{
    
}
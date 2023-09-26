#include <stdbool.h>

#include "protocol.h"
#include "protocol_framebytes.h"

static uint8_t _process_answer(uint8_t *__package, uint8_t *__answer_package)
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
    return 0;
}

static uint8_t _validate_package(uint8_t *__package, uint8_t __package_size)
{
    PROTOCOL_start_head_t (*_head) = (PROTOCOL_start_head_t*) __package;
    uint8_t _package_size = __package_size - (sizeof(PROTOCOL_start_head_t) + sizeof(PROTOCOL_end_head_t));

    uint8_t answer = true;
    if(_package_size != _head->package_size)
    {
        answer = false;
    }

    return answer;
}

uint8_t PROTOCOL_process_package(uint8_t *__package, uint8_t __package_size, uint8_t *__answer_package)
{
    uint8_t _validation = _validate_package(__package, __package_size);

    uint8_t _answer_size = 0;
    if(_validation)
    {
        _answer_size = _process_answer(__package, __answer_package);
    }

    return _answer_size;
}
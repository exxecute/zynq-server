#include "protocol.h"
#include "protocol_test.h"

#define CODE_INDEX                  (4U)
#define ONE_PROTOCOL_BYTES_AMOUNT   (2U)
#define NO_PACKAGE_CODE             (0xFFU) 

static uint16_t (*protocol_linker)(uint8_t* __buffer, uint8_t* __answer_buffer);
const uint8_t *massive_links[] = {PROTOCOL_TEST_PACKAGE_CODE, PROTOCOL_TEST_PACKAGE_FOO};


static uint16_t _get_package_code(uint8_t* __buffer)
{
    uint16_t _package_code = NO_PACKAGE_CODE;
    for(int code_index = 0; code_index < sizeof(massive_links) / ONE_PROTOCOL_BYTES_AMOUNT; code_index++)
    {
        if(__buffer[CODE_INDEX] == massive_links[PROTOCOL_PACKAGE_CODE(code_index)])
        {
            _package_code = PROTOCOL_PACKAGE_FOO(code_index);
            break;
        }
    }
    return _package_code;
}

uint16_t PROTOCOL_process_message(uint8_t* __buffer, uint16_t __size, uint8_t* __answer_buffer)
{
    PACKAGE_API_t package_api = {0};
    uint16_t _answer_size = 0;

    PACKAGE_API_init(&package_api, __buffer, __size);
    PACKAGE_API_find_package(&package_api);

    uint8_t _package_code = _get_package_code(__buffer + package_api.start_package_byte);

    uint16_t (*protocol_linker)(uint8_t* __buffer, uint8_t* __answer_buffer) = massive_links[_package_code];

    _answer_size = protocol_linker(__buffer, __answer_buffer);

    PACKAGE_API_pack(__answer_buffer, _answer_size);

    return _answer_size;
}

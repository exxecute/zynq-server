#include "protocol.h"
#include "protocol_test.h"

#define CODE_INDEX  (4U)

static uint16_t _test_linker_foo(uint8_t* __buffer, uint8_t* __answer_buffer)
{
    printf("[linker test] succsess!\n");
}

static uint16_t (*protocol_linker)(uint8_t* __buffer, uint8_t* __answer_buffer);
const uint8_t *massive_links[] = {_test_linker_foo,         /* 0x00 */\
                                    PROTOCOL_TEST_process   /* 0x01 */\
                                    };


static uint16_t _get_package_code(uint8_t* __buffer)
{
    return __buffer[CODE_INDEX];
}

uint16_t PROTOCOL_process_message(uint8_t* __buffer, uint16_t __size, uint8_t* __answer_buffer)
{
    PACKAGE_API_t package_api = {0};
    uint16_t _answer_size = 0;

    PACKAGE_API_init(&package_api, __buffer, __size);
    PACKAGE_API_find_package(&package_api);

    uint8_t _package_code = _get_package_code(__buffer + package_api.start_package_byte);

    uint16_t (*protocol_linker)(uint8_t* __buffer, uint8_t* __answer_buffer) = massive_links[1];

    _answer_size = protocol_linker(__buffer, __answer_buffer);

    PACKAGE_API_pack(__answer_buffer, _answer_size);

    return _answer_size;
}

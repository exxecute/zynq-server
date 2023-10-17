#include "protocol.h"
#include "protocol_test.h"

static uint8_t _test_linker_foo(uint8_t* __buffer, uint8_t __size, uint8_t* __answer_buffer)
{
    printf("[linker test] succsess!");
}

static uint8_t (*protocol_linker)(uint8_t* __buffer, uint8_t __size, uint8_t* __answer_buffer);
const uint8_t *massive_links[] = {_test_linker_foo, PROTOCOL_TEST_process};


static uint8_t _get_package_code(uint8_t* __buffer, uint16_t __size)
{
}

uint16_t PROTOCOL_process_message(uint8_t* __buffer, uint16_t __size, uint8_t* __answer_buffer)
{
    PACKAGE_API_t package_api = {0};
    uint16_t _answer_size = 0;

    PACKAGE_API_init(&package_api, __buffer, __size);
    PACKAGE_API_find_package(&package_api);

    uint8_t _package_code = _get_package_code(__buffer + package_api.start_package_byte, \
            package_api.start_package_byte + package_api.stop_package_byte);

    uint8_t (*protocol_linker)(uint8_t* __buffer, uint8_t __size, uint8_t* __answer_buffer) = massive_links[_package_code];

    _answer_size = protocol_linker(__buffer + package_api.start_package_byte, \
            package_api.start_package_byte + package_api.stop_package_byte, __answer_buffer);

    return _answer_size;
}

void PROTOCOL_init(void)
{

}
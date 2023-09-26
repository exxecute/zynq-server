#include "protocol_test.h"


#define TEST_BYTE_ANSWER                    (0xab)


static void _print_test_byte(PROTOCOL_TEST_request_t *__request_package)
{
    printf("[PROTOCOL TEST] Test byte: %x\n", __request_package->print_data);
}

static void _fill_answer_package(PROTOCOL_TEST_answer_t *__answer_package)
{
    __answer_package->start_head.start = START_BYTE;
    __answer_package->start_head.package_size = PROTOCOL_TEST_ANSWER_SIZE;
    __answer_package->start_head.code = PROTOCOL_GET_ANSWER(PROTOCOL_CODE_TEST);
    __answer_package->print_data = TEST_BYTE_ANSWER;
    __answer_package->end_head.end_byte = END_BYTE;
}


uint8_t PROTOCOL_TEST_process_package(PROTOCOL_TEST_request_t *__request_package, PROTOCOL_TEST_answer_t *__answer_package)
{
    _print_test_byte(__request_package);
    _fill_answer_package(__answer_package);
    return sizeof(PROTOCOL_TEST_answer_t);
}
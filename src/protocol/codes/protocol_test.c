#include "protocol_test.h"

#define TEST_BYTE_ANSWER    (0x55U)

#define CODE                (0x01U)
#define ANSWER              (0X80U)
#define REQUEST             (0x00U)

#define CODE_REQUEST        (CODE + REQUEST)
#define CODE_ANSWER         (CODE + ANSWER)

#define ANSWER_SIZE         (0x0001U)

void _print_test_byte(PROTOCOL_TEST_request_t *this)
{
    printf("[TEST PACKAGE] test byte: %X\n", this->test_byte);
}

void _generate_answer(PROTOCOL_TEST_answer_t *this)
{
    this->start.command_code = CODE_ANSWER;
    this->start.package_size = ANSWER_SIZE;

    this->test_byte = TEST_BYTE_ANSWER;
}

uint16_t PROTOCOL_TEST_process(PROTOCOL_TEST_request_t* __buffer, PROTOCOL_TEST_answer_t* __answer_buffer)
{
    printf("[PROTOCOL] test package\n");

    _print_test_byte(__buffer);
    _generate_answer(__answer_buffer);
    return sizeof(PROTOCOL_TEST_answer_t);
}

#ifndef PROTOCOL_TEST_H
#define PROTOCOL_TEST_H

#include "protocol.h"

typedef struct PROTOCOL_TEST_request_t
{
    struct PROTOCOL_start_head_t start;
    uint8_t test_byte;
    struct PROTOCOL_stop_head_t stop;
}PROTOCOL_TEST_request_t;

typedef struct PROTOCOL_TEST_answer_t
{
    struct PROTOCOL_start_head_t start;
    uint8_t test_byte;
    struct PROTOCOL_stop_head_t stop;
}PROTOCOL_TEST_answer_t;

uint16_t PROTOCOL_TEST_process(PROTOCOL_TEST_request_t* __buffer, PROTOCOL_TEST_answer_t* __answer_buffer);

#endif /* PROTOCOL_TEST_H */

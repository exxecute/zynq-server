#ifndef PROTOCOL_TEST_H
#define PROTOCOL_TEST_H

#include "protocol_framebytes.h"

#define PROTOCOL_TEST_ANSWER_SIZE   (1U)

typedef struct PROTOCOL_TEST_request_t
{
    PROTOCOL_start_head_t start_head;
    uint8_t print_data;
    PROTOCOL_end_head_t end_head;
}PROTOCOL_TEST_request_t;

typedef struct PROTOCOL_TEST_answer_t
{
    PROTOCOL_start_head_t start_head;
    uint8_t print_data;
    PROTOCOL_end_head_t end_head;
}PROTOCOL_TEST_answer_t;

uint8_t PROTOCOL_TEST_process_package(PROTOCOL_TEST_request_t *__request_package, PROTOCOL_TEST_answer_t *__answer_package);

#endif /* PROTOCOL_TEST_H */
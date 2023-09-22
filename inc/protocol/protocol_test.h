#ifndef PROTOCOL_TEST_H
#define PROTOCOL_TEST_H

#include "protocol_framebytes.h"

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


#endif /* PROTOCOL_TEST_H */
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "package_api.h"

#define PROTOCOL_ANSWER              (0X80U)
#define PROTOCOL_REQUEST             (0x00U)

#define PROTOCOL_GET_ANSWER(code)    (code | PROTOCOL_ANSWER)
#define PROTOCOL_GET_REQUEST(code)   (code | PROTOCOL_REQUEST)
#pragma pack(1)
typedef struct PROTOCOL_start_head_t
{
    struct PACKAGE_head_start_t start;
    uint8_t command_code;
    uint16_t package_size;
}PROTOCOL_start_head_t;

typedef struct PROTOCOL_stop_head_t
{
    struct PACKAGE_head_stop_t stop;
}PROTOCOL_stop_head_t;

uint16_t PROTOCOL_process_message(uint8_t* __buffer, uint16_t __size, uint8_t* __answer_buffer);

#endif /* PROTOCOL_H */

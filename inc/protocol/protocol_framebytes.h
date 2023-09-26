#ifndef PROTOCOL_FRAMEBYTES_H
#define PROTOCOL_FRAMEBYTES_H

#include <stdint.h>
#include "protocol.h"

#define START_BYTE          (0xc0U)
#define END_BYTE            (0xceU)

typedef struct PROTOCOL_start_head_t
{
    uint8_t start;
    uint8_t package_size;
    uint8_t code;
}PROTOCOL_start_head_t;

typedef struct PROTOCOL_end_head_t
{
    uint8_t end_byte;
}PROTOCOL_end_head_t;

#endif /* PROTOCOL_FRAMEBYTES_H */
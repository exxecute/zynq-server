#ifndef PACKAGE_API_H
#define PACKAGE_API_H

#include <stdint.h>

typedef struct PACKAGE_API_t
{
    uint8_t buffer[64];
    uint16_t buffer_size;
    uint8_t start_package_byte;
    uint8_t stop_package_byte;
}PACKAGE_API_t;

typedef struct PACKAGE_head_start_t
{
    uint8_t head[4];
}PACKAGE_head_start_t;

typedef struct PACKAGE_head_stop_t
{
    uint8_t head[4];
}PACKAGE_head_stop_t;

void PACKAGE_API_init(PACKAGE_API_t *this, uint8_t* __buffer, uint16_t __buffer_size);

void PACKAGE_API_find_package(PACKAGE_API_t *this);

void PACKAGE_API_pack(uint8_t *__package, uint16_t __size);

#endif /* PACKAGE_API_H */
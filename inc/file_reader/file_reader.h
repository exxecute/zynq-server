#ifndef FILE_READER_H
#define FILE_READER_H

#include "stdint.h"

typedef struct FILE_READER_t
{
    FILE* fp;
    uint32_t byte_pointer;
}FILE_READER_t;

void FILE_READER_init(FILE_READER_t *this, char *__file_name, uint32_t __offset);
size_t FILE_READER_get_data(FILE_READER_t *this, uint8_t *__massive, uint32_t __size);

#endif /* FILE_READER_H */
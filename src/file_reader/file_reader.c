#include <stdio.h>

#include "file_reader.h"

void FILE_READER_init(FILE_READER_t *this, char *__file_name)
{
    this->fp = fopen(__file_name, "rb");
    this->byte_pointer = 0;
}

size_t FILE_READER_get_data(FILE_READER_t *this, uint8_t *__massive, uint32_t __size)
{
    size_t nread = fread(__massive, sizeof(char), __size, this->fp);
    this->byte_pointer += nread;
    return nread;
}

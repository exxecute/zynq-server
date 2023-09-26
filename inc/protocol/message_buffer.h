#ifndef MESSAGE_BUFFER_H
#define MESSAGE_BUFFER_H

#include <stdint.h>

void MESSAGE_BUFFER_process_data(uint8_t *__data, uint16_t __size);

uint8_t MESSAGE_BUFFER_get_package(uint8_t *__package);

#endif /* MESSAGE_BUFFER_H */
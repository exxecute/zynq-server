#ifndef _SERVER_API_H
#define _SERVER_API_H

#include <stdint.h>

void SERVER_API_init(void);

int SERVER_API_wait_message(uint8_t *__buffer, uint32_t size);

#endif /* _SERVER_API_H */

#ifndef SLIP_API_H
#define SLIP_API_H

#include <stdint.h>

uint8_t SLIP_code(uint8_t *__package, uint8_t __package_size, uint8_t *__coded_package);

uint8_t SLIP_decode(uint8_t *__package, uint8_t __package_size, uint8_t *__encoded_package);

#endif /* SLIP_API_H*/
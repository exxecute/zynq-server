#include <string.h>
#include <stdbool.h>

#include "protocol_framebytes.h"
#include "message_buffer.h"


#define MAX_BUFFER_SIZE_B                (128U)
#define WITH_LAST_BYTE                   (1U)


static uint8_t message_buffer[MAX_BUFFER_SIZE_B] = {0};
static uint16_t buffer_end = 0;


static void _save_data(uint8_t *__data, uint16_t __size)
{
    memcpy(message_buffer + buffer_end, __data, __size);
    buffer_end += __size;
}

static uint8_t _get_package_from_buffer(uint8_t *__package)
{
    uint8_t _package_size = 0;
    uint8_t _is_started = false;

    for(int byte = 0; byte < buffer_end; byte++)
    {
        if(message_buffer[byte] == START_BYTE)
        {
            _is_started = true;
        }
        else if(_is_started && message_buffer[byte] == END_BYTE)
        {
            _package_size = byte + WITH_LAST_BYTE;
            break;
        }
    }

    if(_package_size)
    {
        memcpy(__package, message_buffer, _package_size);
    }
    return _package_size;
}

static void _shift_buffers(uint8_t __shift_index)
{
    if(buffer_end >= __shift_index)
    {
        buffer_end -= __shift_index;
        memcpy(message_buffer, message_buffer + __shift_index, buffer_end);
    }
}


void MESSAGE_BUFFER_process_data(uint8_t *__data, uint16_t __size)
{
    _save_data(__data, __size);
}

uint8_t MESSAGE_BUFFER_get_package(uint8_t *__package)
{
    uint8_t _package_size = _get_package_from_buffer(__package);
    _shift_buffers(_package_size);
    return _package_size;
}
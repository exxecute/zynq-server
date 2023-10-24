#include "protocol_file.h"


static uint16_t _optimize_answer(uint8_t *__answer_buffer)
{
    uint16_t _answer_size = 0;
    return _answer_size;
}

static void _generate_answer(PROTOCOL_FILE_answer_t *this)
{
    this->start.command_code = PROTOCOL_FILE_CODE_ANSWER;
}

static void _fill_answer_buffer(uint8_t *__answer_buffer, uint8_t __file_code, uint32_t __file_offset)
{

}

uint16_t PROTOCOL_FILE_process(PROTOCOL_FILE_request_t* __buffer, PROTOCOL_FILE_answer_t* __answer_buffer)
{
    printf("[PROTOCOL] file package\n");

    _generate_answer(__answer_buffer);

    _fill_answer_buffer(&__answer_buffer->file_data, __buffer->file_code, __buffer->file_offset);

    uint16_t _answer_size = _optimize_answer((uint8_t*) __answer_buffer);

    return _answer_size;
}
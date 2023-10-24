#ifndef PROTOCOL_FILE_H
#define PROTOCOL_FILE_H

#include "protocol.h"


#define PROTOCOL_FILE_CODE          (0x02)

#define PROTOCOL_FILE_CODE_ANSWER   (PROTOCOL_GET_ANSWER(PROTOCOL_FILE_CODE))
#define PROTOCOL_FILE_CODE_REQUEST  (PROTOCOL_GET_REQUEST(PROTOCOL_FILE_CODE))

#define PROTOCOL_FILE_PACKAGE_CODE  (PROTOCOL_FILE_CODE_REQUEST)
#define PROTOCOL_FILE_PACKAGE_FOO   (PROTOCOL_FILE_process)

#define PROTOCOL_FILE_DATA_LEN      (0xffff - (sizeof(PROTOCOL_start_head_t) + sizeof(PROTOCOL_stop_head_t)))


#pragma pack(1)
typedef struct PROTOCOL_FILE_request_t
{
    struct PROTOCOL_start_head_t start;
    uint8_t file_code;
    uint32_t file_offset;
    struct PROTOCOL_stop_head_t stop;
}PROTOCOL_FILE_request_t;

typedef struct PROTOCOL_FILE_answer_t
{
    struct PROTOCOL_start_head_t start;
    uint8_t file_data[PROTOCOL_FILE_DATA_LEN];
    struct PROTOCOL_stop_head_t stop;
}PROTOCOL_FILE_answer_t;


uint16_t PROTOCOL_FILE_process(PROTOCOL_FILE_request_t* __buffer, PROTOCOL_FILE_answer_t* __answer_buffer);


#endif /* PROTOCOL_FILE_H */
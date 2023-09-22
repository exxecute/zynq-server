#ifndef PROTOCOL_H
#define PROTOCOL_H

#define PROTOCOL_REQUEST            (0x00U)
#define PROTOCOL_ANSWER             (0x80U)

#define PROTOCOL_GET_REQUEST(code)  (code + PROTOCOL_REQUEST)
#define PROTOCOL_GET_ANSWER(code)   (code + PROTOCOL_ANSWER)

typedef enum PROTOCOL_code_t
{
    PROTOCOL_CODE_TEST = 0x01,
    PROTOCOL_CODE_FILE = 0x02,
}PROTOCOL_code_t;

#endif /* PROTOCOL_H */
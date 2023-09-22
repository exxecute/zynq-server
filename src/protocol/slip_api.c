#include <string.h>

#include "slip_api.h"

#define BYTE_C0             (0xc0)
#define BYTE_DB             (0xdb)
#define BYTE_CE             (0xce)

#define WITHOUT_START_BYTE  (1U)
#define WITHOUT_STOP_BYTE   (1U)

#define NEXT_CODED_BYTE     (1U)

#define CODE_FIRST_BYTE     (0xdb) 
#define CODE_C0_SECOND_BYTE (0xdc)
#define CODE_DB_SECOND_BYTE (0xdd)
#define CODE_CE_SECOND_BYTE (0xde)


const uint8_t c0_code[] = {0xdb, 0xdc};
const uint8_t db_code[] = {0xdb, 0xdd};
const uint8_t ce_code[] = {0xdb, 0xde};


uint8_t SLIP_code(uint8_t *__package, uint8_t __package_size, uint8_t *__coded_package)
{
    uint8_t _coded_counter = WITHOUT_START_BYTE;
    __coded_package[0] = BYTE_C0;
    for(int byte = WITHOUT_START_BYTE; byte < __package_size - WITHOUT_STOP_BYTE; byte++)
    {
        switch(__package[byte])
        {
            case(BYTE_C0):
            {
                memcpy(__coded_package + _coded_counter, c0_code, sizeof(c0_code));
                _coded_counter += sizeof(c0_code);
                break;
            }
            case(BYTE_DB):
            {
                memcpy(__coded_package + _coded_counter, db_code, sizeof(db_code));
                _coded_counter += sizeof(db_code);
                break;
            }
            case(BYTE_CE):
            {
                memcpy(__coded_package + _coded_counter, ce_code, sizeof(ce_code));
                _coded_counter += sizeof(ce_code);
                break;
            }
            default:
            {
                __coded_package[_coded_counter] = __package[byte];
                _coded_counter++;
                break;
            }
        }
    }
    __coded_package[_coded_counter++] = BYTE_CE;
    return _coded_counter;
}

uint8_t SLIP_decode(uint8_t *__package, uint8_t __package_size, uint8_t *__encoded_package)
{
    uint8_t _encoded_counter = WITHOUT_START_BYTE;
    __encoded_package[0] = BYTE_C0;
    for(int byte = WITHOUT_START_BYTE; byte < __package_size - WITHOUT_STOP_BYTE; byte++)
    {
        if(__package[byte] == BYTE_DB)
        {
            uint8_t writeable_byte;
            switch(__package[byte+1])
            {
                case(CODE_C0_SECOND_BYTE):
                {
                    writeable_byte = BYTE_C0;
                    byte++;
                    break;
                }
                case(CODE_DB_SECOND_BYTE):
                {
                    writeable_byte = BYTE_DB;
                    byte++;
                    break;
                }
                case(CODE_CE_SECOND_BYTE):
                {
                    writeable_byte = BYTE_CE;
                    byte++;
                    break;
                }
                default:
                {
                    writeable_byte = __package[byte];
                    break;
                }
            }
            __encoded_package[_encoded_counter] = writeable_byte;
            _encoded_counter++;
        }
        else
        {
            __encoded_package[_encoded_counter] = __package[byte];
            _encoded_counter++;
        }
    }
    __encoded_package[_encoded_counter++] = BYTE_CE;
    return _encoded_counter;
}
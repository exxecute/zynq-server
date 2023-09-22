## Protocol

- [Information](#information)

- [Requsts codes](#requests-codes)

- [Test request](#test-request-0x01)

- [Test answer](#test-answer-0x80)

- [File request](#file-request-0x02)

    - [Documents](#documents)

- [File answer](#file-answer-0x82)

### Information

**0xc0** - start byte

**0xce** - end byte

data codes:

| Encode   | Codes          |
|----------|----------------|
| 0xc0     | 0xdb, 0xdc     |
| 0xdb     | 0xdb, 0xdd     |
| 0xce     | 0xdb, 0xde     |

### Requests codes

Request from **client**

| Code   | Sign                                  |
|--------|---------------------------------------|
| 0x01   | [Test request](#test-request-0x01)    |
| 0x02   | [File request](#file-request-0x02)    |

Answer from **server**

Code for answer increments 0x80

| Code   | Sign                                  |
|--------|---------------------------------------|
| 0x81   | [Test answer](#test-answer-0x81)      |
| 0x82   | [File answer](#file-answer-0x82)      |


### Test request 0x01

| Code      | Sign                                  |
|-----------|---------------------------------------|
| 0xc0      | Start byte                            |
| Size      | Size                                  |
| 0x01      | Test request code.                    |
| Any 8-bit | Test information for printing.        |
| 0xce      | End byte                              |

### Test answer 0x81

| Code      | Sign                                  |
|-----------|---------------------------------------|
| 0xc0      | Start byte                            |
| Size      | Size                                  |
| 0x81      | Test answer code.                     |
| Any 8-bit | Test information for printing.        |
| 0xce      | End byte                              |

### File request 0x02

| Code          | Sign                                  |
|---------------|---------------------------------------|
| 0xc0          | Start byte                            |
| Size          | Size                                  |
| 0x02          | File request code.                    |
| Document code | [Document](#documents)                |
| 0xce          | End byte                              |

#### Documents 

| Code          | Sign                                  |
|---------------|---------------------------------------|
| 0x00          | Text document                         |
| 0x01          | Shell script                          |
| 0x02          | Picture                               |

### File answer 0x82

| Code          | Sign                                  |
|---------------|---------------------------------------|
| 0xc0          | Start byte                            |
| Size          | Size                                  |
| 0x82          | File answer code.                     |
| Document      | Document                              |
| 0xce          | End byte                              |

## Protocol

- [Information](#information)

- [Requsts codes](#requests-codes)

- [Test request](#test-request-0x01)

- [Test answer](#test-answer-0x80)

- [File request](#file-request-0x02)

    - [Documents](#documents)

- [File answer](#file-answer-0x82)

### Information

Start bytes combination - 0x00 0x11 0x22 0x33
Stop bytes combination - 0xcc 0xdd 0xee 0xff

**Protocol heads**

| Code   | Sign                   |
|--------|------------------------|
| 32-bit | Start byte combination |
| 8-bit  | Command code           |
| 16-bit | Package size           |
|   -    | Package                |
| 32-bit | Stop byte combination  |

### Requests codes

Request from **client**

| Code | Sign                               |
|------|------------------------------------|
| 0x01 | [Test request](#test-request-0x01) |
| 0x02 | [File request](#file-request-0x02) |

Answer from **server**

Code for answer increments 0x80

| Code | Sign                             |
|------|----------------------------------|
| 0x81 | [Test answer](#test-answer-0x81) |
| 0x82 | [File answer](#file-answer-0x82) |


### Test request 0x01
| Code     | Sign                       |
|----------|----------------------------|
| 32-bit   | Start byte combination     |
| 0x01     | Command code               |
| 0x0001   | Package size               |
| 8-bit    | Test information for print |
| 32-bit   | Stop byte combination      |


### Test answer 0x81
| Code   | Sign                       |
|--------|----------------------------|
| 32-bit | Start byte combination     |
| 0x81   | Command code               |
| 0x0001 | Package size               |
| 8-bit  | Test information for print |
| 32-bit | Stop byte combination      |

### File request 0x02
| Code   | Sign                        |
|--------|-----------------------------|
| 32-bit | Start byte combination      |
| 0x02   | Command code                |
| 0x01   | Package size                |
| 8-bit  | [Document code](#documents) |
| 32-bit | Document byte offset        |
| 32-bit | Stop byte combination       |

#### Documents 

| Code | Sign          |
|------|---------------|
| 0x00 | Text document |
| 0x01 | Shell script  |
| 0x02 | Picture       |

### File answer 0x82
| Code   | Sign                   |
|--------|------------------------|
| 32-bit | Start byte combination |
| 0x82   | Command code           |
| 16-bit | Package size           |
|   -    | Document code          |
| 32-bit | Stop byte combination  |
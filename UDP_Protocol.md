## Protocol

- [Information](#information)

- [Requsts codes](#requests-codes)

- [Test request](#test-request-0x01)

- [Test answer](#test-answer-0x80)

- [File request](#file-request-0x02)

    - [Documents](#documents)

- [File answer](#file-answer-0x82)

### Information

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


### Test answer 0x81


### File request 0x02

#### Documents 

| Code          | Sign                                  |
|---------------|---------------------------------------|
| 0x00          | Text document                         |
| 0x01          | Shell script                          |
| 0x02          | Picture                               |

### File answer 0x82

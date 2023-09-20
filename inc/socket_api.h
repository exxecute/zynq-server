#ifndef _SOCKET_API_H
#define _SOCKET_API_H

#include <sys/socket.h>

int SOCKET_API_create_file_desc(int __domain, int __type, int __protocol);

int SOCKET_API_bind_socket(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);

ssize_t SOCKET_API_wait_message(int __fd, void *__restrict __buf, size_t __n,
            __SOCKADDR_ARG __addr,
            socklen_t *__restrict __addr_len);

#endif /* _SOCKET_API_H */
#pragma once

/*
    struct used as a handle for server socket
*/
typedef struct
{
	int server_fd;
	struct sockaddr_in *address;
} server_t;

/*
    returns server file descriptor
*/
server_t start_server(int port);

/*
    returns tcp socket file descriptor
*/
int accept_connection(const server_t* server);

/*
    struct used a send and receive a message
*/
typedef struct
{
    int loc;
    int digit;
} message_t;

// ssize_t send(int socket, const void* buffer, size_t len);

ssize_t send_msg(int socket_fd, const message_t* msg);
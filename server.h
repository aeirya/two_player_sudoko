#pragma once
// #include <sys/socket.h>
// #include <unistd.h>
#include <netinet/in.h>

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
int accept_connection(server_t* server);
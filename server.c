#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int create_welcome_socket() 
{
	int server_fd; 
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	return server_fd;
}

void bind_port(int server_fd, int port, struct sockaddr_in* address) 
{
	int opt = 1;
	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)address,
								sizeof(*address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

server_t start_server(int port)
{
	int server_fd, client_fd;
	struct sockaddr_in address;
	server_t server;

	server_fd = create_welcome_socket();

	// setup address
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	bind_port(server_fd, port, &address);

	// save in server struct
	server.address = &address;
	server.server_fd = server_fd;
	return server;
}

int do_accept_connection(int server_fd, struct sockaddr_in *address) 
{
	int new_socket;
	int addrlen = sizeof(address);
	// accepting
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	return new_socket;
}

int accept_connection(server_t* server) 
{
	return do_accept_connection(server->server_fd, server->address);
}

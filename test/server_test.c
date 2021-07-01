#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../server.h"
// #include "../message.h"

#define PORT 8080

int main()
{
    server_t socket;
    int client;
    socket = start_server(PORT);
    client = accept_connection(&socket);
    char* msg = "hello!\n";
    send(client, msg, 7, 0);
}
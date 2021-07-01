#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "server.h"

#define PORT 8080

int main()
{
    server_t server;
    int client;
    server = start_server(PORT);
    client = accept_connection(&server);
    
    char* msg = "hello!\n";
    send_msg(server, msg, 7);
}
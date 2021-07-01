#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../client.h"
// #include "../message.h"

#define PORT 8080
#define IP "127.0.0.1"

int main() 
{
    int socket;
    socket = connect_to_server(PORT, IP);

    char buffer[100];
    read(socket, buffer, 10);
    printf("%s", buffer);
    return 0;
}
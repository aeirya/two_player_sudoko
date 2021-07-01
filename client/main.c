/*
    client main
*/

#include <stdio.h>

#include "client.h"

#define PORT 8080
#define IP "127.0.0.1"

int main() 
{
    int socket;
    socket = connect_to_server(PORT, IP);
    return 0;
}
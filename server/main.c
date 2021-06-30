#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "server.h"
#include "receiver.h"
#include "game.h"
#include "stdbool.h"

#define PORT 8080

pthread_t client_locks[2];

void receive(int client, char* message) 
{
    
}

void start_connections()
{
    int server_fd, client1, client2;
    server_fd = start_server(PORT);
    client1 = accept_connection(server_fd);
    client2 = accept_connection(server_fd);

    listen_for_client(0, client1);
    listen_for_client(1, client2);
}

GameState state;

int main() 
{
    start_connections();

    int turn = 0;
    int a, b;
    while (true) 
    {
        while (poll(&a, &b, client_locks[turn]) == 0);
        move(turn, a, b);
        turn = (turn+1)%2;
    }
}
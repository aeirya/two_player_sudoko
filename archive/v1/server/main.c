// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>

// #include "server.h"
// #include "receiver.h"
// #include "game.h"
// #include "stdbool.h"

// #define PORT 8080

// pthread_t client_locks[2];

// void receive(int client, char* message) 
// {
    
// }

// void start_connections()
// {
//     server_t server;
//     int clients[2];
//     server = start_server(PORT);

//     clients[0] = accept_connection(&server);
//     clients[1] = accept_connection(&server);

//     listen_for_client(0, clients[0]);
//     listen_for_client(1, clients[1]);
// }

// GameState state;

// int main() 
// {
//     start_connections();

//     int turn = 0;
//     int a, b;
//     while (true) 
//     {
//         while (poll(&a, &b, client_locks[turn]) == 0);
//         move(turn, a, b);
//         turn = (turn+1)%2;
//     }
// }
#include "server.h"
#include "simple_receiver.h"
#include "game.h"

#define PORT 8080

int main() 
{
    server_t server;
    int clients[2];
    server = start_server(PORT);

    clients[0] = accept_connection(&server);
    clients[1] = accept_connection(&server);

    game_state_t state;
    int turn = 0;
    int loc, digit;
    while (true) 
    {
        receive(clients[turn], &loc, &digit); 
        move(&state, turn, loc, digit);
        turn = (turn+1)%2;
    }
}
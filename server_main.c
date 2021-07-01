#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "server.h"
#include "game.h"
#include "message.h"
#include "sample_table.h"

#include "logic.h"
#include "console.h"

#define PORT 8080
#define MAX_BUFF_SIZE 128
#define CLIENT_N 2

int main() 
{
    server_t server;
    int clients[2];
    server = start_server(PORT);

    // accept clients
    for (int i=0; i<CLIENT_N; ++i) 
    {
        clients[i] = accept_connection(&server);
        printf("client %d connected\n", i);
    }

    game_state_t state;
    int turn = 0;
    fill_initial_state(&state);
    message_t rcv_buffer[MAX_BUFF_SIZE], snd_buffer[MAX_BUFF_SIZE];
    int num_of_moves;
    char digit, loc;

    while (1) 
    {
       // print_blocks(state.board);
        num_of_moves = rcv_msg(clients[turn], rcv_buffer);
        // play
        log_server(turn, rcv_buffer, num_of_moves);
        
        for(int i=0, j=0; i<num_of_moves; ++i) {
            digit = rcv_buffer[i].digit;
            loc = rcv_buffer[i].loc;
            if(play(&state, digit, loc)) 
            {
                snd_buffer[j].digit = digit;
                snd_buffer[j++].loc = loc; 
            }

            send_msg(clients[0], snd_buffer, 0, j);
            send_msg(clients[1], snd_buffer, 0, j);
        }
        turn = (turn+1)%2;
    }
}
/*
    client main
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "client.h"
#include "message.h"
#include "game.h"
#include "sample_table.h"
#include "console.h"

#define PORT 8080
#define IP "127.0.0.1"

#define MAX_BUFF_SIZE 128

game_state_t state;

typedef message_t msg_buffer_t[MAX_BUFF_SIZE];

msg_buffer_t rcv_buffer, snd_buffer;

int turn = 1;
int msg_size;

int get_input(msg_buffer_t msg_buffer)
{
    int n, x, y, digit;
    printf("enter number of entries: ");
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        printf("enter x, y, digit\n");
        scanf("%d %d %d", &x, &y, &digit);
        msg_buffer[i].loc = N*x + y;
        msg_buffer[i].digit = digit;
    }
    return n;
}

void update_game_state(message_t* msg, int msg_size) {
    int loc, digit;
    int x, y;
    for(int i=0; i<msg_size; i++) {
        digit = msg[i].digit;
        loc = msg[i].loc;
        x = loc / N;
        y = loc % N;
        state.board[x][y] = digit;
    }
}

int main() 
{
    int socket;
    socket = connect_to_server(PORT, IP);
    printf("connected to server\n");

    fill_initial_state(&state);
    while(true) 
    {   
        print_blocks(state.board);
        msg_size = get_input(snd_buffer);
        send_msg(socket, snd_buffer, 0, msg_size);
        printf("sent message\n");
        msg_size = rcv_msg(socket, rcv_buffer);
        update_game_state(rcv_buffer, msg_size);
        print_blocks(state.board);
        msg_size = rcv_msg(socket, rcv_buffer);
        update_game_state(rcv_buffer, msg_size);
    }
    
    return 0;
}
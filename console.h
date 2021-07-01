#include <stdio.h>
#include "game.h"

void print_blocks(board_t blocks)
{
    int i,j; // row and column

    for (i=0; i<N; ++i)
    {
        for (j=0; j<N-1; ++j)
        {
            printf("%d|", blocks[i][j]);
        }
        printf("%d\n", blocks[i][j]);
    }
    for (i=0; i<N; ++i)
        printf("--");
    printf("\n");
}

void log_server(int turn, message_t rcv_buffer[128], int num_of_moves)
{
    printf("recv data from client %d:\n", turn);
    for(int i=0; i<num_of_moves; i++) 
    {
        printf("%d %d\n", rcv_buffer[i].digit, rcv_buffer[i].loc);
    }
}
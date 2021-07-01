#include "game.h"

void fill_initial_state(game_state_t* state) // the same function for client and server
{ 
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            state->board[i][j] = 0;
    state->board[0][3] = 8;
    state->board[0][5] = 1;
    state->board[1][7] = 4;
    state->board[1][8] = 3;
    state->board[2][0] = 5;
    state->board[3][4] = 7;
    state->board[3][6] = 8;
    state->board[4][6] = 1;
    state->board[5][1] = 2;
    state->board[5][4] = 3;
    state->board[6][1] = 6;
    state->board[6][7] = 7;
    state->board[6][8] = 5;
    state->board[7][2] = 3;
    state->board[7][3] = 4;
    state->board[8][3] = 2;
    state->board[8][6] = 6;
}
#pragma once 

#define N 9
#define ROW 3

typedef struct
{
    int blocks[N];
    int current_turn;

} game_state_t;

bool play(game_state_t* state, int client, int loc, int digit)
{
    if (state->current_turn != client)
        return false;

    int x, y;
    x = 0; y = 0;
    int block_number;
    int loc_tmp = loc;
    while(loc_tmp > ROW) {
        loc_tmp--;
        x++;
    }
    y = loc_tmp;
    block_number = x/3 + y/3;
    if(check_rep(x, y, block_number, digit, state))
        return false;
    return true;
    // do changes here
}

bool check_rep(int x, int y, int bn, int digit, game_state_t* state) {
    int* blocks = state->blocks;
    for(int i=0; i<=ROW; i++) {
        if(blocks[i*ROW+y] == digit)
            return true;
    }

    for(int i=0; i<ROW; i++) {
        if(blocks[x*ROW+i] == digit)
            return true;
    }

    for(int i=bn/3; i<bn/3 + 3; i++) {
        for(int j=)
        if(blocks[bn/])
    }
}

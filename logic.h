bool check_rep(int x, int y, int bn, int digit, game_state_t* state) {
    for(int i=0; i<N; i++) {
        if(state->board[x][i] == digit)
            return true;
    }

    for(int i=0; i<N; i++) {
        if(state->board[i][y] == digit)
            return true;
    }

    for(int i=(bn/3) * 3; i<(bn/3)*3 + 3; i++) {
        for(int j=y/3; j < y/3 + 3; j++)
            if(state->board[i][j] == digit)
                return true;
    }
    return false;
}

bool play(game_state_t* state, int digit, int loc)
{
    int x, y;
    x = 0; y = 0;
    int block_number;
    int loc_tmp = loc;
    x = loc_tmp / N;
    y = loc_tmp % N;
    block_number = x*3 + y/3;
    if(check_rep(x, y, block_number, digit, state))
        return false;
    return true;
    // do changes here
}
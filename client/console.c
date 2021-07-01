// #include "game.h"
#define ROW 3
#include "stdio.h"

typedef int board[ROW][ROW];

void print_blocks(board blocks)
{
    int i,j; // row and column

    for (i=0; i<ROW; ++i)
    {
        for (j=0; j<ROW-1; ++j)
        {
            printf("%d|", blocks[i][j]);
        }
        printf("%d\n", blocks[i][j]);
    }
}
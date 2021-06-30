#include <string.h>
#include <stdlib.h>

#include "simple_receiver.h"

/*
    message format: x:y;
*/
void decode_message(char* buffer, int* key, int* val)
{
    for (int i=0; i<BUFFER_SIZE; ++i) 
    {
        if (buffer[i] == ';') return;
        if (buffer[i] == ':') 
        {
            buffer[i] = '\0';
            *key = atoi(buffer);
            *val = atoi(buffer+i+1);
        }
    }
}

/*
    returns 
        0 if there's more, 
        1 if no new entry to receive

    stores key and value pair received
*/
int receive(int socket_fd, int *loc, int *digit) 
{
    char buffer[BUFFER_SIZE];
    int val_read;
    val_read = read(socket_fd, buffer);
    // protocol finish
    if (strcmp(buffer, "."))
        return 1;
    // decode to key and value
    decode_message(buffer, &loc, &digit);
    return 0;
}
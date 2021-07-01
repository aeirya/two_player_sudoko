#include <unistd.h>
#include <sys/socket.h>

#include "message.h"

#define MAX_MSG_SIZE 128

/*
    byte  | content
    0       msg type
    1       n of moves
    i       digit_i
    i+1       loc_i  

    msg types: 
    0:  move
    1:  update table
*/

/*
msg: a set of coupled digit_locs with a maximu

*/
int send_msg(int socket_fd, message_t* msg, int msg_type, int msg_size)
{
    char buffer[MAX_MSG_SIZE];
    buffer[0] = msg_type;
    buffer[1] = msg_size;

    for(int i=1; i<msg_size+1; i++) {
        buffer[2*i] = msg[i-1].digit;
        buffer[2*i+1] = msg[i-1].loc;
    }
    send(socket_fd, buffer, 2*msg_size+2, 0);
    
    return (int)msg_size; // send number of moves sent
}

int rcv_msg(int socket_fd, message_t* msg)
{
    char buffer[MAX_MSG_SIZE];
    int valread;
    do {
        valread = read(socket_fd, buffer, MAX_MSG_SIZE);
    } while(valread == 0);
    char msg_type = buffer[0];
    char msg_size = buffer[1];
    for(int i=1; i<msg_size+1; i++) {
        msg[i-1].digit = buffer[2*i];
        msg[i-1].loc = buffer[2*i+1];
    }
    return (int)msg_size;
}
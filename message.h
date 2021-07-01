#pragma once

/*
    struct used a send and receive a message
*/
typedef struct
{
    int loc;
    int digit;
} message_t;

int send_msg(int socket_fd, message_t* msg, int msg_type, int msg_size);
int rcv_msg(int socket_fd, message_t* msg);
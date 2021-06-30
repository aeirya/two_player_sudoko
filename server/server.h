#pragma once

/*
    returns server file descriptor
*/
int start_server(int port);

/*
    return tcp socket file descriptor
*/
int accept_connection(int server_fd);

// void send();

// void recieve();

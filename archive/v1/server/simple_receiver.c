#define BUFFER_SIZE 4096

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
    val_read = read(socket_fd, buffer, BUFFER_SIZE);
    // protocol finish
    if (buffer[0] == '.')
        return 1;
    // decode to key and value
    decode_message(buffer, loc, digit);
    return 0;
}
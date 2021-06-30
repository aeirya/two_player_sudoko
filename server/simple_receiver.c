#define BUFFER_SIZE 4096

/*
    message format: x:y;
*/
void decode_message(const char* buffer, int* key, int* val)
{
    for (int i=0; i<BUFFER_SIZE; ++i) 
    {
        if (buffer[i] == ';') return;
        if (buffer[i] == ':') 
        {
            // buffer[i] = '\0';
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
    val_read = read(socket_fd, buffer, BUFFER_SIZE);
    // protocol finish
    if (buffer[0] == '.')
        return 1;
    // decode to key and value
    decode_message(buffer, loc, digit);
    return 0;
}

// test
// int main()
// {
//     char buffer[BUFFER_SIZE] = "124:43";
//     int key, val;
//     decode_message(buffer, &key, &val);
//     printf("%d %d\n", key, val);
// }
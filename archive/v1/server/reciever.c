// #define BUFFER_SIZE 4096
// #define BUFF_SIZE_READ BUFFER_SIZE

// #include <semaphore.h>

// void forever_listen()  

// /*
//     PROTOCOL FORMAT:

//     number:block; number:block; 
//     Sample client message:
//     10:3;4:1;
// */

// int is_valid; // determines if there's incoming data 
// int a   // address of the number to write
//     ,b; // number to write
        

// struct ClientInfo {
//   int id;
//   int client_fd;
// };

// void decode_message(const char* buffer, int *a, int *b) {
//   // decode based on protocol

//   make_move()
// }

// int poll(int *a , int* b, sem_t* m) {
//     sem_post(m);
//     // HOW?!
//     // a = 
//     // b = 
//     // free lock
//     sem_wait(mm);
//     return is_valid;
// };
    
// void loop(int id, int client_fd, sem_t* m)
// {
//     char buffer[BUFFER_SIZE] = {0}; // mem aloc?
//     int val_read;
//     while (true)
//     {
        
//         // fill buffer

//         // val_read = read(server_fd)
//         // pass message to server?
//         // unlock mutex?
//         // pthread_mutex_lock(m);

//         val_read = read(client_fd, buffer, BUFF_SIZE_READ);
        
//         if(val_read != 0) // a valid message comming from client
//         {
//             sem_wait(m);
//             decode_message(buffer, &a, &b);
//             is_valid = true;
//         }
//         else 
//         {
//             sem_wait(m);
//             is_valud = false;
//         }

//     }
//     // receeived number 0
//     // flush 
// }

// void* thread_listen(void* client_info_in) {
//   struct ClientInfo* cl_ptr = (ClientInfo*) client_info_in;
//   int id = cl_ptr -> id;
//   int client_fd = cl_ptr -> client_fd;
//   loop(id, client_fd);
// }

// /*
//     id: client user id
//     client_fd: socket file descriptor
// */
// void listen_for_client(int id, int client_fd)
// {
//   // create pthrad (thread_lsiten)
//   pthread_t thread_id;
//   struct* client_data;
//   client_data = (ClientInfo*) malloc(sizeof(ClientInfo));
//   client_data -> id = id;
//   client_data -> client_fd = client_fd;

//   pthread_create(&thread_id, NULL, thread_listen, (void*)client_data);
// }
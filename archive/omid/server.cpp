#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080
#define IP "127.0.0.1"
#define MAX_TRANSMIT 128
#define MAX_READ 128
#define MAX_QUEUE_LENGTH 4
using namespace std;
void mystrncpy(char *, const char *, size_t);

class ServerSocket {
    public:
    ServerSocket() {
        set_opt(1);
        set_port(8080);
        set_valread(MAX_READ);
        init_connection();
    }
    ~ServerSocket() {}
    void init_connection() {
        //Creating socket file descriptor
        if( (server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        //Attaching socket to the port 8080
        if( setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        //Attaching socket to the port 8080
        if( bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            perror("Bind failed");
            exit(EXIT_FAILURE);
        }

        if( listen(server_fd, MAX_QUEUE_LENGTH) < 0 ) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
        }
    }
    void accept_connection() {
        socklen_t size = sizeof(address);
        if( (accepted_socket = accept(server_fd, (struct sockaddr *)&address, &size)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
        }
    }
   
    void set_valtransmit(int n) {
        if(n > 0 && n <= MAX_TRANSMIT)
            valtransmit = n;
        else
            valtransmit = 1;
    }

    void set_valread(int n) {
        if(n > 0 && n <= MAX_READ)
            valread = n;
        else
            valread = 1;
    }

    void send_data(void *tx) {
        bytestransmitted = send(accepted_socket, tx, valtransmit, 0);
    }

    void read_data(void *rx) {
        bytesread = read(accepted_socket, rx, valread);
    }

    void set_opt(int o) {
        if(o == 1 || o == 0) 
            opt = o;
    }

    void set_port(short int p) {
        if(p >= 1024)
            port = p;
    }

    int get_bytestransmitted() {
        return bytestransmitted;
    }

    int get_bytesread() {
        return bytesread;
    }

    int get_opt() {
        return opt;
    }

    short int get_port() {
        return port;
    }
    private:
    struct sockaddr_in address;
    
    int server_fd; //Socket file descriptor
    int accepted_socket;
    short int port;
    int opt; //option
    int valread; //Number of bytes to be read during read operation
    int valtransmit; //Number of bytes to be transmited( is used by set_tx() )
    int bytesread; //Number of bytes were read during the last read operation
    int bytestransmitted; //Number of bytes were sent during the last send operation
};

int main() {
char msg[MAX_READ];
int *b;
ServerSocket ss;
ss.accept_connection();
ss.read_data(b);
cout<<"From client: "<<*b<<endl;
}

void mystrncpy(char *dst, const char *src, size_t n) {
    strncpy(dst, src, n);
    dst[n] = '\0';
}
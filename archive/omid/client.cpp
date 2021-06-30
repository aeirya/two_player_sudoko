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
using namespace std;
void mystrncpy(char *, const char *, size_t);

class ClientSocket {
    public:
    ClientSocket(const char *ip = IP, short int port = 8080) {
        set_port(port);
        set_ip(ip);
        set_valread(MAX_READ);
        init_connection();
    }
    ~ClientSocket() {}
    void init_connection() {
        if( (sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        perror("\nSocket creation failed\n");
        //return -1;
        }
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        //Convert IPV4/6 addresses from text to binary form
        if( inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
            printf("\n Invalid address\n");
            //return -1;
        }

        if( connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("\nConnection failed\n");
            //return -1;
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
        bytestransmitted = send(sock, tx, valtransmit, 0);
    }

    void read_data(void *rx) {
        bytesread = read(sock, rx, valread);
    }

    void set_port(short int p) {
        if(p >= 1024) //The first 1024 ports are reserved
            port = p;
    }
    
    void set_ip(const char *a) {
        mystrncpy(ip, a, strlen(a));
    }
    int get_bytestransmitted() {
        return bytestransmitted;
    }

    int get_bytesread() {
        return bytesread;
    }
    short int get_port() {
        return port;
    }

    const char * const get_ip() {
        return ip;
    }
    private:
    struct sockaddr_in serv_addr;
    int sock; //Socket file descriptor
    char ip[15];
    short int port; //Port address of the socket
    int valread; //Number of bytes to be read during read operation
    int valtransmit; //Number of bytes to be transmited( is used by set_tx() )
    int bytesread; //Number of bytes were read during the last read operation
    int bytestransmitted; //Number of bytes were sent during the last send operation
   
};

int main() {
    
    ClientSocket cs, cs1;
    char hello[MAX_TRANSMIT] = "Hello from client!";
    int a = 582;
    cs.set_valtransmit(sizeof(a));
    cs.send_data(&a);
    if( cs.get_bytestransmitted() == sizeof(a))
        cout<<"Successful transmision"<<endl;
    else
        cout<<"Transmision wasn't completed successfully!"<<endl;
    cs1.set_valtransmit(strnlen(hello));
    cs1.send_data(hello);
    if( cs1.get_bytestransmitted() == strlen(hello))
        cout<<"Successful transmision-1"<<endl;
    else
        cout<<"Transmision wasn't completed successfully!-1"<<endl;
    return 0;
}

void mystrncpy(char *dst, const char *src, size_t n) {
    strncpy(dst, src, n);
    dst[n] = '\0';
}
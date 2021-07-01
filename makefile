server: server_main.c server.c message.c
	gcc -o server server_main.c server.c message.c

client: client_main.c client.c message.c
	gcc -o client client_main.c client.c message.c
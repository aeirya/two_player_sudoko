#pragma once
#include <semaphore.h>

void poll(int* key, int* val, sem_t* mutex);
void listen_for_client(int id, int client_fd);
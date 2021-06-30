#pragma once

void poll(int* a, int* b, sem* mutex);
void listen_for_client(int id, int client_fd);
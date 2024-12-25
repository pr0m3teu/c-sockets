#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0)
    {
        perror("ERROR in socket()");
        return 1;
    }
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    printf("Hello from Client\n");

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) < 1)
    {
        perror("Error in inet_pton");
        return 1;
    }

    if (connect(client_fd, (const struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("ERROR in connect");
        return 1;
    }
    printf("Connected to server!\n");

    return 0;
}



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
    if(client_fd < 0)
    {
        perror("ERROR in socket()");
        return 1;
    }

    struct 

    printf("Hello from Client\n");
    return 0;
}

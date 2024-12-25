#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    printf("Hello World!\n");
    
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1)
    {
        perror("ERROR in socket()");
        exit(1);
    }
    
    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) != 1)
    {
        perror("ERROR in inet_pton");
        exit(1);
    }
    
    if (bind(serverfd,  (const struct sockaddr *) &address, sizeof(address)) < 0)
    {
        perror("ERROR in bind");
        exit(1);
    }
    
    if (listen(serverfd, 10) < 0)
    {
        perror("ERROR in listen");
        exit(1);
    }
    while(1) {};

    return 0;
}

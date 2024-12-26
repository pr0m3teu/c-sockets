#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "common.h"

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

    int addr_len = sizeof(address);
    int new_socket = accept(serverfd, (struct sockaddr*)&address, (socklen_t*)&addr_len);
    if (new_socket < 0)
    {
        perror("ERROR in accept");
        return 1;
    }

    char buff[1024];
    int num_bites = read(new_socket, buff, 1024); 
    if (num_bites < 0)
    {
        perror("ERROR in read");
        return 1;
    }
    printf("%d\n", num_bites);
    
    struct Pos *new_pos =  (struct Pos *)buff;
    printf("%d, %d\n", new_pos->x, new_pos->y);
    
    close(serverfd);

    return 0;
}

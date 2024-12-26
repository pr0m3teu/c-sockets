CFLAGS=-O3 -Wall -Wextra -std=c11

all: client server

server:  server.c
	clang -o server $(CFLAGS) server.c
	
client: client.c
	clang -o client $(CFLAGS) client.c


all: client server

server:  server.c
	clang -o server -Wall -Wextra -std=c11 server.c
	
client: client.c
	clang -o client -Wall -Wextra -std=c11 client.c


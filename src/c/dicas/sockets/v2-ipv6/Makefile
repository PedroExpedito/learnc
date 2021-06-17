all:
	gcc -Wall -c common.c
	gcc -Wall -Wextra client.c common.o -o client
	gcc -Wall -Wextra server.c common.o -o server
	gcc -Wall -lpthread server-multi-thread.c common.o -o server-mt


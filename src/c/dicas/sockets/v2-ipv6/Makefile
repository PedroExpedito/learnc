all:
	tcc -Wall -c common.c
	tcc -Wall -Wextra client.c common.o -o client
	tcc -Wall -Wextra server.c common.o -o server
	tcc -Wall -lpthread server-multi-thread.c common.o -o server-mt


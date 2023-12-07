readline.o: readline.c
	gcc -c readline.c
request.o: request.c readline.h
	gcc -c request.c
book_requests.o: waiting_list.c request.h readline.h
	gcc -c waiting_list.c
book_requests: waiting_list.o request.o readline.o
	gcc -o waiting_list waiting_list.o request.o readline.o

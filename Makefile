main:	main.o	ReversePolish.o
	gcc main.o ReversePolish.o -o main

main.o:	main.c
	gcc -c main.c

ReversePolish.o:	ReversePolish.c	ReversePolish.h
	gcc -c ReversePolish.c

clean:
	rm *.o

run:
	./main

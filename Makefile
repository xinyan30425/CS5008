CC=gcc
CFLAGS=-Wall --std=c99
OBJECTS=main.o

hello:$(OBJECTS)
	$(CC)$(CFLAGS) -o hello $(OBJECTS)
	gcc -Wall --std=c99 main.o
main.o:main.c
	$(CC)$(CFLAGS)-c main.c -o main.o
clean:
	rm hello $(OBJECTS)


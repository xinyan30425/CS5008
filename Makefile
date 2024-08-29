exe: hash_main.o hash.o
	gcc -o exe hash_main.o hash.o

hash_main.o: hash_main.c
	gcc -c hash_main.c -o hash_main.o

hash.o: hash.c hash.h
	gcc -c hash.c -o hash.o

clean:
	rm exe hash_main.o hash.o



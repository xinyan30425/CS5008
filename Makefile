exe: link_list_main.o linklist.o
	gcc -o exe link_list_main.o linklist.o

link_list_main.o: link_list.c link_list.h
	gcc -c link_list.c -o link_list_main.o

link_list_main.o:link_list_main.c
	gcc -c link_list_main.c -o link_list_main.o

clean:
rm exe link_list_main.o linklist.o

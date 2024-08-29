exe1: queue_main.o queue.o
	gcc -o exe1 queue_main.o queue.o

exe2:main_test.o unit_tests.o queue.o
	gcc -o exe2 main_test.o unit_tests.o queue.o	

queue.o: queue.c 
	gcc -c queue.c -o queue.o

queue_main.o: main_queue.c
	gcc -c main_queue.c -o queue_main.o


unit_tests.o: unit_tests.c 
	gcc -c unit_tests.c -o unit_tests.o

# queue.o:queue.c 
# 	gcc -c queue.c -o queue.o

main_test.o: main_test.c 
	gcc -c main_test.c -o main_test.o

clean:
	rm exe1 exe2 main_test.o unit_tests.o queue.o queue_main.o



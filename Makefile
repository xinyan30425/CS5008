exe: stack_main.ood.o stack_ood.ood
	gcc -o exe stack_main_ood.o stack_ood.o

stack_ood.o: stack_ood.c stack_ood.h
	gcc -c stack_ood.c -o stack_ood.o

stack_main_ood.o: stack_main.ood.c
	gcc -c stack_main.ood.c -o stack_main_ood.o

clean:
rm exe stack_main_ood.o stack_ood.o



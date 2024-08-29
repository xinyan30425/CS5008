exe: student_vector_main_ood.o studentvector_ood.o
	gcc -o exe student_vector_main_ood.o studentvector_ood.o

studentvector_ood.o: studentvector_ood.c studentvector_ood.h
	gcc -c studentvector_ood.c studentvector_ood.o

student_vector_main_ood.o:student_vector_main_ood.c
	gcc -c student_vector_main_ood.c -o student_vector_main_ood.o

clean:
rm exe student_vector_main_ood.o studentvector_ood.o

  
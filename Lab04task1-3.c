/*
Xinyan Liu
CS 5008 Lab4 Student project task 1-3
Modified code with new "initializa","deallocate",and "pushData" functions

Feb 10,2023
*/

#include<stdio.h>
#include <stdlib.h>

//task 1 Create a C struct whose member variables are all the Student attributes
//The scope of the struct is the entire program
//use the typedef keyword to create a synonym of the struc type
struct student{
    int capacity;//capacity of the array
    int total;//current number of items in the array
    int *data;//a pointer variable that keeps the address

};
typedef struct student STUDENT;

//create a function that will print the array
//recieve only one argument,print out all the items in the array
void printData(STUDENT *myStudent)
//here we need the pointer to the STUDENT array as its argument 
//loop through the array 
{
    int i;
    printf("Capacity %d\n",myStudent->capacity);
    printf("Count:%d\n",myStudent->total);
    printf("Printing array of student score:\n");
    for(int i=0;i<myStudent->total;i++){
        printf("%d ",myStudent->data[i]);
    }

}

//task3
//create a function that will insert a new data value into the array
//the function should take the STUDENT struct as its argument
//the function should return nothing
void pushData(STUDENT myStudent){
    int newData;
    printf("Enter a new data: "); //prompts the user to enter a new data value and reads it from the console using "scanf"
    scanf("%d",&newData);
    //check if the array is already full by comparing the "total" and "capacity" fields in the "STUDENT" struct
    //if not full, inserts the new data value at the end of the array and increments the "total" field

    if(myStudent.total == myStudent.capacity){
        //if the array is full,double the capacity
        myStudent.capacity*=2;
        myStudent.data=realloc(myStudent.data,myStudent.capacity*sizeof(int));
        }
    myStudent.total++;
    myStudent.data[myStudent.total]=newData;
    
    printf("Data inserted. \n");
    }
    
/*
the pushData function was not able to print the updated array
it gives an error that pointer being freed was not allocated
task 4 and 5 modified the pushData function and it has fixed this issue
*/

int main(void){
    //task 2
    srand(1); //Seed the random number generator
    STUDENT student;
    student.capacity =7;
    student.total =0;
    student.data=(int*)malloc(student.capacity*sizeof(int));

    //initializa all values in the array to 0
    for (int i=0; i<student.capacity;i++){
        student.data[i]=0;
    }

    //populate the array with random values between 0 and 100
    while(student.total <student.capacity){
        student.data[student.total]=rand()%101;
        student.total++;
    }

    //print the array
    printData(&student);

    //insert a new data value into the array
    pushData(student);

    //print the updated array
    printData(&student);


    //free the dynamic allocated memory
    free(student.data);


    return 0;

}



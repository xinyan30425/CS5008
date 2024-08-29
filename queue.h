//the .h file is the API file. 

//#ifndef QUEUE_H and #define QUEUE_H are preprocessor directives used in C header files to prevent multiple inclusions of the same header file.
#ifndef QUEUE_H //checks if the macro QUEUE_H has not been defined before in the program. 
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void* QUEUE;
typedef enum status{Failure, Success}Status;


//functions

QUEUE queue_init_default();
Status queue_enqueue (QUEUE hQueue, int item); ///add items at the back
Status queue_dequeue(QUEUE hQueue); //remove items at the front
char* printFrontItem(QUEUE hQueue);
char* printTailItem(QUEUE hQueue);
int queue_getCapacity(QUEUE hQueue);
int getFrontItem(QUEUE hQueue); 
int getTailItem(QUEUE hQueue);
int queue_getTotalItems(QUEUE hQueue);
void printItems(QUEUE* phQueue);
void queue_destroy(QUEUE* phQueue);
char* printQueueIndices(QUEUE hQueue);

#endif
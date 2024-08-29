//the .c file is the implementation file

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
	int frontIndex; //this is index where we shall remove items
	int backIndex; //this is index where we shall add items
	int totalItems; // total items in the queue
	int capacity; //how many items our array/queue can hold
	int * data; //THE ARRAY where data is being kept.

};
typedef struct queue MY_QUEUE;

//functions
//This is the initializer for all memory and variables
QUEUE queue_init_default(void){
	MY_QUEUE* pQueue = NULL; //pointer to an instance of a VECTOR
	pQueue = (MY_QUEUE*) malloc(sizeof(MY_QUEUE));

	if(pQueue == NULL){
		printf("No memory");
		exit(1);
	}
	pQueue->frontIndex = 0;
	pQueue->backIndex = 0;	
	pQueue->capacity = 7;
	pQueue->totalItems = 0;

	pQueue->data = (int*) malloc(pQueue->capacity * sizeof(int));

	if(pQueue->data == NULL){
		printf("No memory for array");
		free(pQueue);
		pQueue = NULL;
	}
	return (QUEUE) pQueue;
}


Status queue_enqueue (QUEUE hQueue, int item)///add items at the back
{
	MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type 
	//check whether it is full 
	if(pQueue->totalItems >= pQueue->capacity){
        printf("Unfortunately queue is full! do something about it!");
    /*
	LAB Question 3a: Implement code fragment here that would increase the capacity of 
	the queue structure and allow for items to be added to the queue.
	Note that the implementation for queue is an array, so we need a correct way to increase the
	array capacity and copy items in search a way that no item misses its place in the queue. 
	
	*/
        //double the capacity of the queue
        int newCapacity = pQueue->capacity *2;
        int* newData = (int*) malloc(newCapacity * sizeof(int));

		int *new_prt = newData;
		for (int index = pQueue->frontIndex; index !=pQueue->backIndex;){
			int* old_ptr =(int*)(pQueue->data +index);
			*new_prt = *old_ptr;
			new_prt++;
			index = (index +1)%pQueue->capacity;
		}
        //free the frontindex and backindex of the queue
		free(pQueue->data);

		pQueue->data = newData;
        pQueue->capacity = newCapacity; 
        pQueue->frontIndex =0;
        pQueue->backIndex = pQueue ->totalItems-1;
		printf("Queue capacity is doubled to %d\n", newCapacity);
		}
        //add item to the back of the queue
        pQueue ->data[pQueue->backIndex]=item;//3b Modify this such that we can reuse empty spots in the array 
		pQueue->backIndex = (pQueue->backIndex + 1) % pQueue->capacity;
		pQueue->totalItems++;		
        return Success;	
	
}

int queue_getCapacity(QUEUE hQueue){
	 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
	 return pQueue->capacity;
}

int getFrontItem(QUEUE hQueue) {
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
 return pQueue->data[pQueue->frontIndex];
}

int getTailItem(QUEUE hQueue){
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
 int last_index = (pQueue->backIndex + pQueue->capacity - 1) % pQueue->capacity;
 return pQueue->data[last_index];
}

char* printFrontItem(QUEUE hQueue){
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
  	//You may need to modify this to ensure it works with an extended array
 	// Create a buffer to store the string representation of the front item
    char* buffer = malloc(100 * sizeof(char));
	if (pQueue->totalItems != 0){
		sprintf(buffer, "Front is: %d", pQueue->data[pQueue->frontIndex]);
	} else {
		sprintf(buffer, "Front is: nothing");
	}
	return buffer;
}

char* printTailItem(QUEUE hQueue){
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
 	//You may need to modify this to ensure it works with an extended array
 	
	char* buffer = malloc(100 * sizeof(char));
	if (pQueue->totalItems != 0){
		printf("Tail is: %d \n", pQueue->data[pQueue->backIndex-1]);
	}else {
		sprintf(buffer, "Front is: nothing\n");
	}
	return buffer;
}

int queue_getTotalItems(QUEUE hQueue){
	 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type 
	 return pQueue->totalItems;
}

Status queue_dequeue(QUEUE hQueue) //remove items at the front
{
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type

 if (pQueue->totalItems != 0){
	pQueue->frontIndex++;
	pQueue->totalItems--;
	return Success;
}
 return Failure;
}

void printItems(QUEUE* phQueue){
	MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;
	int i = 0;
	printf("total nums is %d\n", pQueue->totalItems);
	while (i < pQueue->totalItems){
	/*
	LAB Question 2: Implement code fragment here that would correctly print all items in the queue. 
	Note that the first item in the queue should always be printed first and the last item printed second. 
	This code should not use the printFront or printBackItem functions.  
	*/
    printf("%d", pQueue->data[(pQueue->frontIndex + i) % pQueue->capacity]);
	i++;
	}
	return;
}

void queue_destroy(QUEUE* phQueue){
 MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;
 if(pQueue!=NULL){
 	free (pQueue->data);
 	free(pQueue);
 }
 *phQueue = NULL; 
}

char* printQueueIndices(QUEUE hQueue)
{
    // Cast the opaque handle to the appropriate data type
    MY_QUEUE* pQueue = (MY_QUEUE*)hQueue;
	// Create a buffer to store the string representation of the indices
    char* buffer = malloc(100 * sizeof(char));
    // Print the current frontIndex and backIndex of the queue
	sprintf(buffer, "frontIndex: %d\nbackIndex: %d\n", pQueue->frontIndex, pQueue->backIndex);

    return buffer;
}



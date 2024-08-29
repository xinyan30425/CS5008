#include "queue.h"

/*
If we are implementing a dynamic array (or any array) ; 
what in terms of variables do we need
1) Pointer - which shall keep the address of the first of the array
2) Variable - to inform us the CAPACITY of the array
3) An Iterating variable - total no_items in the array at a certain time
*/

int main(void){

QUEUE hQueue= NULL; //opaque handle -- a pointer to an opaque object that conceals the known data type.
hQueue = queue_init_default();

queue_enqueue(hQueue, 5);//5
queue_enqueue(hQueue, 8);//5 8
queue_enqueue(hQueue, 4);// 5 8 4
queue_enqueue(hQueue, 7);//5 8 4 7

printItems(&hQueue);

printQueueIndices(hQueue);
printFrontItem(hQueue); //5
printTailItem(hQueue); //7
//dequeue: dequeues (removes) the first item that was added to the queue and shifts the remaining items one position forward in the queue
queue_dequeue (hQueue); //8 4 7 
queue_dequeue (hQueue); //4 7 
queue_enqueue(hQueue, 20); //4 7 20

printItems(&hQueue);
printQueueIndices(hQueue);
printFrontItem(hQueue);// 4
printTailItem(hQueue);// 20

//enqueue(add) an item to the end of the queue, expanding the size of the queue by one 
queue_enqueue(hQueue, 40);//4 7 20 40 
queue_enqueue(hQueue, 50);//4 7 20 40 50
queue_enqueue(hQueue, 6);//4 7 20 40 50 6
queue_enqueue(hQueue, 14);//4 7 20 40 50 6 14

printf("****************\n");

queue_dequeue (hQueue); //7 20 40 50 6 14
printFrontItem(hQueue);//7
printTailItem(hQueue);//14
queue_destroy(&hQueue);
return 0;
}



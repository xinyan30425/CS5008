#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


typedef struct priority_queue_node{
    int priority;
    int data;
} Priority_Queue_Node;

typedef struct priority_queue{
    Priority_Queue_Node* nodes;
    int size;
    int capacity;
} Priority_Queue;


/*
Precondition: Creates an empty priority queue that can store integer data items
	with different integer priority. Higher integer values indicate higher priority in the queue. For example, consider the
	priority and the data value to be key-value pairs where the priority is the key and the data is the value. The queue could hold 21,10 and 35, 5 so that the 
	first item to be removed from the queue would be the data value 5 because
	it has higher priority (35) than the data value 10 which only has (21).
Postcondition: Returns the handle to an empty priority queue
*/
PRIORITY_QUEUE priority_queue_init_default(void){
    Priority_Queue* queue =(Priority_Queue*) malloc (sizeof(Priority_Queue));
    if (queue !=NULL){
        queue->nodes =NULL;
        queue ->capacity=0;
        queue->size=0;
    }
    return (PRIORITY_QUEUE) queue;
}

/*
Precondition: hQueue is a handle to a valid priority queue opaque object
	Higher priority_level values indicate higher priority in the queue.
	data_item is simply a value we are storing in the queue
Postcondition: returns SUCCESS if the item was successfully added to the queue
	and FAILURE otherwise.
*/

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item){
    Priority_Queue*queue =(Priority_Queue*)hQueue;
    if(queue->size == queue->capacity){
        int new_capacity=0;

        if(queue->capacity ==0){
            new_capacity=1;
        }
        else{
            new_capacity*=2;
        }
        // allocate a new array "Priority_Queue_Node" with the new capacity
        Priority_Queue_Node* new_node = (Priority_Queue_Node*)realloc(queue->nodes, new_capacity*sizeof(Priority_Queue_Node));
        if(new_node ==NULL){
            return FAILURE;
        //update the new node pointer and the capacity
        queue->nodes=new_node;
        queue->capacity=new_capacity;
    }

    int i = queue->size;//current size of the queue is where we insert the new element
    queue->nodes[i].priority = priority_level;//assign priority level and data item to the new node's position
    queue->nodes[i].data = data_item;

    //insert the new item at the end of the array and then bubble up to its correct position
    int parent =(i-1)/2;//index of the parent node in the binary heap
    while(i>0 && queue->nodes[parent].priority < queue->nodes[i].priority){
        //swap the parent and the child node if the current node's priority is greater than its parent's priority
        Priority_Queue_Node temp = queue->nodes[parent];
        queue->nodes[parent] = queue->nodes[i];
        queue->nodes[i] = temp;
        //update the index of the child node and the parent node
        i = parent;
        parent = (i-1)/2;
    }
    queue->size++;
    return SUCCESS;
}
}

/*
Precondition: hQueue is a handle to a valid priority queue opaque object. 
Postcondition: returns SUCCESS if the highest priority item was removed from the queue 
	and FAILURE if the queue was empty.
*/

//adjust the position of the elements in the array based on their priorities
Status priority_queue_service(PRIORITY_QUEUE hQueue){
    Priority_Queue* queue = (Priority_Queue*)hQueue;//cast the hQueue handle to a priority queue pointer
    if(queue->size ==0){ //if queue is empty return False
        return FAILURE;
    }
    //swap the first and the last node in the binary heap
    Priority_Queue_Node temp = queue->nodes[0];
    queue->nodes[0] = queue->nodes[queue->size-1];//replace the root node with the last node in the binary heap
    queue->nodes[queue->size-1] = temp;
    //decrease the size of the queue by 1
    queue->size--;
    //heapify the binary heap
    int i =0;
    int lchild = 2*i+1;
    int rchild = 2*i+2;

    while(lchild < queue->size){
        int max = i;//store the index of the node with the largest priority value among the current node and its child nodes
        
        if(queue->nodes[lchild].priority > queue->nodes[max].priority){
            max = lchild;
        }
        if(rchild < queue->size && queue->nodes[rchild].priority > queue->nodes[max].priority){
            max = rchild;
        }
        if( max !=i){
            Priority_Queue_Node temp = queue->nodes[max];
            queue->nodes[max] = queue->nodes[i];
            queue->nodes[i] = temp;

            i = max;    
        }
        else{
            break;
        }
    }
    return SUCCESS;
}

/*
Precondition: hQueue is a handle to a valid priority queue opaque object. 
Postcondition: returns a copy of the data value for the 
	highest priority item in the queue. Sets status to SUCCESS if there is 
	at least one item in the queue and FAILURE otherwise. If status is 
	passed in as NULL then the status value is ignored for this run of the 
	function. 
*/

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status){
    Priority_Queue* queue =(Priority_Queue*)hQueue;

    if(queue->size ==0){//check if queue is empty  
        if(status !=NULL){
            *status = FAILURE;
        }
        
        return -1;
    }
    if(status !=NULL){
        *status = SUCCESS;
    }
    return queue->nodes[0].data;
}


/*
Precondition: hQueue is a handle to a valid priority queue opaque object. 
Postcondition: returns TRUE if the priority_queue is empty and FALSE otherwise. 
*/

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue){
    Priority_Queue*queue =(Priority_Queue*)hQueue;

    if(queue->size ==0){
        return TRUE;
    }
    return FALSE;

}

/*
Precondition: phQueue is a pointer to the handle of a valid priority queue opaque object. 
Postcondition: The opaque object will be free'd from memory and the handle pointed to 
	by phQueue will be set to NULL. 
*/

void priority_queue_destroy(PRIORITY_QUEUE* phQueue){
    Priority_Queue* queue = (Priority_Queue*)*phQueue;
    if (queue!=NULL){
        if(queue->nodes!=NULL){
            free(queue->nodes);
        }

    free(queue);
    *phQueue = NULL;
}
}


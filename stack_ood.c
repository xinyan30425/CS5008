
#include "stack_ood.h"

//define a NODE type
typedef struct node NODE;

struct node{
	int data;
	NODE* next;
};


//Known type - the stack, keeps only the top node
typedef struct stack MY_STACK;//forward declaration

struct stack{
	NODE *top;
};


//returns an opaque object after creating all required memory for the stack
STACK allocate(void){

	//consider grades as integers - not always true- for static array
	MY_STACK * pStack = (MY_STACK *)malloc(sizeof(MY_STACK));//first bookend
	if (pStack == NULL){
		printf("No memory \n");
		exit(-1);
	}
	//We do not have any nodes yet, so top is NULL
	pStack->top=NULL;
		
	//typecast to opaque	
	return (STACK) pStack;

}


//prints all data items in our stack
void printData(STACK pStack){
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	NODE * temp = ppStack->top;	
	while (temp != NULL){
		printf("%d \n",temp->data);
		temp = temp->next;
	}

return;
}

STATUS isFull(STACK pStack) {
	 //this is a stack implemented as linked list, it can never be full!!!
	 return FALSE;  
}

/*
This function should imitate the insertHead function, why is that? 
The function should receive address of the stack and some data value. 
The function should allocate memory for a node which becomes part of the stack
Some starter code is provide to provide a way for a new NODE to be created. 
You need to show how this is inserted into the stack.
*/
OUTCOME  push(STACK * pStack,int item){
		
	MY_STACK * ppStack = (MY_STACK *) *pStack;//dereferencing + typecasting
	
	NODE* newNode = (NODE*) malloc (sizeof (NODE));
	if(!newNode){
		return FAILURE;
	}
	newNode->data = item;
	//newNode->next = NULL;
	/*
	Your code for PART 1 goes in here (10 points for this part)
	*/
    //we need to update the next pointer of the new node to point to the current head of stack
    //then update the head of the stack to be the new node
  
    newNode->next = ppStack->top;//point to current head of stack
    ppStack->top = newNode;//update stack head to be new node
    return SUCCESS;

}

/*
This function should remove what is on top of the stack. 
Remember we are now dealing with nodes, so what is on top of the stack is actually a node. 
*/
OUTCOME  pop(STACK* pStack){
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	NODE * temp = ppStack->top;
	
	if(ppStack->top == NULL){
		return FAILURE;
	}
	
	/*
	Your code for part 2 should go here (5 points)
	*/
    ppStack->top =ppStack->top->next;//update the top of stack to be the next node
    free(temp); //free memory of removed node
	return SUCCESS;

}


//This function returns the data held by the node which is notop of the stack. 
int peek(STACK pStack){
	
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 

	/*
	Your code for part 3 should go here (5 points)
	*/
    if(ppStack->top ==NULL){
        //first check if the stack is empty
        return -1;
    }
    //if the stack is not empty,access the "data" field of the top node and return its value.
    return ppStack->top->data;
	
}

/*
How would we go about deallocating the memory? 
Notice that for this data structure, everything is held by multiple nodes and therefore all created memory must be freed
also the stack memory allocated in the first function must be deallocated too.
*/

void deallocate(STACK * pStack){
	
    MY_STACK * ppStack = (MY_STACK *) *pStack;//dereferencing + typecasting
    NODE * temp = ppStack->top;

	/*
	Your code for part 4 should go here (10 points)
	*/
    while(temp!=NULL){
        ppStack->top = temp->next;//update the top of the stack to be the next node
        free(temp);//free memory of current node
        temp = ppStack->top; // move to enxt node
    }
    free(ppStack); // free memory of stack itself
    *pStack = NULL; //set stack pointer to NULL

	return;
}



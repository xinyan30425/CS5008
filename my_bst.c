// Xinyan Liu
// 4.2.2023
//
// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    //Modify the body of this function as needed.
    //bst_t* myBST= NULL; 
    bst_t* myBST = (bst_t*)malloc(sizeof(bst_t));
    myBST->size = 0;
    myBST->root = NULL;
    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    return t->size == 0;
}

// Adds a new node containg item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){
     if (t == NULL) {
        printf("Error: BST is NULL\n");
        exit(1);
    }

    bstnode_t** current = &(t->root);//create a pointer to pointer variable ：current" points to the address of the root node
    while (*current != NULL) { //iterate through the BST until the approprite position for the new node
        if (item <= (*current)->data) {
            current = &((*current)->leftChild);//if the item is less than or equal to the current node, move the current pointer to the left childs address
        } else {
            current = &((*current)->rightChild);//move the current pointer to the right 
        }
    }

    *current = (bstnode_t*) malloc(sizeof(bstnode_t));
    if (*current == NULL) {//check if allocation failed
        return -1;
    }
    (*current)->data = item;//set the new node's data to teh given item
    (*current)->leftChild = NULL;//set the new node's left left child pointer to NULL
    (*current)->rightChild = NULL;//set the new node's right child pointer to NULL
    t->size++;//increment 1 to indicate that the operation was successful

    return 1;
    
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// A BST that is NULL should print "(NULL)"
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(t == NULL || t->root ==NULL)
        printf("(NULL)");
        return;
    
    bstnode_t *current = t->root;//create a current pointer that initially pointer to the root node
    bstnode_t *predecessor;//declare a predecessor pointer 

    while (current != NULL) {//iterate through the BST until there are no more nodes
        if (current->leftChild == NULL) {
            if (order == 0) { //if order is 0 print the BST in ascending order
                printf("%d ", current->data);
            } else {
                printf("%d ", -current->data); //if order is not 0,print the BST in descending order
            }
            current = current->rightChild;
        } else {
            // Find the inorder predecessor of the current node
            predecessor = current->leftChild;//set the predecessor pointer to the left
            while (predecessor->rightChild != NULL && predecessor->rightChild != current) {
                predecessor = predecessor->rightChild; //find the inorder predecessor of the current node and move to its right child 
            }

            // If the rightChild of the predecessor is NULL, make the current node its rightChild
            if (predecessor->rightChild == NULL) { //restore the tree structure by setting the right child of the predecessor 
                predecessor->rightChild = current;
                current = current->leftChild;
            } else {
                // Restore the tree structure by setting the rightChild of the predecessor to NULL
                predecessor->rightChild = NULL;
                if (order == 0) {
                    printf("%d ", current->data);
                } else {
                    printf("%d ", -current->data);
                }
                current = current->rightChild;
            }
        }
    }   
}

// Returns the sum of all the nodes in the bst. 
// A BST that is NULL exits the program.
// It should run in O(n) time.
int bst_sum(bst_t *t){
     if (t == NULL) {
        printf("Error: BST is NULL\n");
        exit(1);
    } 

    int sum = 0;
    bstnode_t *current = t->root;//create a current pointer 
    bstnode_t *pre;//a pre pointer that will be used to find the inorder predecessor of current node

    while (current != NULL) {
        if (current->leftChild == NULL) {
            sum += current->data;
            current = current->rightChild;
        } else {
            pre = current->leftChild;//move the pre pointer to its right child 
            while (pre->rightChild != NULL && pre->rightChild != current) {
                pre = pre->rightChild;
            }

            if (pre->rightChild == NULL) {//if the right child of the pre is null
                pre->rightChild = current;//make the current nodfe the right child of the pre
                current = current->leftChild;//move the current pointer to its left child
            } else {
                pre->rightChild = NULL;
                sum += current->data; //add the data of the current node to the sum
                current = current->rightChild;
            }
        }
    }

    return sum;     
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree -- exit the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    if (t == NULL) {
        printf("Error: BST is NULL\n");
        exit(1);
    }

    bstnode_t *current = t->root;

    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }

        if (value <= current->data) {//if the value is less or equal to the data of the current node
            current = current->leftChild;//move the current pointer to its left child if the given value is less than or equal to the current node
        } else { 
            current = current->rightChild;//move to the current pointer to its right child if the given value is greater than the current node
        }
    }

    return 0;
  
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    if (t == NULL) {
        printf("Error: BST is NULL\n");
        exit(1);
    }

    return t->size;
    
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
         if (t == NULL) {
        printf("Error: BST is NULL\n");
        exit(1);
    }

    bstnode_t *current, *temp;// two pointers current and temp 
    while (t->root != NULL) {
        current = t->root;//set the current pointer to the root of the BST
        temp = NULL;//initialize the temp pointer 

        while (current->leftChild != NULL || current->rightChild != NULL) {//iterate until current has no children
            temp = current;

            if (current->leftChild != NULL) {
                current = current->leftChild;
            } else {
                current = current->rightChild;
            }
        }

        if (temp != NULL) { //check if temp is not the root node
            if (temp->leftChild == current) {
                temp->leftChild = NULL;
            } else {
                temp->rightChild = NULL;
            }
        } else {
            t->root = NULL;
        }

        free(current);duo
    }

    free(t);

}
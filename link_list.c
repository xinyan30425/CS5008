#include <stdlib.h>
#include <stdio.h>
#include "list_list.h"

typedef struct nodeTag Node;


/* lengthRec
 * parameter -- list
 * returns the length of the list (# nodes)
 */
int lengthRec(Node * list) {
  if(list == NULL) {
    return 0;//check if the "list" is "NULL", if it is, then the function returns 0
  } else {
    // LAB EXERCISE 1: complete this recursive function call
    //returns "1+lengthRec(list->next)"
    //count the current node and add it to the result of calling "lengthRec" on "list->next", which gives the length of the rest of the list 
    return 1+lengthRec(list->next);
  }
}

/* freeList
 * parameter -- list
 * frees all nodes in the list
 */
void freeList(Node * list) {
  if(list == NULL) {//check if the list is NULL
    return;
  } else {
    // LAB EXERCISE 2: complete the function so that it recursively
    // frees list->next and then frees the list

    freeList(list->next);
    free(list); // if not call "freelist" to free the next node in the list, then free the current node by calling "free(list)" 
  }
}
//why must list->next be freeed before list?
//because when malloc memory for a linked list node, we are allocating a contiguous block of memory.
//the pointer to the next node in the list is stored in this block of memory
//if we just call free(list) but not list->next,we only release the memory block that list points to,but the memory block it points to will still be used
//so we need to free "list->next" first to ensure all the memory blocks in the linked list are freed in the correct order

/* copyList
 * parameter -- list
 * returns a copy of the list
 */
Node * copyList(Node * list) {
  Node * ret = NULL;
  if(list == NULL) {
    return NULL;
  } else {
    // LAB EXERCISE 3: complete the function so that it makes a new
    // node and recusively copies the rest of the list
    // use makeNode, the second argument to makeNode can be a
    // recursive call to copyList, since copyList returns a pointer
    // to a Node

    ret = makeNode(list->num,copyList(list->next));
    return ret;
  }
}

/* mergeList
 * parameters: list1 and list 2
 * merges the two lists, keeping the values in ascending order
 * NOTE: only works if list1 and list2 are sorted
 */
Node * mergeList(Node * list1, Node * list2) {
  if (list1 == NULL) {
    return copyList(list2);
  } else if (list2 == NULL) {
    return copyList(list1);
  } else if (list1->num < list2->num) {

    // LAB EXERCISE 4: complete this recursive case to that it makes
    // a new node and recursively merges the two lists as the
    // second argument   
    Node *ret =makeNode(list1->num,mergeList(list1->next,list2));
    return ret;
  } else {
    // LAB EXERCISE 4: complete this recursive case
    Node *ret =makeNode(list2->num,mergeList(list1,list2->next));
    return ret;

  }
}
//why do the recursive calls for mergeList eventually reach a base case?
//because the base case is when one of the lists is NULL, so the recursive calls will eventually reach the base case



/********************* function definitions from lecture ****/

/* makeNode
 * parameters -- n (the number to store in the node)
 *            -- nextItem (the next link of the node)
 * slightly different than textbook version */
Node * makeNode(int n, Node * nextItem) {
  Node * ret = (Node * ) malloc(sizeof(Node));
  ret->num = n;
  ret->next = nextItem;
  return ret;
}

/* length
 * parameter -- list (the linked list)
 * returns the length (# nodes) in the linked list
 * implemented iteratively */
int length(Node * list) {
  int len = 0;
  while(list != NULL) {
    len++;
    list = list->next;
  }
  return len;
}

/* print
 * parameter -- list (the linked list)
 * prints the values of the nodes (in order) of the list
 */
void print(Node * list) {
  printf("Linked list contents: ");
  while(list != NULL) {
    printf("%d ", list->num);
    list = list->next;
  }
  printf("\n");
}

/* insertTail
 * parameters -- n (the value of the node to insert)
 *            -- list (the linked list)
 * inserts new node at the end with value n
 * note: this is done by passing the pointer to list, so
 * when the function returns, the list object that was
 * passed to this function has been altered
 */
void insertTail(int n, Node ** listPtr) {
  Node * list = *listPtr;
  if(list == NULL) {
    // create a 1-node list
    *listPtr = makeNode(n, NULL);
    return;
  }
  while(list != NULL) {
    if(list->next == NULL) {
      // insert new node here since we found the last node
      list->next = makeNode(n, NULL);
      return;
    }
    list = list->next;
  }
}

/* find
 * parameters -- n (the value to search for)
 *            -- list (the linked list)
 * returns a pointer to the first node found with value n
 * if no such value is found, returns NULL
 */
Node * find(int n, Node * list) {
  while(list != NULL) {
    if(list->num == n) {
      return list;
    }
    list = list->next;
  }
  // no node with value n found
  return NULL; // or could return list, since list has value NULL
}

/* delete
 * parameters -- toDelete (the node to find and delete)
 *            -- listPtr (pointer to the list)
 * note: must pass listPtr in case the first element of the list
 * is deleted -- passing the list by reference, so the address
 * to the first item in the list can get updated if necessary
 *
 * returns 0 if no item found and deleted
 * returns 1 if a node is deleted
 */
int delete(Node * toDelete, Node ** listPtr) {
  Node * list = *listPtr;  // list is the linked list
  // case: either toDelete or list is null -- will not be deleting
  if(toDelete == NULL || list == NULL) {
    return 0;  // indicates no change to the list
  }

  // special case: toDelete is first node in list
  if(toDelete == list) {
     *listPtr = list->next;   // now list->next becomes first node in list
                              // returning new first address via pointer
     free(toDelete);
    return 1;  // indicates that a node was deleted
  }

  // case: need to find toDelete somewhere other than first node in list
  Node * before = list;
  list = list->next;
  while(list != NULL) {
    if(toDelete == list) {
      // redo pointers and then free memory
      before->next = list->next;
      free(list);
      return 1;
    }
    before = list;  // update for next iteration
    list = list->next;
  }
  return 0;  // toDelete not found
}

/* insertHead
 * parameters -- n (the value of the new node)
 *            -- listPtr (a pointer to the linked list for the insertion)
 *
 * inserts the new node at the front of the list
 */
void insertHead(int n, Node ** listPtr) {
  // create new node
  *listPtr = makeNode(n, *listPtr);
}

/* numPos
 * parameters -- list (list to search)
 *
 * returns the number of positive ints in the list
 */
int numPos(Node * list) {
  int countPos = 0;
  if(list == NULL) {
    return 0;
  }
  while(list != NULL) {
    if(list->num > 0) {
      countPos++;
    }
    list = list->next;
  }
  return countPos;
}
    
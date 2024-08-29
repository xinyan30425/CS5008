#ifndef LIST_LIST_H
#define LIST_LIST_H
#include <stdlib.h>
#include <stdio.h>


typedef struct nodeTag Node;

/* similar to the textbook -- a Node represents one node in the linked list */
struct nodeTag {
  int num; // value stored in node
  Node * next; // pointer to next node in list
};

/* function prototypes on linked lists */
Node * makeNode(int n, Node * nextItem);
int    length(Node * list);
void   print(Node * list);
void   insertTail(int n, Node ** list);
Node * find(int n, Node * list);
int    delete(Node * toDelete, Node ** listPtr);
void   insertHead(int n, Node ** list);
int    numPos(Node * list);

/* function prototypes on linked lists for lab */
int    lengthRec(Node * list);
void   freeList(Node * list);
Node * copyList(Node * list);
Node * mergeList(Node * list1, Node * list2);
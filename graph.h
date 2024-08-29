#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {white, gray, black} COLOR;

// typedef struct QueueNode{
//     int data;
//     struct QueueNode* next;
// } QueueNode;

// typedef struct Queue{
//     QueueNode* front;
//     QueueNode* tail;
// } Queue;

typedef struct Queue{
    int size;
    int capacity;
    int *arr;
    int front;
    int tail;
} Queue;

typedef struct Graph {
  int V;     //number of vertices in G
  int ** M;  //2D array of ints, adjacency matrix
} Graph;

typedef struct DFS {
  COLOR color;  // white, gray, or black
  int parent;
  int discover;
  int finish;
} DFS;

typedef struct BFS{
    int *parent;//parent of each node in BFS tree
    int *distance;//distance from source node
    int visited;
    Queue *q;
}BFS;


// prototypes
Graph * createEmptyGraph(int numVertices);
void printGraph(Graph * g);
void freeGraph(Graph * g);
int degree(Graph * g, int v);
DFS * dfsInit(Graph * g);
Queue* createQueue();
BFS * bfsInit(Graph * g);;


//You will need to finalize the following functions
int addEdge(Graph * g, int src, int dest);
int outDegree(Graph * g, int v);
int inDegree(Graph * g, int v);
int isNeighbor(Graph * g, int x, int y);
void dfs(Graph * g, DFS arr[], int src);
void printReversePath(Graph * g, DFS arr[], int src, int dest);

Queue* createQueue();
int isEmpty(Queue* queue);
void enqueue(Queue* queue,int data);
int dequeue(Queue* queue);
void freeQueue(Queue *queue);
void bfs(Graph *g,BFS arr[], int src);
void printBFSPath(Graph *g, BFS arr[], int src, int dest);

#endif
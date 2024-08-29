#include "graph.h"

int time = 0;  // note that this is a global variable (not great programming
               // practice) but need to have a global time count for DFS
               // it would be better to pass in a pointer to a variable that
               // stores the time that dfs could access and update, but
               // for the purpose of keeping this lab simple, we have a
               // global variable

/* createEmptyGraph sets up the graph data structure with numVertices */
Graph * createEmptyGraph(int numVertices) {
  if(numVertices <= 0) {
    return NULL;
  }
  Graph * g = (Graph *)malloc(sizeof(Graph));
  if(g == NULL) {
    return NULL;
  }
  g->V = numVertices;
  g->M = (int **) malloc(sizeof(int *) * numVertices);

  //initializes the adjacency matrix to all zeros
  int i;
  if(g->M != NULL) {
    for(i = 0; i < numVertices; i++) {
      g->M[i] = (int *) malloc(sizeof(int) * numVertices);
      if(g->M[i] == NULL) {
	freeGraph(g);
	return NULL;
      }
    }
  }
  int j;
  for(i = 0; i < numVertices; i++) {
    for(j = 0; j < numVertices; j++) {
      g->M[i][j] = 0;
    }
  }
  return g;
}

/* freeGraph frees all memory associated with the graph */
void freeGraph(Graph * g) {
  if(g == NULL) {
    return;
  }
  int i;
  for(i = 0; i < g->V; i++) {
    free(g->M[i]);
  }
  free(g->M);
  free(g);
  g = NULL;
}

/* addEdge should do error-checking of the parameters and put a
   1 in the adjacency matrix at M[src][dest] */
int addEdge(Graph * g, int src, int dest) { //row src, col dest
  // HW Exercise 1
  //Check if graph is numm
  if (g == NULL){
    printf("Error: cannot add edge to null graph. \n");
  return 0;
  }
  //check if src or desk is out of range
    if (src < 0 || src >= g->V || dest < 0 || dest >= g->V){
        printf("Error: cannot add edge to vertex that is out of range. \n");
        return 0;
    }
    //check if edge already exists
    if (g->M[src][dest] == 1){
        printf("Error: cannot add edge that already exists. \n");
        return 0;
    }

    //Set adjacency matrix element to 1 and return success, means there is an edge from vertix src to vertex dest
    g->M[src][dest] = 1;
    return 1;

}

/* outDegree returns the out degree of a vertex v */
int outDegree(Graph * g, int v) {
    // HW Exercise 2
    //check if graph is null
    if(g==NULL){
        return 0;
    }
    //check if vertex is out of range
    if (v < 0 || v >= g->V){
        return 0;
    }
    //count the number of edges from other nodes to v and return this count
    int count = 0;
    int i;
    for (i = 0; i < g->V; i++){
        if (g->M[i][v] == 1){
            count++;
        }
    }
    return count;
}

/* inDegree returns the in degree of a vertex v */
int inDegree(Graph * g, int v) {
  /// HW Exercise 3
    //check if graph is null
    if(g==NULL){
        return 0;
    }
    //check if vertex is out of range
    if (v < 0 || v >= g->V){
        return 0;
    }
    //count the number of edges from v to other nodes and return this count
    int count = 0;
    int i;
    for (i = 0; i < g->V; i++){
        if (g->M[v][i] == 1){
            count++;
        }
    }
    return count;
}

/* degree returns the degree of a vertex v */
int degree(Graph * g, int v) {
  return inDegree(g, v) + outDegree(g, v);
}

/* printGraph prints the graph as a matrix */
void printGraph(Graph * g) {
  if(g == NULL) {
    return;
  }
  int i, j;
  printf("Matrix for graph:\n");
  for(i = 0; i < g->V; i++) {
    for(j = 0; j < g->V; j++) {
      printf("%d\t", g->M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* isNeighbor returns 1 if edge (x, y), x to y, exists; 0 otherwise */
int isNeighbor(Graph * g, int x, int y) {
  // HW Exercise 4
    //check if graph is null
    if(g==NULL){
        return 0;
    }
    //check if vertex is out of range
    if (x < 0 || x >= g->V || y < 0 || y >= g->V){
        return 0;
    }
    //check if there is an edge from x to y
    if (g->M[x][y] == 1){
        return 1;
    } else{
        return 0;
    }
}

/* dfsInit initializes the array of DFS structs, so that the parent
   is -1 for all nodes, color is white for all nodes, and discover and finish
   times are -1 */ 
DFS * dfsInit(Graph * g) {
  if(g == NULL || g->V <= 0) {
    time = 0;
    return NULL;
  }
  DFS * arr = malloc(sizeof(DFS) * g->V);
  int i;
  for(i = 0; i < g->V; i++) {
    arr[i].parent = -1;
    arr[i].color = white;
    arr[i].discover = -1;
    arr[i].finish = -1;
  }
  time = 0;
  return arr;
}

/* dfs does depth-first search of the graph from src, filling in the arr
   of DFS structs as it processes, should be recursive */
void dfs(Graph * g, DFS arr[], int src) {
  // do DFS from src node in graph g
  if(g == NULL || arr == NULL) {
    return;
  }
  if(src < 0 || src >= g->V) {
    return;
  }

    // HW Exercise 5
    //set the color of the source node to gray
    arr[src].color = gray;
    //set the discover time of the source node to the current time
    arr[src].discover = time;
    //increment the current time
    time++;

    printf("visited %d\n",src);
    //for each neighbor of the source node
    int i;
    for (i=0;i<g->V;i++) {
        if(isNeighbor(g,src,i) && arr[i].color == white){
            arr[i].parent = src;
            dfs(g,arr,i);
        }
    }
    //set the color of the source node to black
    arr[src].color = black;
    //set the finish time of the source node to the current time
    arr[src].finish = time;
    //increment the current time
    time++;

}

/* printReversePath prints the path from dest <- node <- node <- src <-
   note that you may assume that dfs has already filled in arr when
   doing dfs from the src */
void printReversePath(Graph * g, DFS arr[], int src, int dest) {
  // print path from dest to src
  // note: assuming arr has values set from dfs from src
  if(g == NULL || arr == NULL) {
    printf("graph or arr is invalid. No path.\n");
    return;
  }
  // start with dest and put it into an array
  printf("PATH: %d <-", dest);
  int current = dest;
  //assume graph has at most g->V vertices
  int path[g->V];
    int i = 0;
    path[i]= current;
    i++;

  // HW Exercise 7
  // trace path back to source
  while (current !=-1 && current != src){
    current = arr[current].parent;
    path[i]=current;
    i++;
  }
  //print path in reverse order
    for (i = i-1; i >= 0; i--){
        printf(" %d <-", path[i]);  
    }

  printf("\n");
}

Queue* createQueue(int capacity){
    Queue* queue =(Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->size=0;
    queue->capacity = capacity;
    queue->arr =(int *) malloc(sizeof(int) * capacity);
    if (queue->arr == NULL) {
        free(queue);
        return NULL;
    }

    queue->front =0;
    queue->tail = -1;
    return queue;
}

int isEmpty(Queue* queue){
    if (queue == NULL || queue->size == 0) {
        return 1;
    }
    return 0;
}


void enqueue(Queue *queue, int item) {
    if (queue == NULL || queue->size == queue->capacity) {
        return;
    }
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->arr[queue->tail] = item;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue == NULL || queue->size == 0) {
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void freeQueue(Queue *queue) {
    if (queue != NULL) {
        free(queue->arr);
        free(queue);
    }
}

/* bfsInit initializes the array of BFS structs, so that the parent
   is -1 for all nodes, distance is -1, and visited is 0 */
BFS * bfsInit(Graph * g) {
  if(g == NULL || g->V <= 0) {
    return NULL;
  }
  BFS * arr = malloc(sizeof(BFS) * g->V);
  int i;
  for(i = 0; i < g->V; i++) {
    arr[i].parent = -1;
    arr[i].distance = -1;
    arr[i].visited = 0;
  }
  return arr;
}


//bfs does breadth-first search of the graph from src, filling in the array of BFS structs as it processes
void bfs(Graph *g,BFS arr[], int src){
    if(g ==NULL || arr ==NULL){
        return;
    }
    if(src <0 || src >= g->V){
        return;
    }

    Queue *q = createQueue(g->V);
    int *visited =(int *) calloc (g->V,sizeof(int));

    visited[src]=1;
    enqueue(q,src);

    while(!isEmpty(q)){
        int current = dequeue(q);
        printf("visited %d\n",current);
        int i;
        for(i=0;i<g->V;i++){
            if(isNeighbor(g,current,i) && visited[i]==0){
                visited[i]=1;
                enqueue(q,i);
                arr[i].parent = current;
                arr[i].distance = arr[current].distance +1;
            }
        }    
    }
    freeQueue(q);
    free(visited);

}

/* printBFSPath prints the path from dest to src computed by BFS */
void printBFSPath(Graph *g, BFS arr[], int src, int dest) {
  // print path from dest to src
  // note: assuming arr has values set from bfs from src
  if (g == NULL || arr == NULL) {
    printf("graph or arr is invalid. No path.\n");
    return;
  }
  if (src < 0 || src >= g->V || dest < 0 || dest >= g->V) {
    printf("src or dest vertex invalid. No path.\n");
    return;
  }
  if (arr[dest].parent == -1) {
    printf("No path from %d to %d.\n", src, dest);
    return;
  }
  // start with dest and put it into an array
  int current = dest;
  int path[g->V];
  int i = 0;
  while (current != -1) {
    path[i++] = current;
    current = arr[current].parent;
  }

  // print the path
  printf("PATH: %d", path[--i]);
  while (i > 0) {
    printf(" <- %d", path[--i]);
  }
  printf("\n");
}

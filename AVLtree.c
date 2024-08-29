#include "AVLtree.h"

/*
insert key in subtree rootedwith node and returns new root of subtree.
*/
TNode* insertNodes(TNode* node, int key){
    /*BST insertion -usual technique , refer to notes */
    if (node == NULL)
        return(createNode(key));
    if (key < node->key)
        node->lChild  = insertNodes(node->lChild, key);
    else if (key > node->key)
        node->rChild = insertNodes(node->rChild, key);
    else // No duplicates in a BST
        return node;
    
    /* A update height of the node */
    node->nodeHeight = 1 + findmax(getHeight(node->lChild),getHeight(node->rChild));
 
    /* B. calculate balance factor (hLeft-hRigh)*/
    int balance = getBalancefactor(node);
 
    /*IF Node is unbalance, i.e balance is >1 or <-1, then it could be: */
 
    // 1. LEFT LEFT CASE (In this case, just rotate once on the RIGHT)
    if (balance > 1 && key < node->lChild->key)//if node is unbalanced and balance factor >1, key <left child key
        return rightRotation(node);
 
    // 2. RIGHT RIGHT CASE (In this case, just rotate once on the left)
    if (balance < -1 && key > node->rChild->key)//if node is unbalanced and balance factor <-1, key>right child key
        return leftRotation(node);
 
    // 3. LEFT - RIGHT CASE ()
    if (balance > 1 && key > node->lChild->key)//if node is unbalanced and balance factor >1, key >left child key
    {
        node->lChild =  leftRotation(node->lChild); //To make it a LEFT LEFT CASE
        return rightRotation(node);
    }
 
    // 4. RIGHT - LEFT CASE
    if (balance < -1 && key < node->rChild->key)//if node is unbalanced and balance factor <-1, key <right child key
    {
        node->rChild = rightRotation(node->rChild);//To make it a RIGHT RIGHT CASE
        return leftRotation(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
 
}
/* Create a new node with the given key and NULL lChild and rChild pointers. */
TNode* createNode(int key){
    TNode* node = (TNode*) malloc(sizeof(TNode));
    node->key   = key; //initialize the node's properties
    node->lChild   = NULL;
    node->rChild  = NULL;
    node->nodeHeight = 0;  //assume that node is added at leaf has height = 1
    return(node);
}

// A get method for height of the node.
int getHeight(TNode *node){
    if (node == NULL)
        return -1;
    return node->nodeHeight;
}


// This should show a sorted out tree(recall from last class)
void inorderTraversal(TNode *root){
    if(root != NULL)
    {
        inorderTraversal(root->lChild);
        printf("%d ", root->key);
        inorderTraversal(root->rChild);
    }
    
    return;
}
// This should show tree with root first (recall from last class)
void preorderTraversal(TNode *root){
    if(root != NULL)
    {
         printf("%d ", root->key);
         preorderTraversal(root->lChild);
         preorderTraversal(root->rChild);
    }
   return;
}

// return the largest value (used for height comparison)
int findmax(int x, int y){
    return (x > y)? x : y;
}

//This uses printNodeAtLevel to do a BFS traversal
void breadthFirstTraversal(TNode* root){
    for (int i=0; i<=getHeight(root); ++i ){
        printf("Level %d: ", i);
        printNodeAtLevel(root, i);
        printf("\n");
    }
} 

void printNodeAtLevel(TNode* node, int nodeLevel){
	//Print N (for Null) so that an entire complete tree can be visualized
    if (node == NULL) {
     printf("N  ");
     return;
     }
    if (nodeLevel ==0){
        printf("%d  ", node->key);
    }
    else if(nodeLevel > 0){
        printNodeAtLevel(node->lChild, nodeLevel-1);
        printNodeAtLevel(node->rChild, nodeLevel-1);
    }
 return;
}

// Exercise 1 (5 points)
int getBalancefactor(TNode* node){
   /*
   Calculates and returns the balance factor for a particular node. 
   */
  if(node==NULL) //if the given node is null, return 0 as the balace factor
  return 0;
  return getHeight(node->lChild)-getHeight(node->rChild);//calculate the balance factor by sunstracting the height of the right child and the left child 
}

// Exercise 2 (5 points)
void postOrderTraversal(TNode *root){
   /*
    - Uses recursive calls to traverse the tree using post order traversal
   */
  if(root !=NULL){
    postOrderTraversal(root->lChild); //recursively traverse the left subtree
    postOrderTraversal(root->rChild); //recursively traverse the right subtree
    printf("%d ", root->key); //print the key value
  }
   return;
}

 
// Exercise 3 (10 points)
TNode *rightRotation(TNode* nodeY){
    /*
 	- On receiving a particular node identified as LEFT Case
 	-(1) Rotate right
 	-(2) Update height of affected nodes
 	-(3) update and return the new root
 	*/
    TNode *nodeX = nodeY->lChild; //get the left child of nodeY
    TNode *nodeT = nodeX->rChild; //get the right child of nodeX

    nodeX->rChild = nodeY; //set the right child of nodeX as nodeY
    nodeY->lChild = nodeT; //set the left child of nodeY as a temp node

    //update the height of nodeX and nodeY will be the maximum of the heights of its children node plus 1
    nodeX->nodeHeight = findmax(getHeight(nodeX->lChild), getHeight(nodeX->rChild)) + 1; 
    nodeY->nodeHeight = findmax(getHeight(nodeY->lChild), getHeight(nodeY->rChild)) + 1;

    return nodeX; //return nodeX as the new root
}
 
// Exercise 4 (10 points)
TNode* leftRotation(TNode* nodeX){
 	/*
 	- On receiving a particular node identified as RIGHT Case
 	-(1) Rotate left
 	-(2) Update height of affected nodes
 	-(3) update and return the new root 
 	
 	*/

    TNode *nodeY = nodeX->rChild;//get the right child of nodeX
    TNode *nodeT = nodeY->lChild;//get the left child of nodeY

    nodeY->lChild = nodeX;//set the left child of nodeY as a temp node
    nodeX->rChild = nodeT;//set the right child of nodeX as nodeY

    //update the height of nodeX and nodeY will be the maximum of the heights of its children node plus 1
    nodeX->nodeHeight = findmax(getHeight(nodeX->lChild), getHeight(nodeX->rChild)) + 1;
    nodeY->nodeHeight = findmax(getHeight(nodeY->lChild), getHeight(nodeY->rChild)) + 1;

    return nodeY;// return nodeY as the new root
}
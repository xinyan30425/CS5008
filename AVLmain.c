// AVL tree (Dynamic Balancing using AVL)
// use gcc -Wall AVLmain.c AVLtree.c to compile
#include "AVLtree.h"
 

/* Driver program*/
int main(int argc, char** argv){
  TNode* root = NULL;
  int key;

  srand(time(NULL));
  /* create a tree now.*/
  for (int i =10; i<20;i++){
      key = rand()%100;
      root = insertNodes(root, key);
  }
 
  printf("Preorder traversal : \n");
  preorderTraversal(root);
  printf("\n");

  printf("Inorder traversal (sorted tree): \n");
  inorderTraversal(root);
  printf("\n");

  printf("Level printing: \n");
  breadthFirstTraversal(root);
  printf("\n");

  return 0;
}

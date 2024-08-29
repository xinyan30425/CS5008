/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct Stack {
    struct TreeNode **data;//pointer to an array of TreeNode pointer
    int top;//index of the top element in the stack
    int capacity;//maximum size of the stack
};

struct Stack *createStack(int capacity){
   struct Stack *stack =(struct Stack*) malloc (sizeof(struct Stack));
   stack -> capacity = capacity;
   stack -> top=-1;
   stack-> data =(struct TreeNode**) malloc (capacity *sizeof(struct TreeNode *));
   return stack;
}

bool isFull(struct Stack *stack){
  return stack->top == stack->capacity-1;
}

bool isEmpty(struct Stack *stack){
  return stack ->top ==-1;
}

void push(struct Stack *stack, struct TreeNode *node){
  if (isFull(stack)) 
  return;
  stack->data[++stack->top]=node;//increment the index of top by 1
}

struct TreeNode *pop(struct Stack *stack){
  if (isEmpty(stack)) 
  return NULL;
  return stack -> data[stack->top--];
}

bool isValidBST(struct TreeNode *root){
  if(root == NULL) 
  return true;

  struct Stack *stack = createStack(1000);
  struct TreeNode *previous = NULL;//previous pointer store the last visited TreeNode during the in-order traversal

  while (root || !isEmpty(stack)) {//loop continue until no more nodes to traverse
    while (root) {//traverse the left subtree of the current root, push each node onto the stack, until it reaches the leftmost node
      push(stack,root);
      root = root ->left;
    }

    root = pop(stack);

    if (previous && root ->val <= previous->val){
      return false;
    }

    previous = root;
    root = root->right;
  }

  return true;
}


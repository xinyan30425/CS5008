/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; //value of node
 *     struct ListNode *next; //pointer to the next node in the list 
 * };
 */
//merge sort O(n log n) 

// A head node in a linked list is the first node in the list. 
// It serves as the entry point or the starting point of the list. 
// Each node in a linked list contains two fields: 
// a data field that stores a value, 
// and a next field that stores a reference (or a pointer) to the next node in the list.

//define a function to merge two sorted lists
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
  if (!left) return right; //if left head node is empty, return right 
  if (!right)return left; //if right head node is empty, return left 

  //compare the head nodes and merge the lists recursively
  if(left->val < right->val){
    left->next = merge(left->next, right);
    return left;
  } else {
    right->next = merge (left,right->next);
    return right;
  }
}

//function to find the middle node of the lsit 
struct ListNode* findMiddle(struct ListNode* head){
  struct ListNode *slow = head;
  struct ListNode *fast = head;
  struct ListNode *prev = NULL;

  while (fast && fast->next){//run a loop until the fast pointer reaches the end of the list or its next pointer is NULL
    prev = slow;//update the previous pointer to the slow pointer
    slow = slow->next;//move slow pointer one step
    fast = fast ->next->next;//move fast pointer two steps
  }

  if(prev){ //if previous pointer is not NULL, set the next pointer of the previous node to NULL to break the input list into two parts
    prev->next = NULL;
  }
  return slow;
}

//define a function "sortList" that sorts the input linked list "head" using the merge sort algorithm
struct ListNode* sortList (struct ListNode* head){
  if(!head || !head->next){
    return head; //if list is empty or has one node, it is already sorted
  }

    struct ListNode* middle = findMiddle(head);//find the middle node of the input list
    struct ListNode* left = sortList(head); //recursive call to sort the left half of the list starts from head
    struct ListNode* right = sortList(middle);//recursive call to sort the right half starts from the middle node

return merge(left,right);
}


//insertion sort O(n^2)

//define a function to insert a new node into the sorted list
struct ListNode* sortedInsert(struct ListNode* sorted, struct ListNode* newNode){
  if(!sorted || newNode->val <= sorted->val){//if the sorted list is empty or the value of newNode is less than or equal to the value of the head node of the sorted list
    newNode->next = sorted; //set the new node's next pointer to the current head of the sorted list
    return newNode; //return the new node as the new head of the sorted list 
  }

  //initialize a pointer "current" to the head node of the sorted list 
  struct ListNode* current = sorted;

  //run a loop until the end of the list is reached or a node with a value greater than or equal to newNode->val is found
  while(current->next && current->next->val < newNode->val){
    current = current -> next; //move the current pointer to the next node in the sorted list
  }

  newNode-> next = current->next; //set the new node's next pointer to the node after the current node
  current-> next = newNode; //set the current node's next pointer to the new node

  return sorted;
}

struct ListNode* sortList(struct ListNode* head){
  //initialize a pointer to NULL, represents the head node of the sorted linked list
  struct ListNode* sorted = NULL;

  //initialize a pointer current to the head node of the input list
  struct ListNode* current = head;

  while(current){//run a loop until the end of the input list is reached
    //store the next node of the current node in a variable nextNode
    struct ListNode* nextNode = current->next;

    //call the sortedInsert funtion to insert the current node into the sorted list and update the head node of the sorted list
    sorted = sortedInsert(sorted, current);

    //update the current node to the next node
    current= nextNode;
  }
  return sorted;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
time complexity for both method is O(N* logK)
n is the total number of nodes across all the linked-lists
k is the number of linked lists
*/

//define a method to merge two lists in ascending order
//takes two pointers to ListNode
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //chekc if either of input linked lists is null
    if(!l1) return l2;
    if(!l2) return l1;

    //check if the value of the first node in l1 is less than or equal to the value of the first node in l2
    if(l1->val <= l2->val){
        //if true, current node in l1 maintains at the first in the merged list
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    } else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

//lists is an array of pointers to the individual linked-lists
/*
mergeKlist with recursion is based on top-down approach
recursively divide the array into two halves by finding the middle index until the base cases are reached（an empty array or an array with only one element）
the merging process is performed when the function calls start returning, combining the result from the left and right subproblem

The depth of the recursion tree is log (k)
at each level of the recursion tree, all n nodes will be processed in the merging step
*/

//takes in array of pointers to ListNode and the number of linked-lists in the array
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize ==0) return NULL;//if there are no linked-lists, return null
    if(listsSize ==1) return lists[0];//if there is only one linked list, return the head node of that lists as the merged result

    int mid = listsSize/2;//calculate the middle index of the lists array divide the array into 2 halves

    //call mergeKLists function recursively on the first half of the input array
    struct ListNode* left = mergeKLists(lists, mid);

    //call mergeKLists function recursively on the second half of the input array
    struct ListNode* right = mergeKLists(lists+ mid, listsSize-mid);

    return mergeTwoLists(left,right);

}

/*
mergeKlists without recursion
use a bottom-up approach
iteratively merges pairs of linked-lists in the array until there's only one list left
in each iteration, half of the linked-lists are merges with their adjacent lists,
reducing size of the array by half
process repeats until there's only one merged list left

the merging process occurs in log（k） iterations
in each iteration, half of the linked-list are merged with their adjacent lists,and all n nodes are processed
*/

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize ==0) return NULL;
    if (listsSize ==1) return lists[0];

    //while there is more than one linked list to merge, continue the merging process
    while(listsSize >1){

        //initialize a counter to track the number of merged linked-list in the current iteration 
        int mergedLists = 0;

        //iterate over the linked-lists array in pairs
        for (int i=0; i<listsSize-1; i+=2){
        //merge each pair of linked list and store the result in the lists array, increment the mergedLists counter
        lists[mergedLists++] =mergeTwoLists(lists[i],lists[i+1]);
        }
        //if there are an odd number of linked-lists, the last list doest have a apir to merge with
        if (listsSize %2){
            lists[mergedLists++]=lists[listsSize-1];
        }

        //update listsSize to the number of merged linked-lists in the current iteration
        listsSize = mergedLists;
    }

    // return the head node of the merged linked-list, which is sorted at the first position of the lists array
    return lists[0]

    }




////////
// Function to add a node to the end of a linked-list
void addNode(struct ListNode** head, struct ListNode* newNode) {
    if (!(*head)) {
        *head = newNode;
    } else {
        struct ListNode* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to combine all linked-lists into one
struct ListNode* combineLists(struct ListNode** lists, int listsSize) {
    struct ListNode* combined = NULL;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* current = lists[i];
        while (current) {
            struct ListNode* nextNode = current->next;
            current->next = NULL;
            addNode(&combined, current);
            current = nextNode;
        }
    }
    return combined;
}

// Function to split a linked-list into two halves
struct ListNode* split(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL;
    return mid;
}

// Function to merge two sorted linked-lists
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->val <= right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Function to perform merge sort on a linked-list
struct ListNode* mergeSort(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* mid = split(head);

    struct ListNode* left = mergeSort(head);
    struct ListNode* right = mergeSort(mid);

    return merge(left, right);
}

// Function to merge k sorted linked-lists using merge sort
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* combined = combineLists(lists, listsSize);
    return mergeSort(combined);
}
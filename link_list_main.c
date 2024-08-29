#include "list_list.h"

/* main function */
int main(void) {
  // LAB EXERCISE: update main to test the new functions
  Node * lst1 = NULL;
  Node * lst2 = NULL;

  insertHead(8, &lst1);
  insertHead(7, &lst1);
  insertHead(5, &lst1);
  insertHead(4, &lst1);

  printf("lst1 length: %d\n", length(lst1));
  printf("lst1 length (rec): %d\n", lengthRec(lst1));

  insertHead(25, &lst2);
  insertHead(21, &lst2);
  insertHead(20, &lst2);
  insertHead(15, &lst2);
  insertHead(13, &lst2);

  printf("lst2 length: %d\n", length(lst2));
  printf("lst2 length (rec): %d\n", lengthRec(lst2));

  Node * mergedList = mergeList(lst1, lst2);
  printf("Merged List:\n");
  print(mergedList);

  freeList(lst1);
  freeList(lst2);
  freeList(mergedList);

  Node * lst3=copyList(lst1);
  print(lst3);
  freeList(lst3);

  return EXIT_SUCCESS;

}
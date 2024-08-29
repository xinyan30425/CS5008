#include "hash.h"

/* initTable returns pointer to empty hash table */
HT * initTable(int n) { 
  HT * t = (HT *)malloc(sizeof(HT));//initialize a hash table of size n and allocates memory.
  if(t == NULL || n <= 0) { //check if memory allocation failed or if the input size is less or equal to 0
    return NULL;  //memory not allocated
  }
  t->size = n; //assigns hash table size
  t->numItems = 0;
  t->table = (char **)malloc(sizeof(char *) * n);//allocate memory to table array
  if(t->table == NULL) {
    return NULL;  //memory not allocated
  }
  int i;
  for(i = 0; i < t->size; i++) {
    t->table[i] = NULL;//initialize each element in the table array to null
  }
  return t;
}

/* freeTable frees all memory associated with the hash table */
void freeTable(HT * t) {
  if(t == NULL) return;
  free(t->table);
  free(t);
  t = NULL;
}

/* insert puts key into hash table
   if did not get inserted, return 0; else, return 1 */
int insert(char * key, HT * t) {//function inserts a key into the hash table 
  if(key == NULL || t == NULL || t->numItems == t->size) {
    printf("%s not inserted.\n", key);
    return 0;
  }
  if(find(key, t) >= 0) {
    printf("%s is already in hash table.\n", key);
    return 0;
  }
  // hash the key using the hash function and find location
  unsigned int hashValue = hash(key);//hash the key into hash function
  unsigned int location = hashValue % t->size;//calculate the initial location in the table array using the hash value 
  while((t->table[location] != NULL) && (strcmp(t->table[location], DELETE))) {
    location = location + 1; //update the location if collision
    location = location % t->size;  // wrap-around if necessary
  }
  // at this point, we have a location that is empty or has a delete flag
  t->table[location] = key; //inserts the key at the found location
  t->numItems++;
  return 1;
}

/* find searches for the key in the hash table and returns -1
   if not found and the array index of the key if it is found */
int find(char * key, HT * t) {
  // LAB EXERCISE 1: complete this function
  if (key ==NULL || t==NULL){
    return -1;
  }
    unsigned int hashValue = hash(key);//hash the key into hash function
    unsigned int location = hashValue % t->size;//calculate the initial location in the table array using the hash value 
    unsigned int origLocation =location;

    while(t->table[location] != NULL) {
        if (strcmp(t->table[location],key)==0){
        return location;
      }
      location = location + 1; //update the location if collision
      location = location % t->size;  // wrap-around if necessary

    if (location ==origLocation){
        break;
    }
}
  return -1;//key not found
}

/* delete removes the key from the hash table */
int delete(char * key, HT * t) {
  if(key == NULL || t == NULL) {
    return 0;
  }
  int location = find(key, t);
  if(location < 0) {  // key not in hash table
    return 0;
  }
  t->table[location] = DELETE;
  t->numItems--;
  return 1;
}

/* printTable prints the locations and keys of non-null cells 
   shows "D" for cells that have deleted items */
void printTable(HT * t) {
  int i;
  if(t == NULL) {//check if input hash table is NULL
    return;
  }
  printf("\nHASH TABLE CONTENTS:\n");
  printf("Num items: %d\n", t->numItems);
  printf("-----------------------\n");
  // LAB EXERCISE 2: complete this function

  for (i=0; i< t->size;i++){
    if(t->table[i] == NULL){
        printf("%d:(empty)\n",i);
    } else if (strcmp (t->table[i], DELETE) ==0){
        printf("%d:D\n",i);//if deleted, print D for that locatin
    } else {
        printf("%d:%s\n",i,t->table[i]);
    }
  }

  printf("-----------------------\n\n");
}

/* hash function maps strings to unsigned ints */
//use arthmetic operations and prime numbers to produce a unique unsigned integer for each unique key
unsigned int hash(char *key) {
  unsigned int rtnVal = 3253;
  char *p;
  for (p = key; *p != '\0'; p++) {
    rtnVal *= 28277;
    rtnVal += *p * 2749;
  }
  return rtnVal;
}
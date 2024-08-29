/*
What are the mumbers of the HT struct? Size, numItems, table

What values is used to represent a DELETED cell? The DELETED cell is represented by the string "DELETE" 

What location is used for inserting the key?
The location for inserting the given key depends on:
 hash value; 
 initial location in the table array using modulo of the hash value with the table size;
 if collision, use linear probing to find the next available location

*/

#include "hash.h"
/* main creates hash table, inserts items, deletes items, and finds items */

int main(void) {
  unsigned int N = 17;  //default hash table size
  HT * ht = initTable(N);

  //printTable(ht);
  
  int ok1 = insert("orange", ht);
  int ok2 = insert("banana", ht);
  int ok3 = insert("strawberry", ht);
  int ok4 = insert("pineapple", ht);
  int ok5 = insert("orange", ht);
  int ok6 = insert("chocolate", ht);
  int ok7 = insert("rice", ht);
  int ok8 = insert("corn", ht);
  int ok9 = insert("papaya", ht);

   printTable(ht);

  int loc1 = find("orange", ht);
  int loc2 = find("mango", ht);

  int d1 = delete("orange", ht);
  int d2 = delete("banana", ht);
  int d3 = delete("popcorn", ht);

  printTable(ht);

  int ok10 = insert("peanuts", ht);
  int ok11 = insert("green beans", ht);

  printTable(ht);

  int loc3 = find("peanuts", ht);
  int loc4 = find("orange", ht);

  int ok12 = insert("tangerine", ht);
  int ok13 = insert("hummus", ht);
  int ok14 = insert("yogurt", ht);

  printTable(ht);

  int loc5 = find("yogurt", ht);
  int loc6 = find("cereal", ht);

  int ok15 = insert("tang", ht);
  int ok16 = insert("hu", ht);
  int ok17 = insert("yo", ht);

  printTable(ht);


  freeTable(ht);
  return EXIT_SUCCESS;
}
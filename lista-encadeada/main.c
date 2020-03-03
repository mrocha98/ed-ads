#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
  Cell head;
  head.next = NULL;
  Cell *list = &head;
  for(int i = 0; i <= 10; i++)
    alocate(list, i);

  removeFromList(list, 0);

  printList(list);

  printf("Lower value of list: %d\n", findLower(list));

  freeList(list);
  printf("end of execution...\n");
  return 0;
}
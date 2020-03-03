#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void alocate(Cell *head, int x) {
  Cell *new = malloc(sizeof(Cell));
  new->value = x;
  new->next = head->next;
  head->next = new;
}

void printList(Cell *head) {
  printf("List: [\t");
  for(Cell *aux = head->next; aux != NULL; aux = aux->next) 
    printf("%d\t", aux->value);
  printf("]\n");
}

void freeList(Cell *head) {
  Cell *p = head->next;
  Cell *trash;
  while(p != NULL) {
    trash = p;
    p = p->next;
    free(trash);
  }
  head->next = NULL;
}

int findLower(Cell *head) {
  int lower = head->next->value;
  for(Cell *aux = head->next; aux != NULL; aux = aux->next) {
    if(aux->value < lower)
      lower = aux->value;
  }
  return lower;
}

void removeFromList(Cell *head, int x) {
  Cell *before = head;
  Cell *current = before->next;
  while(current != NULL) {
    printf("current value: %d\n", current->value);
    if(current->value == x) {
      printf("%d == %d\n", current->value, x);
      Cell *trash = current;
      current = current->next;
      before->next = current;
      free(trash);
      return;
    }
    before = current;
    current = current->next;
  }
}


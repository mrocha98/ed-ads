#ifndef LIST
#define LIST

typedef struct cell {
  int value;
  struct cell *next;
} Cell;

void alocate(Cell *head, int x);
void printList(Cell *head);
void freeList(Cell *head);
void removeFromList(Cell *head, int x);
int findLower(Cell *head);


#endif
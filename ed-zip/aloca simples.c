#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *p;
    p = malloc(sizeof(int));
    *p = 42;
    printf ("Variavel = %d\n", *p);
    system ("pause");
}

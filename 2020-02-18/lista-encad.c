#include <stdio.h>
#include <stdlib.h>


typedef struct cel
{
    int val;
    struct cel *prox;
} Celula;

void aloca(int x, Celula *p) {
    Celula *nova = malloc(sizeof(Celula));
    nova->val = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void imprime(Celula *p) {
    for (Celula *aux = p->prox; aux != NULL; aux = aux->prox)
        printf("%d\n", aux->val);
    printf("\n\n");
}

int menor(Celula *p) {
    int menor = p->prox->val;
    for (Celula *aux = p->prox; aux != NULL; aux = aux->prox) {
        if(aux->val < menor)
            menor = aux->val;
    }
    return menor;
}

int main(void) {
    Celula cabeca;
    cabeca.prox = NULL;
    Celula *lst = &cabeca;
    aloca(10, lst);
    aloca(11, lst);
    aloca(12, lst);
    aloca(13, lst);
    aloca(14, lst);
    aloca(15, lst);
    printf("%d\n", menor(lst));
    system("pause");
    return 0;
}
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

// ex.4
int menor(Celula *p) {
    int menor = p->prox->val;
    for (Celula *aux = p->prox; aux != NULL; aux = aux->prox) {
        if(aux->val < menor)
            menor = aux->val;
    }
    return menor;
}

// ex.13
void concatenaListas(Celula *p, Celula *q) {
    Celula *aux = p->prox;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = q->prox;
    q = p;
}

// ex.9
void converteVetorParaLista() {

}

int main(void) {
    Celula cabeca1;
    cabeca1.prox = NULL;
    Celula *lst1 = &cabeca1;
    aloca(10, lst1);
    aloca(11, lst1);
    aloca(12, lst1);
    aloca(13, lst1);
    aloca(14, lst1);
    aloca(15, lst1);

    Celula cabeca2;
    cabeca2.prox = NULL;
    Celula *lst2 = &cabeca2;
    aloca(100, lst2);
    aloca(200, lst2);
    aloca(300, lst2);
    aloca(400, lst2);
    aloca(500, lst2);
    aloca(600, lst2);

    concatenaListas(lst1, lst2);
    imprime(lst1);
    imprime(lst2);

    system("pause");
    return 0;
}
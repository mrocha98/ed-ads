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

// ex.4 - forma iterativa
int menor(Celula *p) {
    int menor = p->prox->val;
    for (Celula *aux = p->prox; aux != NULL; aux = aux->prox) {
        if(aux->val < menor)
            menor = aux->val;
    }
    return menor;
}

// ex.4 - forma recursiva
int menorRecursivo(Celula *p, int menor) { //menor == primeiro valor da lista
  Celula *aux = p;
  if(aux->prox == NULL) { //valida se é a última celula
    if(aux->val < menor) //valida se o valor dela é menor que o último menor encontrado
      return aux->val; //retorna o valor dela
    return menor; //caso contrário, retorna o último menor encontrado
  }
  if(aux->prox->val < menor)
    return menorRecursivo(aux->prox, aux->prox->val);
  return menorRecursivo(aux->prox, menor);
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
Celula* converteVetorParaLista(int v[], int len) {
  Celula cabeca;
  cabeca.prox = NULL;
  Celula *lst = &cabeca;
  //int *p = v;
  for(int i = len-1; i >= 0 ; i--) {
    Celula *nova = malloc(sizeof(Celula));
    nova->val = v[i];//*(p--);//*(p-i);
    nova->prox = lst->prox;
    lst->prox = nova;
  }
  return lst;
}

//ex. 18
void libera(Celula *p) {
  Celula *temp = p; 
  Celula *aux = p->prox;
  temp->prox = NULL; //deixa a cabeça sem um campo próximo

  while(aux != NULL) {
      temp = aux;
      aux = aux->prox;
      temp->prox = NULL;
      free(temp);
  }
}

//ex. 19
void inverte(Celula *head) {
  /*Celula *atual = head->prox;
  Celula *ultimoAnalisado = atual;
  head->prox = head->prox->prox;
*/
}

int main(void) {
    Celula cabeca1, cabeca2;
    cabeca1.prox = NULL;
    cabeca2.prox = NULL;
    Celula *lst1 = &cabeca1;
    Celula *lst2 = &cabeca2;
    for(int i = 10, j = 100; i <= 15 && j <= 600; i++, j+=100) {
      aloca(i, lst1);
      aloca(j, lst2);
    }
    
    libera(lst1);
    libera(lst2);

    #if defined(WIN32) || defined(WIN64)
      system("pause");
    #else
      printf("fim da execução, pressione enter para sair....\n");
      getchar();
    #endif
    
    return 0;
}
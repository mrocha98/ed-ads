#include <stdio.h>
#include <stdlib.h>

/*
Existem 3 operações: inserir, remover e alterar
Qual o pior caso de inserir e remover? No caso de um vetor de inteiros em C???
O pior caso é inserir e remover no início, pois vetores em C, são estruturas de dados,
com informações contíguas (dados um do lado do outro).
Para inserir no começo, preciso mover todos os 900k elementos para a direita
Para remover do começo, preciso mover todos os 900k elementos para a esquerda, tapando o butaco do removido.
Como resolver isso? Usando ponteiros!! Criando uma nova estrutura de dados, onde os elementos não estão mais contíguos,
mas ligados através de ponteiros!!

Fica mais fácil entender isso, pensando na brincadeira de Caça ao Tesouro, você vai num local inicial, procura uma pista para o próximo 
local e assim por diante.

O nome desta nova ED é Lista Encadeada, ou também, Lista Ligada, os elementos não estão um do lado do outro, mas são ligados por ponteiros,
assim, inserir e remover simplesmente mexe com ponteiros, sem mover todo mundo
*/

struct cel
{
  int conteudo;
  struct cel *seg;
};

/*
  Existem vários detalhes de implementação, onde inserir, no começo ou no final da lista
  Como testar lista vazia, como alterar o início...

  Na prática crio Listas Encadeadas usando alocação dinâmica de memória, e não apontando para variáveis. Se eu quiser um número grande de elementos,
  não posso declarar variáveis e apontar pra elas.

  Lista Ligada com cabeça com alocação.C

  Por que insiro ao contrário??

  Porque eu sempre insiro no início da lista encadeada, por motivos de performance, se inserisse no final, e alista fosse enorme,
  teria que andar todo mundo até chegar no fim.
  Inserindo no início, para ter 3, 5, 10, preciso inserir ao contrário, 10, 5, 3

  Lembrem que eu tenho outras decisões de implementação: como testar lista vazia? como alterar o início da lista?

  Vamos ver primeiro COM CABEÇA e depois comparar SEM CABEÇA para ver qual é melhor

  CABEÇA É UMA ESTRUTURA DE DADOS QUE TORNA A FUNÇÃO DE INSERIR MUITO MELHOR
  1) NÃO PRECISO TESTAR LISTA VAZIA, PORQUE PELO MENOS TEM SEMPRE A CABEÇA
  2) NÃO PRECISO PASSAR PONTEIROS PARA PONTEIROS, JÁ QUE LST APONTA PARA A CABEÇA
*/

int main(void)
{

  system("pause");
  return 0;
}

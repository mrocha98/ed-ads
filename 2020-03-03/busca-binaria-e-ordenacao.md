# Busca binária

Essa ideia, dividir o número de cada passo, dobrando o número de cada passo, é muit usada.
Se você tem um algoritmo de uma caixa de spam, a uma taxa que vai dobrando, em quantos passasos sua caixa de spam estará vazia?
log(n, 2) passos (n numero de SPAMS)

Se você tem uma folha de papel, e quer desenhar n quadradeinhos, em quantos passos você acaba? log(n, 2)
Exemplo: 64
 - Pego a folha dobro no meio 2 (1 passo)
 - Dobro no meio 4 (2 passos)
 - Dobro no meio 8 (3 passos)
 - Dobro no meio 16 (4 passos)
 - Dobro no meio 32 (5 passos)
 - Dobro no meio 64 (6 passos)

Cada passo dobra o tamanho de quadradinhos.

Pergunta: Busca Binária é muito rápido, mas o vetor tem que estar ordenado. Será que consigo colocar o vetor em ordem rápido também??
Resposta: Se colocar o vertor em ordem demora muito, não vale a pena a ideia da Busca Binária
Surpresa: os melhores algoritmos de ordenação usam a ideia de dividir em 2 ou dobrar a cada passo

# Algoritmos de ordenação

Vamos ver 5 algoritmos de ordenação
2 ruins (Inserção e Seleção)
3 bons (usam a ideia da Busca Binária, Mergesort, Quicksort, Heapsort)

Estudar algoritmos de ordenação é muito didático, vemos várias formas de atacar o mesmo problema!!!
Também como verificar se a solução é boa!!!

## Baralho

Inserção é o algoritmo do BARALHO
Quanto você recebe as cartas e quer ordenar, percorre da esquerda para a direita, enfia a carta atual na posição correta à esquerda

2 3 5 1 6 0 4 7
2 3 5 empurro 2 3 5
1 2 3 5 6 como é maior não mexo
0 1 2 3 5 6 zero menor empurro todo mundo
0 1 2 3 4 5 6 empurro 5 e 6
0 1 2 3 4 5 6 7 como é maior não mexo

## Análise do Algoritmo
Pior caso vetor em ordem descrescente
n passos para percorrer todo mundo
como sempre movo todo mundo, na última vez
movo n passo
isto é (n * n) no pior caso

### Coisas interessantes

Existem, na média, casos bons e ruins
  - Caso bom:
    - número entrando grande
  - Caso ruim:
    - número menor que todos à esquerda

Faça você: 
[ 3 7 5 4 2 1 0 6 ]
[ 7 6 5 2 4 3 1 0 ]
[ 7 6 5 4 3 2 1 0 ]
[ 0 1 2 3 4 5 6 7 ]

1)

3 5 7 (5 empurra 7)
3 4 5 7 (4 empurra 5 7)
2 3 4 5 7 (2 empurra todos)
1 2 3 4 5 7 (1 empurra todos)
0 1 2 3 4 5 7 (0 empurra todos)
0 1 2 3 4 5 6 7 (6 empurra apenas o 7)

2) 

7
6 7 (6 empurra 7)
5 6 7 (5 empurra 6 7)
2 5 6 7 (2 empurra todos)
2 4 5 6 7 (4 empurra 6 7)
2 3 4 5 6 7 (3 empurra 4 5 6 7)
1 2 3 4 5 6 7 (1 empurra todos)
0 1 2 3 4 5 6 7 (0 empurra todos)

3)

7
6 7
5 6 7
4 5 6 7
3 4 5 6 7
2 3 4 5 6 7
1 2 3 4 5 6 7
0 1 2 3 4 5 6 7 (cada novo empurra todos)
                (n ** 2 passos)


4)

0
0 1
0 1 2
0 1 2 3
0 1 2 3 4
0 1 2 3 4 5
0 1 2 3 4 5 6
0 1 2 3 4 5 6 7 (não empurro ninguém)
                (apenas n passos)
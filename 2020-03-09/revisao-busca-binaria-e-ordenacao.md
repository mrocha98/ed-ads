# Revisão Busca Binária

## Busca binária

Ideia geral através de um exemplo:

Se você tem 40 folhas com os nomes dos alunos da FATEC em ordem alfabética, para procurar um nome você abre no meio e vê se o nome é maior ou menor.
Nós vimos que Busca Binária é muito rápida, pois divide em 2 a todo momento, aplicando log(n, 2).


Minha busca num vetor ordenado custa n passos na Busca Sequencial.
Na Buca Binária gasta loga(n, 2), isso porque aproveito um DADO: meu vetor está em ordem crescente.

Busca binária necessita de um vetor ordenado. Pergunta: será que custa muito colocar em ordem?

## Ordenação

Começamos a estudar algoritmos de ordenação, que é um tópico que toda disciplina de ED estuda.
Existem vários algoritmos, assim podemos aprender a comparar e analisar algoritmos em geral.
Vamos estudar 5 algoritmos:
  - ruins:
    - inserção
    - seleção
  - bons:
    - mergesort
    - quicksort
    - heapsort

### Inserção

Algoritmo do baralho. Percorre as cartas da esquerda para direita e cada uma você coloca na posição correta do lado esquerdo.
Teste de mesa para: [5, 1, 6, 2, 0, 4, 3, 7]:
5
1 5                 (1 -> 5)
1 5 6               (6 caso bom)   
1 2 5 6             (2 -> 5 6)
0 1 2 5 6           (0 pior caso)
0 1 2 4 5 6         (4 -> 5 6)
0 1 2 3 4 5 6       (3 -> 4 5 6)
0 1 2 3 4 5 6 7     (7 melhor caso)

Teste de mesa para: [7, 3, 6, 4, 2, 5, 1, 0]:
7
3 7                 (3 -> 7)
3 6 7               (6 -> 7)
3 4 6 7             (4 -> 6 7)
2 3 4 6 7           (2 caso ruim)
2 3 4 5 6 7         (5 -> 6 7)
1 2 3 4 5 6 7       (1 caso ruim)
0 1 2 3 4 5 6 7     (0 pior caso)

Gasto n passos para percorrer todos, em cada um dos passos, no pior caso, movo todo mundo (ex. 0).
Isto é n * n, ou n ** 2 no pior caso.
No entanto, existem casos bons, por exemplo, quanto o  número atual é grande, movo poucos ou ninguém.
Então existe uma diferwnã entre analisar o pior caso, e o caso médio! Na média inserção não é tão ruim como n ** 2.


### Seleção

Percorro da esquerda da direita, só que vejo do atual para direita, qual o menor e troco com o atual

Teste de mesa para: [5, 1, 6, 2, 0, 4, 3, 7]:
5 1 6 2 0 4 3 7
0 1 6 2 5 4 3 7 (5 troca 0)
0 1 6 2 5 4 3 7 (1 troca 1)
0 1 2 6 5 4 3 7 (6 troca 2)
// Note que preciso percorrer todos para saber que 2 é o menor, visualmente sei disso porque sou humano, um programa não vê "tudo"
 0 1 2 3 5 4 6 7 (6 troca 3)
 0 1 2 3 4 5 6 7 (5 troca 4)
 0 1 2 3 4 5 6 7 (5 troca 5)
 0 1 2 3 4 5 6 7 (6 troca 6)
 0 1 2 3 4 5 6 7 (7 troca 7)
// nos 4 últimos passos, eu, humano, vejo que o resto está em ordem, mas um programa precisa fazer todos os passos

Teste de mesa para: [7, 3, 6, 4, 2, 5, 1, 0]:
7 3 6 4 2 5 1 0
0 3 6 4 2 5 1 7 (7 troca 0)
0 1 6 4 2 5 3 7 (3 troca 1)
0 1 2 4 6 5 3 7 (2 troca 6)
0 1 2 3 6 5 4 7 (3 troca 4)
0 1 2 3 4 5 6 7 (4 troca 6)
0 1 2 3 4 5 6 7 (5 troca 5) // humano vê, robô não
0 1 2 3 4 5 6 7 (6 troca 6)
0 1 2 3 4 5 6 7 (7 troca 7)

Seleção gasta n passos para percorrer todo mundo, cada passo demora todos à direita, no primeiro percorro n elementos.
Logo gasto n * n ou n ** 2 passos no pior caso, porém seleção não tem caso médio, sempre é o pior.
Como procuro o menor do lado direita, do qual não sei nada, ssempre percorro todos, ao contrário de inserção que vej o lado esquerdo conhecido (está em odem), vantagem de ter um DADO a mais. Por isso na média, inserção é melhor que seleção.


#### Análise
CONCEITO: Análise leva em conta caso pior e também caso médio.
Mais para frente vamos comparar dois algoritmos *muito* ruins
1. vê todos os subconjuntos, isto é 2**n elementos
2. vê todas as permutações, isto é n! elementos

2**n é muito, muito menor que n!

INSERÇÃO E SELEÇÃO no pior caso são n**2 passos, no caso médio inserção é melhor, pois usa um DADO a mais, lado esquerdo ordenado.

Vamos ver agora algoritmos melhores

### MERGESORT

merge === misturar

Se eu tenho dois vetores em ordem crescente, posso misturar para um terceiro vetor em ordem.
Analogia: duas fileiras de crianças em ordem de altura, vou vendo a criança menor que estpa na frente de cada fila, e passo para trás.

FILA 1: 21 15 7 3 2 (2 3 7 15 21)
FILA 2: 42 22 9 4 0 (0 4 9 22 42)
FILA ORDENADA: 
0 (0 < 2)
0 2 (2 < 4)
0 2 3 (3 < 4)
0 2 3 4 (4 < 7)
0 2 3 4 7 (7 < 9)
0 2 3 4 7 9 15 (15 < 21)
0 2 3 4 7 9 15 21 (21 < 22)
0 2 3 4 7 9 15 21 22 (22 < 42)
0 2 3 4 7 9 15 21 22 42 (sobrou 42)

FILA 1: 1 2 4 6
FILA 2: 0 3 5 7
0 (0 < 1)
0 1 (1 < 2)
0 1 2 (2 < 3)
0 1 2 3 (3 < 4)
0 1 2 3 4 (4 < 5)
0 1 2 3 4 5 (5 < 6)
0 1 2 3 4 5 6 (6 < 7)
0 1 2 3 4 5 6 7 (sobrou 7)

Sei que erge funciona para dois vetores ordenados, como ordeno todos?
Divido o vetor em 2
Divido cada metade em 2
Até chegar em tamanho <= 1
Vetor com 0 ou 1 elemento está em ordem, então posso juntar dois vetores de tamanho 1 e voltar até a origem
6412 3750 (2 vetores de 4)
64 12 37 50 (4 vetores de 2)
6 4 1 2 3 7 5 0 (8 vetores de 1)
46 12 37 05 (4 duplas em ordem)
1246 0357 (2 quadruplas em ordem)
01234567 (original em ordem)

abrir mergesort.py

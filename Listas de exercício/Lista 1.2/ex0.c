/*
a) Leia os valores de l e c que representam, respectivamente, a quantidade de linhas
e colunas de uma matriz de inteiros XXXXXXX



b) Aloque a matriz dinamicamente, primeiro aloque um vetor de ponteiros de
inteiros de tamanho l. Cada elemento desse vetor é um (int *) (passo 1) XXXXXXXXXXXXXXXX 

c) Depois faça cada elemento do vetor alocada apontar para um vetor de inteiros
alocado dinamicamente de maneira que os valores dos elementos da linha i
sejam armazenados no vetor apontado por m[i] (passo 2) XXXXXXXXXXXXXXXXXXXX


d) Preencher a matriz com valores simples digitados pelo usuário XXXXXXXXXXXXXXXXX

e) Imprimir a matriz linha por linha XXXXXXXXXXXXXXXXXXXXXx

f) Para cada linha, imprima o endereço de cada elemento (linha por linha) -
&m[i][j] XXXXXXXXXXXXXXXXXXXXX


g) Para i variando de 0 até a quantidade de linhas -1, imprima o valor de m[i]
Responda as seguintes perguntas:

1. O endereço de m[i] é igual a &m[i][0]?
Sim, o endereço de m[i] é igual a &m[i][0], pois m[i] aponta para o primeiro elemento da linha i.

2. Os elementos m[i][j] de uma mesma linha são contíguos?
Sim, os elementos m[i][j] de uma mesma linha são contíguos na memória, pois foram alocados em um único bloco de memória.

3. Os endereços dos elementos de linhas diferentes são contíguos? Por exemplo, o
endereço do último elemento da linha 0 é seguido do endereço do primeiro
elemento da linha 1?
Não, os endereços dos elementos de linhas diferentes não são contíguos, pois cada linha é alocada separadamente.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

int l, c; 
int **m;

printf("Digite a quantidade de linhas: ");
scanf(" %d", &l);
printf("Digite a quantidade de colunas: ");
scanf(" %d", &c);

m = (int **)malloc(l * sizeof(int *));

for(int i =0; i < l; i++) {
    m[i] = (int *)malloc(c * sizeof(int));
}

for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
        printf("Digite o elemento [%d][%d]: ", i, j);
        scanf(" %d", &m[i][j]);
    }
}

for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
        printf("linha %p: elemento [%d][%d] === %d\n", &m[i][j], i, j, m[i][j]);
    }
}

for(int i = 0; i < l; i++) {
    free(m[i]);
}

free(m);

return 0; 
}
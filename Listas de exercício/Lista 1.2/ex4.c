/*

Crie um programa com duas matrizes de dimensão 2 x 2. Uma matriz deve ser alocada
dinamicamente e a outra deve ser alocada de forma estática. Suponha que
os nomes das matrizes sejam matE (matriz estática) e matA (matriz dinâmica). Para cada
matriz, imprima:
• endereço de matE e matA
• endereço de cada linha da matriz
• o valor de matE[i] e matA[i], sendo i o número de cada linha da matriz
• endereço do primeiro elemento de cada linha da matriz
Usando o recurso de comentários, indique no seu código o trecho que representa cada item
solicitado. No final do código, para cada matriz, descreva quais valores foram iguais e
quais valores foram diferentes. O que representa este resultado?

*/

#include <stdio.h>
 
int main() {

    int matE[2][2];
    int **matA;

matA = (int **) malloc(2 * sizeof(int *));
for (int i = 0; i < 2; i++) {
    matA[i] = (int *) malloc(2 * sizeof(int));
}

if(!matA) {
    printf("Erro ao alocar memoria\n");
    return -1;
}

for(int i = 0; i < 2; i++) {
for(int j = 0; j < 2; j++) {
printf("Digite o elemento para matE[%d][%d]: ", i, j);
scanf("%d", &matE[i][j]);
printf("Digite o elemento para matA[%d][%d]: ", i, j);
scanf("%d", &matA[i][j]);
}

}


printf("MatE: %p\nMatA: %p\n", &matE, matA); 
for(int i = 0; i < 2; i++) {
    printf("Endereco da linha %d de matE: %p\n", i + 1, &matE[i]);
    printf("Endereco da linha %d de matA: %p\n", i + 1, matA[i]);
    printf("Valor de matE[%d]: %d\n", i, matE[i]);
    printf("Valor de matA[%d]: %d\n", i, matA[i]);
    printf("Endereco do primeiro elemento da linha %d de matE: %p\n", i + 1, &matE[i][0]);
    printf("Endereco do primeiro elemento da linha %d de matA: %p\n", i + 1, matA[i]);
}

    return 0;
}
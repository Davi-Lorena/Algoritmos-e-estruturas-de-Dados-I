/*

Crie um programa que multiplique duas matrizes de inteiros alocadas dinamicamente.
As dimensões das matrizes devem ser fornecidas pelo usuário. Utilize as funções
elaboradas no exercício anterior para alocar, preencher e imprimir as matrizes. A
impressão deve ser feita somente da matriz resultante da multiplicação.

*/


#include <stdio.h>
#include <stdlib.h>

int **alocaMatrizUm (int l, int c) {
    int **m1; 

m1 = (int **) malloc(l * sizeof(int *));

for(int i = 0; i < l; i++) {
    m1[i] = (int *) malloc(c * sizeof(int));
}

return m1;

}

int **alocaMatrizDois (int l, int c) {
    int **m2; 

m2 = (int **) malloc(l * sizeof(int *));

for(int i = 0; i < l; i++) {
    m2[i] = (int *) malloc(c * sizeof(int));
}

return m2;

}

void preencherMatrizUm(int **m1, int l, int c) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("Digite o elemento m[%d][%d] da primeira matriz: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    return;
}

void preencherMatrizDois(int **m2, int l, int c) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("Digite o elemento m[%d][%d] da segunda matriz: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    return;
}

void imprimeMatriz(int l, int c, int **m) {

    printf("Matriz: \n");

  for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
      printf(" %d ", m[i][j]);
    }
    printf("\n");
  }

  return;
}



int main() {

int l1, c1, l2, c2; 
int **mat1, **mat2, **matRes;

printf("Digite o numero de linhas da primeira matriz: ");
scanf(" %d", &l1);
printf("Digite o numero de colunas da primeira matriz: ");
scanf(" %d", &c1);

printf("Digite o numero de linhas da segunda matriz: ");
scanf(" %d", &l2);
printf("Digite o numero de colunas da segunda matriz: ");
scanf(" %d", &c2);

if (c1 != l2) {
    printf("Incompatibilidade de dimensoes!\n");
    return -1;
}

matRes = (int**) malloc(l1 * sizeof(int*));
for(int i = 0; i < l1; i++) {
    matRes[i] = (int*) malloc(c2 * sizeof(int));
}

mat1 = alocaMatrizUm(l1, c1);
mat2 = alocaMatrizDois(l2, c2);
preencherMatrizUm(mat1, l1, c1);
preencherMatrizDois(mat2, l2, c2);

/* 

00 * 00 + 01 * 10 | 00 * 01 + 01 + 11 
10 * 00 + 11 * 10 | 10 * 01 + 11 * 11  


*/

for(int i = 0; i < l1; i++) {
    for(int j = 0; j < c2; j++) {
        matRes[i][j] = 0;
        // O valor comparado com "k" pode ser ou c1 ou l2, tendo em vista a condição de multiplicação da matriz
        for(int k = 0; k < l2; k++) {
            matRes[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

imprimeMatriz(l1, c2, matRes);

for(int i = 0; i < l1; i++) {
    free(matRes[i]);
free(mat1[i]);
free(mat2[i]);
}

free(matRes);
free(mat1);
free(mat2);

return 0;
}
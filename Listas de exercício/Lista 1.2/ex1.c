/*

Elabore um programa com as seguintes funções:
- alocaMatriz: retornar uma matriz de inteiros de l linhas e c colunas alocada na
memória

- preencheMatriz: preencher os valores de uma matriz de inteiros com l linhas e c
colunas

- imprimeMatriz: imprimir os valores de uma matriz de inteiros com l linhas e c
colunas

Utilize as funções no programa principal.

*/

#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz (int l, int c) {
    int **m; 

m = (int **) malloc(l * sizeof(int *));

for(int i = 0; i < l; i++) {
    m[i] = (int *) malloc(c * sizeof(int));
}

return m;

}

void preencherMatriz(int **m, int l, int c) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("Digite o elemento m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    return;
}

void imprimeMatriz(int l, int c, int **m) {
    for(int i = 0; i < l; i ++) {
        for(int j = 0; j< c; j++) {
            printf("Elemento m[%d][%d]: %d\n", i, j, m[i][j]);
        }
    }
}



int main() {

int l, c; 
int **mat;

printf("Digite o numero de linhas: ");
scanf(" %d", &l);
printf("Digite o numero de colunas: ");
scanf(" %d", &c);

mat = alocaMatriz(l, c);
preencherMatriz(mat, l, c);
imprimeMatriz(l, c, mat);

for(int i = 0; i < l; i++) {
    free(mat[i]);
}
free(mat);

return 0;
}
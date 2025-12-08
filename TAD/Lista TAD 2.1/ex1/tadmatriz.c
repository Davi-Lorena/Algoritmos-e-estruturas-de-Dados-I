#include "tadmatriz.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz {
    int l;
    int c;
    int **m;
} tmatriz;

tmatriz *cria_matriz(int l, int c) {
    tmatriz *matriz;
    matriz = (tmatriz *)malloc(sizeof(tmatriz));
    matriz->l = l;
    matriz->c = c;
    matriz->m = (int **)malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) {
        matriz->m[i] = (int *)malloc(c * sizeof(int));
    }
    return matriz;
}

void preencheMatriz(tmatriz *matriz) {
    for (int i = 0; i < matriz->l; i++) {
        for (int j = 0; j < matriz->c; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz->m[i][j]);
        }
    }
}

void imprimeMatriz(tmatriz *matriz) {
    for (int i = 0; i < matriz->l; i++) {
        for (int j = 0; j < matriz->c; j++) {
            printf("%d ", matriz->m[i][j]);
        }
        printf("\n");
    }
}

void somaMatriz(tmatriz *matriz1, tmatriz *matriz2, tmatriz *resultado) {
    if (matriz1->l != matriz2->l || matriz1->c != matriz2->c) {
        printf("As matrizes devem ter as mesmas dimensoes para serem somadas.\n");
        return;
    }

    for (int i = 0; i < resultado->l; i++) {
        for (int j = 0; j < resultado->c; j++) {
            resultado->m[i][j] = matriz1->m[i][j] + matriz2->m[i][j];
        }
    }
}

void liberarMatriz (tmatriz *matriz) {

    for(int i = 0; i < matriz->l; i++) {
        free(matriz->m[i]);
    }
    free(matriz->m);
    free(matriz);
}


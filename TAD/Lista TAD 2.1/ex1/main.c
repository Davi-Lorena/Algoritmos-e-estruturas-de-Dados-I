#include "tadmatriz.h"
#include <stdio.h>


int main() {

    tmatriz *matriz1 = cria_matriz(2, 2);
    tmatriz *matriz2 = cria_matriz(2, 2);
    tmatriz *resultante = cria_matriz(2, 2);

    preencheMatriz(matriz1);
    preencheMatriz(matriz2);
    somaMatriz(matriz1, matriz2, resultante);
    imprimeMatriz(resultante);

    liberarMatriz(matriz1);
    liberarMatriz(matriz2);
    liberarMatriz(resultante);
    return 0;

}

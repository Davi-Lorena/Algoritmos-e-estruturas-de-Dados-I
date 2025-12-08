typedef struct matriz tmatriz;

tmatriz *cria_matriz(int l, int c);

void preencheMatriz(tmatriz *matriz);

void imprimeMatriz(tmatriz *matriz);

void somaMatriz(tmatriz *matriz1, tmatriz *matriz2, tmatriz *resultado);

void liberarMatriz(tmatriz *matriz);
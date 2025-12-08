#include <stdio.h>

void preencherNotas(float notas[10][3], char nomeArquivo[]) {
    
    FILE *arq = fopen(nomeArquivo, "r");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(arq, "%f", &notas[i][j]);
        }
    }
    fclose(arq);
}

void gerarRelatorio(float notas[10][3]) {

    int p1 = 0, p2 = 0, p3 = 0;

    for (int i = 0; i < 10; i++) {
        int indice_pior_nota = 0;
        if (notas[i][1] < notas[i][indice_pior_nota]) {
            indice_pior_nota = 1;
        }
        if (notas[i][2] < notas[i][indice_pior_nota]) {
            indice_pior_nota = 2;
        }

        if (indice_pior_nota == 0) {
            p1++;
        } else if (indice_pior_nota == 1) {
            p2++;
        } else {
            p3++;
        }
    }
    
    printf("%d %d %d \n", p1, p2, p3);
}

int main() {
    
    float notas[10][3];
    char nomeArquivo[21];
    
    scanf("%s", nomeArquivo);

    preencherNotas(notas, nomeArquivo);

    gerarRelatorio(notas);

    return 0;
}
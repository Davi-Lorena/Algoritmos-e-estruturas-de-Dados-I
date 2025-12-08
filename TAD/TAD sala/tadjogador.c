#include "tadjogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogador {
    char nome[51];
    float pontuacao;
} tjogador;


tjogador *cria_jogador(int n) {
    tjogador *j;

j = (tjogador *)malloc(n * sizeof(tjogador));
if (!j) {
    printf("Erro ao alocar memoria.\n");
    exit(1);
}

return j;

}

void preenchelista(tjogador *j, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s", j[i].nome);
        printf("Digite a pontuacao do jogador %d: ", i + 1);
        scanf("%f", &j[i].pontuacao);
    }
}

void altera_pontuacao(tjogador *j, char *nome, float pontnova, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(j[i].nome, nome) == 0) {
            j[i].pontuacao = pontnova;
            return;
        }
    }
}


void get_jogador(tjogador *j, char *nome, int n) {
for(int i = 0; i < n; i++) {
    if(strcmp(j[i].nome, nome) == 0) {
        printf("Nome: %s\n", j[i].nome);
        printf("Pontuacao: %.2f\n", j[i].pontuacao);
        return;
    }
}

}


void imprime_lista(tjogador *j, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", j[i].nome);
        printf("Pontuacao: %.2f\n", j[i].pontuacao);
    }
}

void libera_jogador(tjogador *j) {
    free(j);
}
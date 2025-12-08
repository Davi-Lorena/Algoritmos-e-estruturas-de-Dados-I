#include "tadjogador.h"
#include <stdio.h>

int main() {

    char nome[51];
    int n;
float pontuacao;

    printf("Digite o número de jogadores que serão cadastrados: ");
    scanf(" %d", &n);

    tjogador *jogadores = cria_jogador(n);
    preenchelista(jogadores, n);

    printf("Lista de jogadores:\n");
    imprime_lista(jogadores, n);

    printf("Digite o nome para alterar a pontuacao: ");
    scanf(" %[^\n]", nome);
    printf("Digite a nova pontuacao: ");
    scanf("%f", &pontuacao);
    altera_pontuacao(jogadores, nome, pontuacao, n);

    get_jogador(jogadores, nome, n);

    libera_jogador(jogadores);
    return 0;
}
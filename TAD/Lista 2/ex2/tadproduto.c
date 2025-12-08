#include <stdio.h>
#include <stdlib.h>
#include "tadproduto.h"

typedef struct produto {
int cod, quant;
float preco;
} tproduto;


tproduto *criar(int n) {

    tproduto *p;
    p = (tproduto*) malloc(n * sizeof(tproduto));

    return p;

}

void preencher(int n, tproduto *p) {

for(int i = 0; i < n; i++) {
    printf("Digite o código do produto: ");
    scanf(" %d", &p[i].cod);
printf("Digite a quantidade de produtos: ");
scanf(" %d", &p[i].quant);
printf("Digite o preço do produto: ");
scanf(" %f", &p[i].preco);

}

}

void imprimirMaior(int n, tproduto *p) {

float maior;

for(int i = 0; i < n; i++) {

if(p[i].preco > maior) {
    maior = p[i].preco;
}

}

printf("\nO produto mais caro é: %.2f\n", maior);
printf("\n");
}

void aumentarPorcentagem(int n, int porc, tproduto *p) {

float porcentagem = ( porc / 100.0 ) + 1;

for(int i = 0; i< n; i++) {

p[i].preco = p[i].preco * porcentagem;
printf("Valor alterado: %.2f\n", p[i].preco);
}

}



void maiorQuantidade(int n, tproduto *p) {

int maior;

for(int i = 0; i < n; i++) {
if(p[i].quant > maior) {
    maior = p[i].quant;
}
}

printf("Maior quantidade: %d\n", maior);

}

void liberar(tproduto *p) {
free(p);
}
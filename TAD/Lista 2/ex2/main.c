#include <stdio.h>
#include "tadproduto.h"

int main() {

int n, porcento;
tproduto *p;

printf("Digite a quantidade de produtos: ");
scanf("%d", &n);

p = criar(n);

preencher(n, p);

imprimirMaior(n, p);

printf("Digite a porcentagem a ser aumentada nos preços: ");
scanf(" %d", &porcento);

aumentarPorcentagem(n, porcento, p);

maiorQuantidade(n, p);

liberar(p);

}
#include <stdio.h>
#include "heap.h"

int main() {
char nomeArquivo[] = "entrada.txt";
heap *novaHeap = criaHeap(9);
int rem;

carregaElementos(nomeArquivo, novaHeap);

printf("Raiz: %d\n", retornaMaiorPrioridade(novaHeap));
printf("Quantidade de elementos: %d\n", retornaOcupacao(novaHeap));

imprimeVetor(novaHeap);

printf("Digite quantos elementos você quer remover: ");
scanf(" %d", &rem);

for(int i = 0; i < rem; i++) removeElemento(novaHeap);

printf("Raiz: %d\n", retornaMaiorPrioridade(novaHeap));
printf("Quantidade de elementos: %d\n", retornaOcupacao(novaHeap));

imprimeVetor(novaHeap);


    return 0;
}
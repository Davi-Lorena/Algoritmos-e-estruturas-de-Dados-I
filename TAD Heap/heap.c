#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

struct heap {
int tail; // Índice do último elemento da heap 
int *vet; // Vetor em que implementaremos a heap 
int tam; // Tamanho máximo da heap 
};

heap *criaHeap(int tam) {
heap *novaHeap = (heap*) malloc(sizeof(heap));

if(!novaHeap) return NULL;

novaHeap->vet = (int*) calloc(tam + 1, sizeof(int));

if(!novaHeap->vet) {
    free(novaHeap);
    return NULL;
}

novaHeap->tam = tam;
novaHeap->tail = 0;
return novaHeap;

}

int insereElemento(heap *h, int elemento) {
int i, aux;

h->tail++;

i = h->tail;

if(i > h->tam) return -1;

h->vet[i] = elemento;

while(i > 1 && h->vet[i] > h->vet[i/2]) {
aux = h->vet[i/2];
h->vet[i/2] = h->vet[i];
h->vet[i] = aux;
i = i/2;
}

return 1;

}

int carregaElementos(char nomeArq[], heap *h) {
FILE *arq = fopen(nomeArq, "r");
int element, aux;
if(!arq) return -1;

while(!feof(arq)) {

fscanf(arq, " %d", &element);

aux = insereElemento(h, element);

if(aux == -1) {
    fclose(arq);
    return -1;
}

}

fclose(arq);
return 1;
}

int retornaOcupacao(heap *h){ 
    return h->tail;
}

int retornaMaiorPrioridade(heap *h) {
    return h->vet[1];
}

int removeElemento(heap *h) {

if(!h->tail) return -1;

int aux = h->vet[1];
h->vet[1] = h->vet[h->tail];
h->vet[h->tail] = 0;
h->tail--;

if(h->tail)
    MaxHeapify(h, 1);

return aux;

}

void MaxHeapify(heap *h, int pos) {
    int l = pos * 2;
    int r = pos * 2 + 1;
int maior, aux;

if(l <= h->tail && h->vet[l] > h->vet[pos]) maior = l;
else maior = pos;

if(r <= h->tail && h->vet[r] > h->vet[maior]) maior = r;

if(maior != pos) {
aux = h->vet[pos];
h->vet[pos] = h->vet[maior];
h->vet[maior] = aux;

MaxHeapify(h, maior);
}
}

// Solução com passagem da posição 
void alteracaoPrioridade_pos(heap *h, int pos, int novaPrioridade) {
if(pos < 1 || pos > h->tail) return;

int aux = h->vet[pos];
h->vet[pos] = novaPrioridade;

if(novaPrioridade < aux)
    MaxHeapify(h, pos);
else {
int pai = pos / 2;
        while(pai && h->vet[pai] < h->vet[pos]) {
            aux = h->vet[pos];
            h->vet[pos] = h->vet[pai];
            h->vet[pai] = aux;
            pos = pai;
            pai = pai/2;
        }
}
}
// Solução com o elemento sendo a prioridade 

void alteracaoPrioridade_valor(heap *h, int elemento, int novaPrioridade){
 
int i = 1;

while(i <= h->tail && elemento != h->vet[i]) {
i++; // Guardará a posição do elemento
}

if(h->vet[i] != elemento) {
    printf("Elemento nao encontrado\n");
    return;
}

h->vet[i] = novaPrioridade;

if (novaPrioridade > elemento) {
        int aux;
        while(i > 1 && h->vet[i] > h->vet[i/2]) {
            aux = h->vet[i/2];
            h->vet[i/2] = h->vet[i];
            h->vet[i] = aux;
            i = i/2;
        }
    } else if (novaPrioridade < elemento) {
        MaxHeapify(h, i);
    }

}

void imprimeVetor(heap *h) {
    for(int i = 1; i <= h->tail; i++) {
        printf("Elemento %d do vetor: %d\n", i, h->vet[i]);
    }
}

void destroiHeap(heap *h) {
    if (h != NULL) {
        // 1. Libera o vetor
        free(h->vet);
        
        // 2. Libera a estrutura
        free(h);
    }
}


 /*int insereNo(heap *h, int elemento) {
int aux;

if(h->tail >= h->tam) return -1;

    if(!h->tail) {
        h->tail++;
        h->vet[1] = elemento;
        return 1;
    }
    
    h->tail++;
h->vet[h->tail] = elemento;

int pai = h->tail / 2;
int pos = h->tail;

while(pai && h->vet[pai] < h->vet[pos]) {
aux = h->vet[pai];
h->vet[pai] = h->vet[pos];
h->vet[pos] = aux;

pos = pai;
pai = pai / 2;
}
return 1;

} 

int removeElemento (heap *h) {

if(!h->tail) return -1;

int elementoRemovido = h->vet[1];

h->vet[1] = h->vet[h->tail];
h->tail--;

MaxHeapify(h, 1);   

return elementoRemovido;
}

void maxHeapify(heap *h, int pos) {
int r = pos * 2 + 1;
int l = pos * 2;
int aux, maior;

if(l <= h->tail && h->vet[pos] < h->vet[l]) maior = l;
else maior = pos;

if(r <= h->tail && h->vet[pos] < h->vet[r]) maior = r;

if(maior != pos) {
aux = h->vet[pos];
h->vet[pos] = h->vet[maior];
h->vet[maior] = aux;
maxHeapify(h, maior);
}

}

int alteraprioridade_pos(heap *h, int pos, int new) {

if(pos > h->tail || pos <= 0) return -1;

    int aux = h->vet[pos];

    h->vet[pos] = new;

    if(aux > new) {  
        maxHeapify(h, pos);
        return 1;
    }
    else {
int pai = pos / 2;

while(pai && h->vet[pai] < h->vet[pos]) {
    aux = h->vet[pos]; 
    h->vet[pos] = h->vet[pai];
    h->vet[pai] = aux;
    pos = pai;
    pai = pai/2;
}
    
    }

return 1;
}


int alteraprioridade_valor(heap *h, int valor, int new) {
int aux;
int ant;

while(aux <= h->tail && h->vet[aux] != valor) 
    aux++;

    if(h->vet[aux] != valor) return -1;

ant = h->vet[aux];
h->vet[aux] = new;

if(h->vet[aux] > ant) {
int pai = aux / 2;

while(pai && h->vet[pai] < h->vet[aux]) {
ant = h->vet[pai];
h->vet[pai] = h->vet[aux];
h->vet[aux] = ant;
aux = pai;
pai = pai/2;
}

} else maxHeapify(h, aux);

return 1;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

typedef struct no {
    int dado;
    tno *prox;
} tno;

typedef struct lista {
    tno *com;
} tlista;


tlista *crialista() {
tlista *l;

l = (tlista*) malloc(sizeof(tlista));

if(l) l->com = NULL;
else {
    printf("Erro de alocação!\n");
    exit(1);
}

return l;

}

int adicionano(tlista *l, int dado) {
    tno *novo, *aux, *ant = NULL;

novo = (tno*) malloc(sizeof(tno));

if(!novo) {
    printf("Erro de alocação de nó!\n");
    return 0;
}

novo->dado = dado;
novo->prox = NULL; 

if(!l->com) {
    l->com = novo;
    printf("O elemento inserido é o primeiro nó da lista!\n");
    return 1;
}

aux = l->com;

while(aux && aux->dado < dado) {
ant = aux;
aux = aux->prox;
}
novo->prox = aux;

if(!ant) {
l->com = novo;
printf("Elemento inserido no começo da lista!\n");
return 1;
} else {
ant->prox = novo;
return 1;
}

}

int removeno(tlista *l, int dado) {
tno *aux, *ant = NULL;

if(!l->com) {
    printf("Lista vazia!\n");
    return 0;
}

aux = l->com;

while(aux && aux->dado != dado) {
    ant = aux;
    aux = aux->prox;
}

if(!aux) {

    printf("O elemento não está na lista!\n");
    return 0;
    
}
    
    if(!ant) {
    l->com = aux->prox;
    } else {
    ant->prox = aux->prox;
    }

free(aux);
printf("Elemento %d removido com sucesso!\n", dado);
return 1;
}

int mostralista(tlista *l) {
    int i = 1;
tno *no;


if(!l->com) {
    printf("Lista vazia!\n");
    return 0;
}

no = l->com;

while(no) {
    printf("Dado %d: %d\n", i, no->dado);
    no = no->prox;
    i++;
}


}

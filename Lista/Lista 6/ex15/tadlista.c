#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

typedef struct no {
    int dado;
    tno *prox;
    tno *ant;
} tno;

typedef struct lista {
    tno *com;
    tno *fim;
} tlista;

tlista *crialista() {
tlista *l = (tlista*) malloc(sizeof(tlista));

if(l) {
    l->com = NULL;
    l->fim = NULL;
}

return l;

}


int insereno(tlista *l, int dado) {
tno *aux, *novo; 

novo = (tno*) malloc(sizeof(tno));

novo->dado = dado;
novo->ant = novo;
novo->prox = novo;  

if(!l->com) {
    l->com = novo; 
    l->fim = novo;
    return 1;
}

if(novo->dado < l->com->dado) {
novo->prox = l->com;
novo->ant = l->fim;
l->com->ant = novo; 
l->fim->prox = novo;
l->com = novo;
return 1;
}

aux = l->com->prox;

while(aux != l->com && aux->dado < dado) {
    aux = aux->prox;
}

    if(aux == l->com) {
novo->ant = l->fim;
novo->prox = l->com;
l->fim->prox = novo;
l->com->ant = novo;
l->fim = novo;
    } else {
        novo->prox = aux;
        novo->ant = aux->ant; 
        aux->ant->prox = novo; 
        aux->ant = novo;
    }

return 1; 

}

int removeno(tlista *l, int dado) {
tno *aux;

if(!l->com) return 0;

aux = l->com;

if(l->com == l->fim) {
    l->com = NULL;
    l->fim = NULL; 
    free(aux);
    return 1;
}

while(aux->prox != l->com && aux->dado != dado) {
    aux = aux->prox;
}

if(aux->dado == dado) {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    if(aux == l->com) {
        l->com = aux->prox;
    } else if(aux == l->fim) {
l->fim = aux->ant;
    } 

    free(aux);
  return 1;  
}

return 0;
}

void exibelista (tlista *l) {
tno *aux;

if(!l->com) return;

aux = l->com; 

do {
    printf("%d\n", aux->dado);
    aux = aux->prox;
}
while(aux->prox != l->com);

}

void exibetras(tlista *l) {
tno *aux; 

if(!l->com) return; 

aux = l->fim;

do {
    printf("%d\n", aux->dado);
    aux = aux->ant;
} while(aux->ant != l->fim); 

}

int pulaSoldados(tlista *l, int n) {
tno *aux = l->com;

while(l->com != l->fim) { 
    for(int i = 0; i < n; i++) {
aux = aux->prox; 
    }
  removeno(l, aux->dado);
}

return aux->dado;

}
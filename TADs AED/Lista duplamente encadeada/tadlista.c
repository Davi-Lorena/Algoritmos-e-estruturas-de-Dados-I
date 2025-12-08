#include <stdlib.h>
#include <stdio.h>
#include "tadlista.h"

typedef struct no {
int dado;
tno *prox;
tno *ant;
} tno;

typedef struct lista {
tno *inicio;
tno *fim;
} tlista;

tlista *crialista() {
tlista *l = (tlista*) malloc(sizeof(tlista));

if(l) {
    l->inicio = NULL;
    l->fim = NULL;
}

return l;

}

int insereno(tlista *l, int dado) {
tno *aux, *novo;

novo = (tno*) malloc(sizeof(tno)); 

if(novo) {

novo->dado = dado;
novo->ant = NULL;
novo->prox = NULL;

if(!l->inicio) {
    l->inicio = novo;
    l->fim = novo;
    return 1;
}

aux = l->inicio;

while(aux && aux->dado < dado)
    aux = aux->prox;

if(aux) {
    novo->prox = aux;
if(!aux->ant) {
aux->ant = novo;
l->inicio = novo;
} else {
novo->ant = aux->ant;
aux->ant->prox = novo;
aux->ant = novo;
}

} else {
    novo->ant = l->fim;
    l->fim->prox = novo;
    l->fim = novo;
}

    return 1;
}

return 0;
}

int removeno(tlista *l, int dado) {
tno *aux;

if(!l->inicio) return 0;

aux = l->inicio;

while(aux && aux->dado != dado) 
 aux = aux->prox;

if(aux) {

if(!aux->ant) {
    l->inicio = aux->prox;

    if(aux->prox) {
        aux->prox->ant = NULL;
    } else {
        l->fim = NULL; 
    }
} else {

    aux->ant->prox = aux->prox; 

    if(aux->prox) {
        aux->prox->ant = aux->ant; 
    } else {
        l->fim = aux->ant; 
    }

}

free(aux);
return 1;
} else {
    return 0; 
}


}
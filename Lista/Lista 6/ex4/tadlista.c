#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

typedef struct produto {
int cod;
float valor;
char pecu;
} tproduto;

typedef struct no {
tproduto x;
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

int insereno(tlista *l, int cod, float valor, char pecu) {
tno *no, *aux;

no = (tno*) malloc(sizeof(tno));

if(!no) return 0;

no->x.cod = cod;
no->x.pecu = pecu;
no->x.valor = valor;
no->ant = NULL;
no->prox = NULL;

if(!l->com) {
    l->com = no;
    l->fim = no;
    return 1;
}

aux = l->com;

while(aux && aux->x.cod < cod) {
    aux = aux->prox;
}

if(aux) {
    no->prox = aux;

if(!aux->ant) {
    aux->ant = no;
    l->com = no;
} else {
    aux->ant->prox = no;
    no->ant = aux->ant;
    aux->ant = no;
}

} else {
l->fim->prox = no;
no->ant = l->fim;
l->fim = no;
    
}

return 1;

}


int removeno(tlista *l, int cod) {
tno *aux;

if(!l->com) return 0;

aux = l->com;

while(aux && aux->x.cod != cod) {
    aux = aux->prox;
}

if(aux) {

if(!aux->ant) {
l->com = aux->prox;

if(!aux->prox) {
l->fim = NULL;
} else {
    aux->prox->ant = NULL;
}

} else {
aux->ant->prox = aux->prox;

if(!aux->prox) {
    l->fim = aux->ant;
} else {
    aux->prox->ant = aux->ant;
}

}

free(aux);
return 1;

} else {
return 0;
}

}

void mostralista(tlista *l) {
tno *no;

if(!l->com) return;

no = l->com; 

while(no) {
printf("\nCod: %d\nValor: %.2f\nPericulosidade: %c\n", no->x.cod, no->x.valor, no->x.pecu);
no = no->prox;
}

}


int retornaquant(tlista *l, char s) {
tno *no;
int count = 0;

if(!l->com) return 0;

no = l->com;

while(no) {
    if(no->x.pecu == s) count++;
    no = no->prox;
}

return count;

}

void imprimecod(tlista *l, int cod) {
tno *no;

if(!l->com) return;

no = l->com;

while(no) {

    if(no->x.cod == cod) {
        printf("Cod: %d\nValor: %.2f\nPericulosidade: %c", no->x.cod, no->x.valor, no->x.pecu);
        return;
    }

    no = no->prox;
}

printf("Produto nao encontrado\n");
}


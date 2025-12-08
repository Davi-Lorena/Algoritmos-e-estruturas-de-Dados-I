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
tno *no, *aux;

no =(tno*) malloc(sizeof(tno));

if(!no) return 0;

no->dado = dado;
no->prox = NULL;
no->ant = NULL;

if(!l->inicio) {
l->inicio = l->fim = no;
return 1;
}

aux = l->inicio;

while(aux && aux->dado < dado) {
    aux = aux->prox;
}

if(aux) {
    no->prox = aux;

if(!aux->ant) {
aux->ant = no;
l->inicio = no;
} else {
aux->ant->prox = no;
no->ant = aux->ant;
aux->ant = no;
}

} else {
no->ant = l->fim;
l->fim->prox = no;
l->fim = no;
}

return 1;

}

int removeno(tlista *l, int dado) {
    tno *aux;


    if (!l->inicio) return 0;

    aux = l->inicio;


    while (aux && aux->dado != dado) {
        aux = aux->prox;
    }


    if (aux) {

     
        if (!aux->ant) { 
            l->inicio = aux->prox;
            
    
            if (aux->prox) {
                aux->prox->ant = NULL;
            } else {
            
                l->fim = NULL; 
            }
        } 
        
    
        else {
            
       
            aux->ant->prox = aux->prox; 

        
            if (aux->prox) {
            
                aux->prox->ant = aux->ant; 
            } 
            
           
            else {
               
                l->fim = aux->ant; 
            }
        }

        free(aux);
        return 1;
    } else {
        
        return 0;
    }
}

int mostralista(tlista *l) {
tno *no;

if(!l->inicio) return 0;

no = l->inicio;

while(no) {
printf("%d\n", no->dado);
no = no->prox;
}

}


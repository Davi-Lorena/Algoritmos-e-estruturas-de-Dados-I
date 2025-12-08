#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"



typedef struct no {
tcliente x;
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

int insereno(tlista *l, tcliente cliente) {
tno *no, *aux; 

no = (tno*) malloc(sizeof(tno));

if(!no) return 0;

no->x = cliente;
no->ant = NULL;
no->prox = NULL;

if(!l->com) {
    l->com = l->fim = no;
    return 1;
}

aux = l->com;

while(aux && strcmp(aux->x.nome, cliente.nome) < 0) {
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
no->ant = l->fim;
l->fim->prox = no;
l->fim = no;
}

return 1;

}


int removeno(tlista *l, tcliente cliente) {

 tno *aux;


    if (!l->com) return 0;

    aux = l->com;


    while (aux && strcmp(aux->x.nome, cliente.nome)) {
        aux = aux->prox;
    }


    if (aux) {

     
        if (!aux->ant) { 
            l->com = aux->prox;
            
    
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

void mostralista(tlista *l) {
tno *no;

if(!l->com) return;

no = l->com; 

while(no) {
printf("\nCod: %d\nNome: %s\nEndereco: %s\nUltima compra: %s\nNascimento: %s\n", no->x.cod, no->x.nome, no->x.endereco, no->x.duc, no->x.dnsc);
no = no->prox;
}

}
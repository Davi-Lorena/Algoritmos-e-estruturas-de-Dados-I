#include <stdio.h>
#include <stdlib.h>
#include "TAD_Lista.h"

typedef struct no{
    int cod;
    float valor;
    struct no *prox;
} TNo; 

typedef struct lista{
    TNo *inicio; 
    int qtd;
} TLista; 


TLista *criaLista(){ 
    TLista *lista = (TLista*)malloc(sizeof(TLista));

    if(lista){
        lista->inicio= NULL;
        lista->qtd=0;
    }
    return lista;
}

// 'criaNo' (com 'N' Maiúsculo)
TNo *criaNo(int cod, float valor){ 
    TNo *no = (TNo*)malloc(sizeof(TNo));
    if (no){
        no->cod=cod;
        no->valor=valor;
        no->prox=NULL;
    }
    return no;
}

void insereInicioLista(TLista *lista, TNo *elemento){ 
    if(!lista || !elemento){
        return;
    }
    elemento->prox=lista->inicio;
    lista->inicio=elemento;
    lista->qtd++;
}

void insereFinalRec(TLista *lista,TNo *noAtual, TNo *pedido){ 
    if(!lista || !pedido){
        return;
    }

    if(lista->inicio==NULL) {
        insereInicioLista(lista, pedido);
        return;
    }

    if(noAtual->prox==NULL){
        noAtual->prox=pedido;
        lista->qtd++;
        return;
    }
    insereFinalRec(lista, noAtual->prox, pedido);
}

TNo *getLInicio(TLista *lista){ 
    if(lista==NULL){
        return NULL;
    }
    return lista->inicio;
}

void imprimeLista(TLista *lista){ 
    if(lista == NULL || lista->inicio==NULL){
        return;
    }

    TNo *aux = lista->inicio;

    while(aux != NULL){
        printf("%d\t",aux->cod); 
        aux = aux->prox;
    }
    
}

void esvaziaLista(TLista *lista){ 
    if(lista == NULL){
        return;
    }

    TNo *noAtual = lista->inicio;
    TNo *proximoNO;

    while( noAtual != NULL){
        proximoNO = noAtual->prox;
        free(noAtual);
        noAtual = proximoNO;
    }
    lista->inicio=NULL;
    lista->qtd=0;
}

void desalocaLista(TLista *lista){ 
    if(lista != NULL){
        esvaziaLista(lista);
        free(lista);
    }
}

float somaPedidos(TNo *inicio){ 
    if(inicio == NULL){
        return 0.0;
    }

    return inicio->valor + somaPedidos(inicio->prox);
}

float calculaMedia(TLista *lista){ 
    if(lista == NULL || lista->qtd==0){
        return 0.0;
    }

    float total = somaPedidos(lista->inicio);

    return total / (float)lista->qtd;
}

void pedidos(TLista *novalista, TNo *inicio){ 
    if(!inicio){
        return;
    }
    if(inicio->cod >= 0){
        TNo *novoPedido = criaNo(inicio->cod, inicio->valor); 
        if(novoPedido){
            insereFinalRec(novalista, getLInicio(novalista), novoPedido);
        }
    }

    pedidos(novalista, inicio->prox);
}
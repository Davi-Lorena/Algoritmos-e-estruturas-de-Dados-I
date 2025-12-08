#include <stdlib.h>
#include <stdio.h>
#include "tadlista.h" 

typedef struct no
{
    int dado;
    tno *prox;
} tno;

typedef struct lista {
tno *com;
} tlista;


tlista *crialista() {
tlista *l; 

l = (tlista*) malloc(sizeof(tlista));

if(l) {
    l->com = NULL;
    return l;
}

else printf("Erro de alocação da lista!\n");

}

int insereno(tlista *l, int dado) {
tno *novo, *aux, *ant = NULL;

novo = (tno*) malloc(sizeof(tno));
if(!novo) return 0;

novo->dado = dado;
novo->prox = NULL;

// Novo nó é o primeiro nó da lista 
if(!l->com) {l->com = novo;
return 1;
}

aux = l->com;

// O retorno desse while será ou o fim da lista ou o elemento que será o próximo do que vai ser inserido (aux)
while(aux && aux->dado < dado) {
    ant = aux;
aux = aux->prox;
}

novo->prox = aux;

if(!ant) { // O nó será inserido no começo da lista 
    l->com = novo;
} else ant->prox = novo; // o Nó será inserido no meio ou no final da lista;

return 1;
}


int excluirno(tlista *l, int dado) {
tno *aux, *ant = NULL;

if(!l->com) return 0; // Lista vazia, não tem o que excluir 

aux = l->com;

// O retorno desse while poderá ser:
// NULL -> O elemento não está na lista 
// Aux = nó desse elemento na lista
while(aux && aux->dado != dado) {
ant = aux; 
aux = aux->prox;
}

if(aux) {

if(ant) {
    // Se tiver ant, ou seja, estiver no meio ou no final da fila, alteramos o prox do ant para o prox do aux para remover o elemento
    ant->prox = aux->prox;
} else {
    // Se não tiver, removeremos o primeiro elemento da lista e, portanto, o próximo desse elemento deverá ser o começo
l->com = aux->prox;
}

free(aux);
printf("Elemento removido com sucesso!\n");
return 1;

}
else {
    printf("O elemento não está na lista!\n");
    return 0;
}

}

void mostralista(tlista *l) {
    tno *no; 

    no = l->com; 

    while(no)
    { 
printf("%d\n", no->dado);
no = no->prox;
    }
    return;
}
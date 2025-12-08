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

    // 1. Caso: Lista Vazia
    if (!l->inicio) return 0;

    aux = l->inicio;

    // 2. Caso: Lista com APENAS UM NÓ (o mais limpo é tratar isso após a busca)
    /* if(l->inicio == l->fim) {
        // ... (Bloco original removido para simplificar, pois a lógica final trata isso)
    } */

    // 3. Busca do Nó
    while (aux && aux->dado != dado) {
        aux = aux->prox;
    }

    // Se o nó foi encontrado
    if (aux) {

        // 4. Caso: O nó é o PRIMEIRO da lista
        if (!aux->ant) { 
            l->inicio = aux->prox;
            
            // Verifica se não é o único nó. Se não for, atualiza o novo primeiro.
            if (aux->prox) {
                aux->prox->ant = NULL;
            } else {
                // Se aux->prox é NULL, a lista ficou vazia
                l->fim = NULL; 
            }
        } 
        
        // 5. Caso: O nó está no MEIO ou no FIM (aux->ant não é NULL)
        else {
            
            // Conecta o nó ANTERIOR ao PRÓXIMO do nó removido
            aux->ant->prox = aux->prox; 

            // Se o nó removido TEM um sucessor (está no MEIO)
            if (aux->prox) {
                // Conecta o nó POSTERIOR ao ANTERIOR do nó removido
                aux->prox->ant = aux->ant; 
            } 
            
            // Se o nó removido NÃO TEM sucessor (está no FIM)
            else {
                // Atualiza o ponteiro 'fim' da lista para o nó anterior
                l->fim = aux->ant; 
            }
        }

        free(aux);
        return 1;
    } else {
        // Nó não encontrado
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


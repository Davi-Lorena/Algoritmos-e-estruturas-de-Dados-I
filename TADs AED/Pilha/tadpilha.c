#include <stdlib.h>
#include "tadpilha.h"

typedef struct no {
    int dado;
    tno *prox;
} tno;

typedef struct pilha {
    tno *topo; 
} tpilha;

tpilha *criapilha() {
tpilha *p = (tpilha*) malloc(sizeof(tpilha));

if(p) p->topo = NULL;

return p;
}

int empilha(tpilha *p, int dado) {
tno *no = (tno*) malloc(sizeof(tno));

no->dado = dado;
no->prox = p->topo;

if(p->topo) 
    p->topo = no;


return 1;

}

int desempilha(tpilha *p) {
    int dado;
    tno *no;

    if(!p->topo) return 0;

    no = p->topo;
    dado = p->topo->dado;
    p->topo = p->topo->prox;

free(no);
return dado;

}
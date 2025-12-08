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
tpilha *p;

p = (tpilha*) malloc(sizeof(tpilha));

if(p) p->topo = NULL;

return p;

}

int pilhavazia(tpilha *p) {
if(p->topo == NULL) return 1;
else return 0;

}

int empilha(tpilha *p, char dado) {
tno *no = (tno*) malloc(sizeof(tno));

if(!no) {
    return 0;
} else{

no->dado = dado;
no->prox = p->topo;
p->topo = no;

return 1;
}
}


char topo(tpilha *p) {
    if(pilhavazia(p)) exit(1);
    else return p->topo->dado;
}

char desempilha(tpilha *p) {

char dado;
tno *no;

if(pilhavazia(p)) {
    exit(1);
} else {
dado = p->topo->dado;
no = p->topo;
p->topo = p->topo->prox;
free(no);
return dado;
}


}


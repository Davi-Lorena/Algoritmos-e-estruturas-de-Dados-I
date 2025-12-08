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

 p = (tpilha *)malloc(sizeof(tpilha));

 if (p) p->topo = NULL;

 return p;

}

int pilhavazia(tpilha *p){
 if (!p->topo)
 return 1;
 else return 0;
}

int empilha (tpilha *p, int dado){
 tno *no;
 no = (tno *)malloc(sizeof(tno));

 if (!no) {
 return 0;
}

 else {
 no->dado = dado;
 no->prox = p->topo;
 p->topo = no;
 return 1;
}
}



int topo (tpilha *p){
 if(pilhavazia(p)) return -1;

 else return p->topo->dado;
}

int desempilha (tpilha *p){
 int dado;
 tno *no;
 if(pilhavazia(p)) return -1;

 else {
 dado = p->topo->dado;
 no = p->topo;
 p->topo = p->topo->prox;
 free(no);
 return dado;
}}

#include "tadponto.h"
#include <stdio.h>
#include <stdlib.h> 

struct ponto{
    int x;
    int y;
};

tponto *criaPonto(int x, int y){
    tponto *p = (tponto*) malloc(sizeof(tponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void imprimePonto(tponto *p){
    if(p != NULL){
        printf("Ponto: (%d, %d)\n", p->x, p->y);
    }
}

void alteraPonto(tponto *p, int x, int y){
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
}

void liberaPonto(tponto *p){
    free(p);
}

#include <stdlib.h>
#include "tadfila.h"

typedef struct no {
    int dado;
    tno *prox;
 } tno;

typedef struct fila {
    tno *com;
    tno *fim;
} tfila;

tfila *criarfila() {
tfila *f;

f = (tfila*) malloc(sizeof(tfila));

if(f) {
    f->com = NULL;
    f->fim = NULL;
}

return f;
}

int filavazia(tfila *f) {

if(f->com == NULL) return 1;
else return 0;
}

int enfileirar(tfila *f, int dado) {
tno *no;

no = (tno*) malloc(sizeof(tno));

if(no) {

no->dado = dado;
no->prox = NULL;

if(f->com == NULL) {
f->com = no;
f->fim = no; 
}

f->fim->prox = no;
f->fim = no;

return 1;
}

return 0;
}

int desenfileirar(tfila *f) {

tno *no;
int dado;

if(f->com == NULL) return -1;
  // fila vazia
else { 
dado = f->com->dado;
no = f->com;

if(f->com == f->fim) f->fim = NULL;

f->com = f->com->prox;

free(no);

return dado;
}


}

int primeirofila(tfila *f) {

if(f->com == NULL) return -1;

return f->com->dado;
}

void esvaziarfila(tfila *f) {
tno *no;

while(f->com != NULL) {
no = f->com;
f->com = f->com->prox;

free(no);
}

}

void liberarfila(tfila *f) {

if(f->com != NULL) {
tno *no;

while(f->com != NULL) {
no = f->com;
f->com = f->com->prox;

free(no);
}

}

free(f->com);
free(f->fim);
free(f);

}
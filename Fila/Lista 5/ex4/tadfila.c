#include <stdlib.h>
#include "tadfila.h"

typedef struct processo {
int num;
char tipo;
} tprocesso;

typedef struct no {
tprocesso dado;
tno *prox;
} tno;

typedef struct fila
{
    tno *com;
    tno *fim;
} tfila;


tfila *criarfila() {
tfila *f;

f = (tfila*) malloc(sizeof(tfila));

if(f) {
f->com = NULL;
f->fim = NULL;
return f;
}

}

int filavazia(tfila *f) {
if(f->com == NULL) return 1;
else return 0;
}

int enfileirar(tfila *f, int x, char y) {
tno *no;

no = (tno*) malloc(sizeof(tno));

if(no) {

no->dado.num = x;
no->dado.tipo = y;
no->prox = NULL;

if(f->com == NULL) {
    // Significa que esse é o primeiro nó da fila
    f->com = no;
    f->fim = no;
}

f->fim->prox = no;
f->fim = no;

return 1;
}
return 0;
}

void desenfileirar(tfila *f) {
tno *no;
tprocesso dado;

if(f->com == NULL) return;

dado = f->com->dado;
no = f->com;

if(f->com == f->fim) f->fim == NULL;

f->com = f->com->prox;

free(no);
return;

}

int iniciofilaNum(tfila *f) {
if(f->com == NULL) return -1;
else return f->com->dado.num;
}

char iniciofilaTipo(tfila *f) {
if(f->com == NULL) exit(-1);
else return f->com->dado.tipo;
}

void esvaziar(tfila *f) {
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
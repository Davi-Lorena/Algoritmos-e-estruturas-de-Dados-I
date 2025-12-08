#include <stdlib.h>
#include "tadfila.h"

typedef struct no {
    int dado;
    tno *prox;
} tno;

typedef struct fila {
    tno *inicio;
    tno *fim;
} tfila;

tfila *criarfila() {

tfila *f;

f = (tfila*) malloc(sizeof(tfila));

if(f) {
    f->inicio = NULL;
    f->fim = NULL;
}
return f;

}


int filavazia(tfila *f) {
if(f->inicio == NULL) return 1;
else return 0;
}


int enfileirar(tfila *f, int dado) {
tno *no;
no = (tno*) malloc(sizeof(tno));

if(no) {

no->dado = dado;
no->prox = NULL;

if(f->inicio == NULL) // Fila vazia 
{
f->inicio = no;
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

if(f->inicio == NULL) // Fila vazia 
    return -1;

dado = f->inicio->dado;
no = f->inicio;

if(f->inicio == f->fim) {
f->fim = NULL;
}
f->inicio = f->inicio->prox;
free(no);
return dado;

}

int iniciofila(tfila *f) {
if(f->inicio == NULL)
    return -1;

return f->inicio->dado;
}

void esvaziar(tfila *f) {
tno *no;

if(f->inicio == NULL)   
    return;

while(f->inicio != NULL) {
no = f->inicio;
f->inicio = f->inicio->prox;
free(no);
}


}

void liberarfila(tfila *f) {
if(f->inicio != NULL) { 
 tno *no;
    while(f->inicio != NULL) {
no = f->inicio;
f->inicio = f->fim->prox;
free(no);
}
}

free(f->inicio);
free(f->fim);
free(f);

}






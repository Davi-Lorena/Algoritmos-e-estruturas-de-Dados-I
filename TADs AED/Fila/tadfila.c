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

int enfileirar(tfila *f, int dado) {
tno *no = (tno*) malloc(sizeof(tno));

if(no) { 
no->dado = dado; 
no->prox = NULL;

if(!f->inicio) {
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

if(!f->inicio) return 0;

no = f->inicio;
dado = f->inicio->dado; 

if(f->inicio == f->fim) {
    f->fim = NULL;
    f->inicio = NULL;
}
 
    f->inicio = f->inicio->prox;


free(no);
return dado;


}
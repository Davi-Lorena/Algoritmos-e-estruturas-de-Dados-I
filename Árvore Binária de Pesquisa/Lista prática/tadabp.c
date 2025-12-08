#include <stdlib.h>
#include <stdio.h>
#include "tadabp.h"

/*
a) Inserção
b) Percurso em profundidade: pré-ordem, em-ordem e pós-ordem
c) Busca (retorna o nó com determinado valor ou -1 caso não exista)
d) Altura da árvore
e) Retornar o nó sucessor (contém o próximo valor de chave)
f) Retornar o nó predecessor
g) Maior valor armazenado na árvore
h) Menor valor armazenado na árvore
i) Número de nós folhas
j) Número de nós internos
k) Verificação se a árvore é estritamente binária (retornar 1 ou 0, caso contrário)
l) Verificação se a árvore é binária cheia*/

struct arvore {
tno *raiz;
};

struct no {
int chave;
tno *esq, *dir;
};

tno *criaNo(int dado){
tno *no = (tno*) malloc(sizeof(tno));

if(no) {
    no->chave = dado;
    no->esq = no->dir = NULL;
}

return no;
}

tabp *criaArvore() {
    tabp *arv = (tabp*) malloc(sizeof(tabp));

    if(arv) arv->raiz = NULL;

    return arv;
}

// a) Inserção

void insereNo(tabp *arv, tno *no) {

tno *aux = arv->raiz, *pai = NULL;

if(!aux) {
    arv->raiz = no;
    return;
}

while(aux) {
pai = aux;
if(aux->chave < no->chave) aux = aux->dir;
else aux = aux->esq;
}

if(pai->chave < no->chave) pai->dir = no;
else pai->esq = no;

return;
}

void carregaNo(tabp *arv, char *nomeArquivo) {
FILE *arq = fopen(nomeArquivo, "r");
tno *no;
int dado;

if(!arq) return;

while(!feof(arq)) {
fscanf(arq, "%d", &dado);

no = criaNo(dado);
if(!no) return;

insereNo(arv, no);
}

fclose(arq);
return;
} 

// b) Percurso em profundidade: pré-ordem, em-ordem e pós-ordem
void buscaPreOrdem(tno *raiz) {

if(!raiz) return;

printf("%d", raiz->chave);
buscaPreOrdem(raiz->esq);
buscaPreOrdem(raiz->dir);

}
void buscaEmOrdem(tno *raiz) {
if(!raiz) return;

buscaEmOrdem(raiz->esq);
printf("%d", raiz->chave);
buscaEmOrdem(raiz->dir);
}
void buscaPosOrdem(tno *raiz) {
    if(!raiz) return;

    buscaPosOrdem(raiz->dir);
    printf("%d", raiz->chave);
    buscaPosOrdem(raiz->esq);
}

tno *retornaRaiz(tabp *arv) {
    return arv->raiz;
}

// c) Busca (retorna o nó com determinado valor ou -1 caso não exista)
tno *buscaNo(tabp *arv, int dado) {
tno *aux = arv->raiz;

while(aux && aux->chave != dado) {
    if(aux->chave > dado) aux = aux->esq;
    else aux = aux->dir;
}

return aux;

}

//d) Altura da árvore
int alturaArvore(tno *raiz) {
int alturaDir = 0, alturaEsq = 0; 
if(!raiz) return -1;

alturaEsq = 1 + alturaArvore(raiz->esq);
alturaDir = 1 + alturaArvore(raiz->dir);

if(alturaDir > alturaEsq) return alturaDir;
else return alturaEsq;

}


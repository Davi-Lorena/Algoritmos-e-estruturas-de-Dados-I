#include "tadabp.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int chave;
    tno *esq, *dir;
} tno;

typedef struct abp
{
    tno *raiz;
} tabp;

tabp *criaArvore()
{
    tabp *arvore = (tabp *)malloc(sizeof(tabp));

    if (arvore)
    {
        arvore->raiz = NULL;
    }

    return arvore;
}

tno *criaNo(int chave)
{
    tno *novoNo = (tno *)malloc(sizeof(tno));

    if (novoNo)
    {
        novoNo->chave = chave;
        novoNo->esq = novoNo->dir = NULL;
    }

    return novoNo;
}

void insereNo(tno *no, tabp *arv)
{
    tno *aux, *pai;

    if (!arv->raiz)
    {
        arv->raiz = no;
        return;
    }

    aux = arv->raiz;

    while (aux)
    {
        pai = aux;
        if (no->chave < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (no->chave < pai->chave)
        pai->esq = no;
    else
        pai->dir = no;
}

int carregaNo(tabp *arv, char *nomeArquivo)
{
    FILE *arq;
    tno *novo;
    int chave;

    arq = fopen(nomeArquivo, "r");

    if (!arq)
        return -1;

    while (!feof(arq))
    {
        fscanf(arq, "%d", &chave); // Vantajoso só para UM elemento por linha

        novo = criaNo(chave);
        if (!novo)
            return -1;

        insereNo(novo, arv);
    }

    fclose(arq);
    return 1;
}

void percorrePreOrdem(tno *no)
{

    if (!no)
        return;

    printf("%d\n", no->chave);
    percorrePreOrdem(no->esq);
    percorrePreOrdem(no->dir);
}

void percorreOrdem(tno *no)
{
    if (!no)
        return;

    percorrePreOrdem(no->esq);
    printf("%d\n", no->chave);
    percorrePreOrdem(no->dir);
}

void percorrePosOrdem(tno *no)
{

    if (!no)
        return;

    percorrePreOrdem(no->dir);
    printf("%d\n", no->chave);
    percorrePreOrdem(no->esq);
}

tno *retornaRaiz(tabp *arv)
{

    if (arv->raiz)
        return arv->raiz;
}

// Métodos de busca - Valor e Nó

int buscaValor(tabp *arv, int dado)
{

    tno *aux = arv->raiz;

    while (aux && aux->chave != dado)
    {
        if (dado < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    return aux->chave;
}

tno *buscaNo(tabp *arv, int dado)
{

    tno *aux = arv->raiz;

    while (aux && aux->chave != dado)
    {
        if (aux->chave < dado)
            aux = aux->dir;
        else
            aux = aux->esq;
    }

    return aux;
}

// Encontrar altura da árvore
int altura(tno *raiz)
{
    int altDir, altEsq;
    tno *aux = raiz;

    if (!aux)
        return -1;

    altEsq = 1 + altura(aux->esq);
    altDir = 1 + altura(aux->dir);

    if (altEsq > altDir)
        return altEsq;
    else
        return altDir;
}

// sucessor é o nó mais à esquerda da sub-árvore à direita
tno *sucessor(tabp *arv)
{

    tno *suc = arv->raiz->dir;

    while (suc->esq)
        suc = suc->esq;

    return suc;
}

// antecessor é o nó mais à direita da sub-árvore da esquerda

tno *antecessor(tabp *arv)
{

    tno *ant = arv->raiz->esq;

    while (ant->dir)
        ant = ant->dir;

    return ant;
}

int removeNo(tabp *arv, int chave)
{
    tno *aux, *pai = NULL;

    // Passo 1: Buscar o elemento na árvore
    aux = arv->raiz;

    if (!aux)
        return 0; // Árvore vazia
    

    while (aux && aux->chave != chave)
    {
        pai = aux;
        if (chave < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
        
    }

    if (!aux)
        return 0; // Elemento não encontrado

    // Passo 2: Verificar se o nó tem grau 2
    if (aux->esq && aux->dir)
    {
        tno *pred = aux->esq;
        while (pred->dir)
        {
            pai = pred;
            pred = pred->dir;
        }

        // Fazer a cópia dos dados
        aux->chave = pred->chave;
        // Substituir o nó que será removido fisicamente da árvore
        aux = pred;
    }

    // Passo 3: Verificar se nó tem grau 1
    if (aux->esq || aux->dir)
    {
        if (aux->esq)
        {
            if (aux == pai->esq)
                pai->esq = aux->esq;
            

            else
                pai->dir = aux->esq;
        }

        else
        { // o nó tem um filho à direita
            if (aux == pai->esq)
                pai->esq = aux->dir;
            else
                pai->dir = aux->dir;
        }
    }

    if (!aux->esq && !aux->dir)
    { // Nó folha
        if (aux == pai->esq)
            pai->esq = NULL;
        else
            pai->dir = NULL;
    }
    free(aux);
    return 1;
}

tno *maiorNo(tabp *arv)
{

    tno *aux = arv->raiz->dir;

    while (aux->dir)
        aux = aux->dir;

    return aux;
}

tno *menorNo(tabp *arv){ 
    tno *aux = arv->raiz->esq;

    while (aux->esq)
        aux = aux->esq;

    return aux;
}

int arvIguais(tno *raiz1, tno *raiz2) {

if(!raiz1 && !raiz2) return 1;

return (arvIguais(raiz1->esq, raiz2->esq) && arvIguais(raiz1->dir, raiz2->dir));

}

int NosFolhas(tno *no) { 
    if (!no) {
        return 0;
    }

    if (!no->esq && !no->dir) {
        return 1;
    }

    return NosFolhas(no->esq) + NosFolhas(no->dir);
}

int nosInternos(tno *no) {
    if (!no) 
        return 0;

    if (!no->esq || !no->dir) 
        return 1;     

    return nosInternos(no->esq) + nosInternos(no->dir);

}

int totalNos(tno *no) {

    if(!no)
        return 0;

    return 1 + totalNos(no->esq) + totalNos(no->dir);

}

int valorTotal(tno *no) {

    if(!no)
        return 0;

    return no->chave + valorTotal(no->esq) + valorTotal(no->dir);

}

int estritamenteBinaria(tno *no) {

if(!no) return 1;

    if(!no->esq != !no->dir) 
        return 0;

        return estritamenteBinaria(no->esq) && estritamenteBinaria(no->dir);
}

int arvoreCompleta(tno *no, int altura) {
int aux = altura - 2;


    if(!no->esq && no->dir)
    return 0;

}


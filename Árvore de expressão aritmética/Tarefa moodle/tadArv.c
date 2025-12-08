#include "arvExpressao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvExpr
{
    struct noArv *raiz;
};

struct noArv
{
    char chave;
    struct noArv *esq;
    struct noArv *dir;
};

struct pilhaArv
{
    struct NopilhaArv *topo;
};

struct NopilhaArv
{
    struct noArv *no;
    struct NopilhaArv *prox;
};

arv *criaArvoreExpressao()
{
    arv *novaArvore=(arv*)malloc(sizeof(arv));
    if (!novaArvore) return NULL;
    novaArvore->raiz=NULL;
    return novaArvore;
}

noArvore *criaNoArvore(char token)
{
    noArvore *novoNo=(noArvore*)malloc(sizeof(noArvore));
    if (!novoNo) return NULL;
    novoNo->chave=token;
    novoNo->esq=NULL;
    novoNo->dir=NULL;
    return novoNo;
}

pArvore *criaPilhaArvore()
{
    pArvore *novaPilha = (pArvore*)malloc(sizeof(pArvore));
    if (!novaPilha) return NULL;
    novaPilha->topo = NULL;
    return novaPilha;
}

noPArvore *criaNoPArvore(noArvore *novoNo)
{
    noPArvore *novoNoP = (noPArvore*)malloc(sizeof(noPArvore));
    if (!novoNoP) return NULL;
    novoNoP->no=novoNo;
    novoNoP->prox=NULL;
    return novoNoP;
}

int prioridade(char token)
{
    int prioridade=0;
    switch (token)
    {
        case '+':prioridade=1;break;
        case '-':prioridade=1;break;
        case '*':prioridade=2;break;
        case '/':prioridade=2;break;
    }
    return prioridade;
}

void converteExpressao(char *expressao, pC *p, fila *f)
{
    char token;
    int tamanho, i;
    tamanho=strlen(expressao);
    if (!f||!p) return;
    for (i=0;i<tamanho;i++)
    {
        token=expressao[i];
        if ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z'))
        {
            noC *novoNo = criaNo(token);
            enfileirar(f, novoNo);
        }
        else if (token == '+'||token == '-'||token == '*'||token == '/')
        {
            while (retornaElemento(p) != ' ' && retornaElemento(p) != '(' && (prioridade(retornaElemento(p)) > prioridade(token) || (prioridade(retornaElemento(p)) == prioridade(token))))
            {
                noC *operador = desempilha(p); //se tiver menos prioridade que o atual, desempilha e enfileira
                enfileirar(f, operador);
            }
            
            noC *operador=criaNo(token);
            empilha(p, operador); //empilha o operador atual
        }
        else if (token=='(')
        {
            noC *novoNo = criaNo(token);
            empilha(p, novoNo);
        }
        else if (token == ')')
        {
            while (retornaElemento(p)!= ' ' && retornaElemento(p) != '(')
            {
                noC *operador = desempilha(p);
                enfileirar(f, operador);
            }
            if (retornaElemento(p)== '(')
            {
                desempilha(p);
            }
        }
    }
    while (retornaElemento(p)!=' ')
    {
        noC *operador = desempilha(p);
        enfileirar(f, operador);
    }
}

void geraArvoreExpressao(fila *f, arv *a)
{
    char token;
    pArvore *pArv = criaPilhaArvore();
    noC *aux=retornaCabeca(f);
    while (aux!=NULL)
    {
        token = retornaToken(aux);
        noArvore *novoNo = criaNoArvore(token);
        processaToken(pArv, novoNo);
        aux = retornaProx(aux);
    }
    if (pArv->topo!=NULL)
    {
        a->raiz = desempilhaNoArvore(pArv);
    }
    free(pArv);
}

void processaToken(pArvore *pArv, noArvore *novoNo)
{
    char token = novoNo->chave;
    if ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z'))
    {
        noPArvore *novoNoP = criaNoPArvore(novoNo);
        empilhaNoArvore(pArv, novoNoP);
    }
    else if (token == '+' || token == '-' || token == '*' || token == '/')
    {
        novoNo->dir=desempilhaNoArvore(pArv);
        novoNo->esq=desempilhaNoArvore(pArv);
        noPArvore *novoNoP = criaNoPArvore(novoNo);
        empilhaNoArvore(pArv, novoNoP);
    }
    else
    {
        free(novoNo);
    }
}

void empilhaNoArvore(pArvore *pArv, noPArvore *novoNo)
{
    if (!pArv->topo)
    {
        pArv->topo=novoNo;
        return;
    }
    novoNo->prox=pArv->topo;
    pArv->topo=novoNo;
}

noArvore *desempilhaNoArvore(pArvore *pArv)
{
    if (!pArv->topo) return NULL;
    noPArvore *aux = pArv->topo;
    noArvore *no = aux->no;

    pArv->topo = pArv->topo->prox;
    free(aux);
    return no;
}

float avaliaExpressao(noArvore *no, float a, float b)
{
    float ESQ, DIR;
    if (!no) return 0.0;
    char token=no->chave;
    if ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z'))
    {
        if (token >= '0' && token <= '9') return (float)(token - '0');
        else if (token == 'a') return a;
        else if (token == 'b') return b;
        else return 0.0;
    }
    ESQ=avaliaExpressao(no->esq, a, b);
    DIR=avaliaExpressao(no->dir, a, b);
    switch (token)
    {
        case '+': return ESQ+DIR;
        case '-': return ESQ-DIR;
        case '*': return ESQ*DIR;
        case '/': return ESQ/DIR;
        default: return 0.0;
    }
}

noArvore *retornaRaiz(arv *arvExpr)
{
    if (!arvExpr) return NULL;

    return arvExpr->raiz;
}


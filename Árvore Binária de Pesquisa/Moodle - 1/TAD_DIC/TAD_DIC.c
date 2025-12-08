#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TAD_DIC.h"

typedef struct abp 
{
    pal *raiz;
} dic;
typedef struct no
{
    char palavra[11];
    char descri[31];
    pal *esq, *dir;
} pal;

dic *criaDic() {
dic* novoDic = (dic*) malloc(sizeof(dic)); 

if(novoDic) {
novoDic->raiz = NULL;
}

return novoDic;

}

pal *criaNo(char palavra[10], char significado[30]) {
pal *novaPal = (pal*) malloc(sizeof(pal));

if(novaPal) {
strcpy(novaPal->palavra, palavra);
strcpy(novaPal->descri, significado);
novaPal->dir = novaPal->esq = NULL;
}

return novaPal;

}

//lê uma lista de palavras de um arquivo e a insere no dicionário
void carregaDicionario(dic *dicionario, char nomeArquivo[20]) {
    FILE *arq = fopen(nomeArquivo, "r");
pal *aux, *pai;


if (!arq) return;

while(!feof(arq)) {
    
    pal *novaPal = (pal*) malloc(sizeof(pal));
    
    novaPal->esq = novaPal->dir = NULL;

    if(!novaPal) return;

aux = dicionario->raiz;
pai = NULL;

fscanf(arq, " %s %[^\n]", novaPal->palavra, novaPal->descri);

int len = strlen(novaPal->descri);

if (len > 0 && novaPal->descri[len - 1] == '\r') {
    novaPal->descri[len - 1] = '\0';
}

if(!aux) {
dicionario->raiz = novaPal;
} else {

while(aux) {

pai = aux;

if(strcmp(aux->palavra, novaPal->palavra) > 0) aux = aux->esq;
else aux = aux->dir;

}

if(strcmp(pai->palavra, novaPal->palavra) > 0) pai->esq = novaPal;
else pai->dir = novaPal;

}
}


fclose(arq);
}

//Insere uma palavra no dicionário
void inserePalavra(dic *dicionario, pal *novaPalavra) {

pal *pai = NULL;
pal *aux = dicionario->raiz;

if(!aux) dicionario->raiz = novaPalavra;

while(aux) {

pai = aux;

if(strcmp(aux->palavra, novaPalavra->palavra) > 0) aux = aux->esq;
else aux = aux->dir;

}

if(strcmp(pai->palavra, novaPalavra->palavra) > 0) pai->esq = novaPalavra;
else pai->dir = novaPalavra;

return;
}

//Busca a palavra no dicionário e imprime na tela o significado
//Se não encontrar a palavra, chama a função que busca por palavras com o
//mesmo prefixo (4 caracteres) para sugerir outras palavras
void buscaPalavra(dic *dicionario, char palavra[11]) {
char prefixo[4];
pal *aux = dicionario->raiz;

if(!aux) return;

while(aux && strcmp(aux->palavra, palavra)) {

if(strcmp(aux->palavra, palavra) > 0) aux = aux->esq;
else aux = aux->dir;

}

if(aux) {
    printf("%s : %s\n", aux->palavra, aux->descri);
} else {
strncpy(prefixo, palavra, 3);
printf("Palavra não encontrada - Sugestões:\n");
    sugerePalavras(dicionario->raiz, prefixo);
}

}

//busca por palavras que tem o mesmo prefixo da palavra solicitada
//Retorna um vetor com essas palavras
void sugerePalavras(pal *no, char *prefixo) {

if(!no) return;

if(!strncmp(no->palavra, prefixo, 3)) 
    printf("%s\n", no->palavra);

sugerePalavras(no->esq, prefixo);
sugerePalavras(no->dir, prefixo);

}

//Mostra palavras do dicionário em pré-ordem
void percorrePreOrdem(pal *palavra) {

if(!palavra) return;

printf("%s\n", palavra->palavra);
percorrePreOrdem(palavra->esq);
percorrePreOrdem(palavra->dir);
}

//Mostra palavras do dicionário em ordem alfabética
void percorreEmOrdem(pal *palavra) {
    if(!palavra) return;

percorreEmOrdem(palavra->esq);
printf("%s\n", palavra->palavra);
percorreEmOrdem(palavra->dir);
}

//Mostra palavras do dicionário em ordem alfabética
void percorrePosOrdem(pal *palavra) {
    if(!palavra) return;

    percorrePosOrdem(palavra->dir);
    printf("%s\n", palavra->palavra);
percorrePosOrdem(palavra->esq);
}

//Retorna a raiz da árvore
pal *getRaiz(dic *dicionario) {
    return dicionario->raiz;
}


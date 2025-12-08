#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_DIC.h"

struct abp {
    pal *raiz;
};

struct no {
    char nome[11], def[41];
    pal *esq, *dir;
};

dic *criaDic() {
    dic *abp = malloc(sizeof(dic));

    if (abp) {
        abp->raiz = NULL;
    }
    return abp;
};

pal *criaNo(char palavra[], char significado[]) {
    pal *p = malloc(sizeof(pal));

    if (p) {
        strcpy(p->nome, palavra);
        strcpy(p->def, significado);
        p->dir = NULL;
        p->esq = NULL;
    }
    return p;
}

void carregaDicionario(dic *dicionario, char *nomeArquivo) {
    FILE *arq;
    pal *novaPalavra;
    char nome[11], def[41];

    arq = fopen(nomeArquivo, "r");
    if (!arq) {
        printf("Não foi possível ler o arquivo.\n");
        return;
    } 
    while (!feof(arq)) {
        fscanf(arq, " %s %[^\n]", nome, def);
        
        int len = strlen(novaPalavra->def);

if (len > 0 && novaPalavra->def[len - 1] == '\r') {
    novaPalavra->def[len - 1] = '\0';
}

        novaPalavra = criaNo(nome, def);
        inserePalavra(dicionario, novaPalavra);
    }

    fclose(arq);
    return;
}

void inserePalavra(dic *dicionario, pal *novaPalavra) {
    pal *aux, *pai;

    if (!dicionario->raiz) {
        dicionario->raiz = novaPalavra;
        return;
    }
    aux = dicionario->raiz;
    while (aux) { //enquanto aux existir, ele varrerá a árvore de modo a achar a posição correta para a inserção da palavra
        pai = aux;
        if (strcmp(novaPalavra->nome, aux->nome) > 0) 
            aux = aux->dir;
        else 
            aux = aux->esq;
    }
    if (strcmp(novaPalavra->nome, pai->nome) > 0) //agora, basta preencher a posição encontrada com essa palavra 
        pai->dir = novaPalavra;
    else 
        pai->esq = novaPalavra;

    return;
}

void buscaPalavra(dic *dicionario, char palavra[11]) {
    pal *aux = dicionario->raiz;
    char prefixo[4];

    if (!aux)
        return;
    while (aux && strcmp(aux->nome, palavra)) {
        if (strcmp(palavra, aux->nome) > 0)
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    if (!aux) {
        strncpy(prefixo, palavra, 3);
        printf("Palavra não encontrada - Sugestões:\n");
        sugerePalavras(dicionario->raiz, prefixo);
    } else 
        printf("%s : %s\n",aux->nome, aux->def);
    
    return;
}

void sugerePalavras(pal *no, char *prefixo) {
    if (!no)
        return; 
        
    if (!strncmp(no->nome, prefixo, 3))
        printf("%s\n", no->nome);

    sugerePalavras(no->dir, prefixo);
    sugerePalavras(no->esq, prefixo);
    return;
}

void percorrePreOrdem(pal *palavra) {
    if (!palavra) 
        return;

    printf("%s\n", palavra->nome);    
    percorrePreOrdem(palavra->esq);
    percorrePreOrdem(palavra->dir);
    return;
}

void percorreEmOrdem(pal *palavra) {
    if (!palavra) 
        return;
    
    percorreEmOrdem(palavra->esq);
    printf("%s\n", palavra->nome);    
    percorreEmOrdem(palavra->dir);
    return;
}

void percorrePosOrdem(pal *palavra) {
    if (!palavra) 
        return;

    percorrePosOrdem(palavra->dir);
    printf("%s\n", palavra->nome);    
    percorrePosOrdem(palavra->esq);
    return;
}

pal *getRaiz(dic *dicionario) {
    if (dicionario->raiz) 
        return dicionario->raiz;
}

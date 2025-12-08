#include <stdio.h>
#include <stdlib.h>
#include "tadpessoa.h"

typedef struct pessoa {
char nome [101], cpf[101], dataNascimento[101];
} tpessoa;


tpessoa *criarPreencher(int n) {

    tpessoa *p = (tpessoa *) malloc(n * sizeof(tpessoa));

for(int i = 0; i < n; i++) {
printf("Digite o nome da pessoa: ");
scanf(" %[^\n]", p[i].nome);
printf("Digite o cpf da pessoa: ");
scanf(" %[^\n]", p[i].cpf);
printf("Digite a data de nascimento da pessoa: ");
scanf(" %[^\n]", p[i].dataNascimento);
}

return p;

}

void imprimir(int n, tpessoa *p) {

for(int i = 0; i < n; i++) {

    printf("\n");
    printf("Pessoa: %s\nCpf: %s\nData de nascimento: %s\n", p[i].nome, p[i].cpf, p[i].dataNascimento);

}

}


void liberar(tpessoa *p) {
    free(p);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadcandidato.h"

typedef struct candidato {
char identidade[101], nome[101], grau[101], data[101], profissao[101]; 
} tcandidato;

tcandidato *criaListaCandidato(int n) {

tcandidato *p = (tcandidato*) malloc(n * sizeof(tcandidato));

for(int i = 0; i < n; i++) {
printf("Digite a identidade do candidato: ");
scanf(" %[^\n]", p[i].identidade);
printf("Digite o nome do candidato: ");
scanf(" %[^\n]", p[i].nome);
printf("Digite o grau de escolaridade do candidato: ");
scanf(" %[^\n]", p[i].grau);
printf("Digite a data de nascimento do candidato: ");
scanf(" %[^\n]", p[i].data);
printf("Digite a profissao do candidato: ");
scanf(" %[^\n]", p[i].profissao);
printf("\n");
}

return p;

}


void buscarCId (int n, char ident[], tcandidato *p) {

for(int i = 0; i < n; i++) {

    if(!strcmp(ident, p[i].identidade)){
        printf("\nNome: %s\nGrau de escolaridade: %s\nData de nascimento: %s\nProfissao: %s\n",p[i].nome, p[i].grau, p[i].data, p[i].profissao);
        return;
    }

}


}

void buscaCE(int n, char grau[], tcandidato *p) {

    int cont = 0;
for(int i = 0; i < n; i++) {

    if(!strcmp(grau, p[i].grau)){
cont++;
    }

}

printf("\nQuantidade de candidatos com esse grau: %d\n", cont);
}

void imprimeNomeProf(int n, char profissao[], tcandidato *p) {


for(int i = 0; i < n; i++) {

    if(!strcmp(profissao, p[i].profissao)){
        printf("\nNome: %s\nIdentidade: %s\nData de nascimento: %s\nGrau de escolaridade: %s\n",p[i].nome, p[i].identidade, p[i].data, p[i].grau);
    }

}

}

void liberaCandidato (tcandidato *p) {

    free(p);
}
#include <stdio.h>
#include "tadcandidato.h"

int main() {

int n;
char identidade[101], escolaridade[101], profissao[101];
tcandidato *p; 

printf("Digite a quantidade de candidatos: ");
scanf(" %d", &n);

p = criaListaCandidato(n);

printf("Digite o número de identidade a ser buscado: ");
scanf(" %[^\n]", identidade);

buscarCId(n, identidade, p);

printf("Digite o grau de escolaridade a ser buscado: ");
scanf(" %[^\n]", escolaridade);

buscaCE(n, escolaridade, p);

printf("Digite a profissao a ser buscada: ");
scanf(" %[^\n]", profissao);

imprimeNomeProf(n, profissao, p);

liberaCandidato(p);

}

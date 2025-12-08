#include <stdio.h>
#include <stdlib.h>
#include "tadalunos.h"

int main() {
int n, matricula; 

printf("Digite a quantidade de alunos: ");
scanf("%d", &n);

taluno *p = (taluno*) malloc(n * sizeof(taluno));

preencher(n, p);

printf("Digite a matrícula para ver a media: ");
scanf(" %d", &matricula);

retornaMedia(n, p, matricula);

mediaGeral(n, p);

    return 0;
}
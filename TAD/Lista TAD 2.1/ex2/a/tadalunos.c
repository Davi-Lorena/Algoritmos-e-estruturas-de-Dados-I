#include <stdio.h>
#include "tadalunos.h"

void preencher(int n, taluno *p) {

for(int i = 0; i < n; i++) {
printf("Digite o codigo do aluno: ");
scanf(" %d", &p[i].cod);
printf("Digite o nome do aluno: ");
scanf(" %[^\n]", p[i].nome);

for(int j = 0; j < 5; j++) {
    printf("Digite a nota %d: ", j + 1);
    scanf(" %f", &p[i].notas[j]);
}

}

}

void retornaMedia(int n, taluno *p, int matricula) {
float media = 0;

for(int i = 0; i < n; i++) {

if(p[i].cod == matricula) {

for(int j = 0; j < 5; j++) {
    media += p[i].notas[j];
}

}
}

media = media / 5;
printf("Media das notas: %.2f\n", media);
return;

}

void mediaGeral(int n, taluno *p) {
float media = 0;
int cont = 0;

for(int i = 0; i < n; i++) {

for(int j = 0; j < 5; j++) {

media += p[i].notas[j];
cont++;
}

}

media = media / cont;

printf("A media de todos esses alunos e: %.2f", media);

}





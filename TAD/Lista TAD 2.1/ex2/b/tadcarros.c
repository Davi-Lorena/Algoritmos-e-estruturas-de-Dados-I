#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadcarros.h"

typedef struct carros {
char placa [15], marca[51], modelo[51], cor[15];
} tcarro;

tcarro *alocaPreenche(int n) {

tcarro *p = (tcarro*) malloc(n * sizeof(tcarro));

if(!p) {
printf("Erro de alocacao!\n");
exit(1);
}

for(int i = 0; i < n; i++) {

printf("Digite a placa do carro: ");
scanf(" %[^\n]", p[i].placa);
printf("Digite a marca do carro: ");
scanf(" %[^\n]", p[i].marca);
printf("Digite o modelo do carro: ");
scanf(" %[^\n]", p[i].modelo);
printf("Digite a cor do carro: ");
scanf(" %[^\n]", p[i].cor);

}

return p;

}

void alterar(int n, char placa[], tcarro *p) {
for(int i = 0; i < n; i++) {
if(!strcmp(placa, p[i].placa)){
printf("Altere a marca: ");
scanf(" %[^\n]", p[i].marca);
printf("Altere o modelo: ");
scanf(" %[^\n]", p[i].modelo);
printf("Altere a cor: ");
scanf(" %[^\n]", p[i].cor);

}

}

}

void imprimirPelaPlaca (int n, char placa[], tcarro *p) {
for(int i = 0; i < n; i++) {
if(!strcmp(placa, p[i].placa)){

    printf("Marca: %s\nModelo: %s\nCor: %s\n", p[i].marca, p[i].modelo, p[i].cor);

}

}

}


void retornaQuant(int n, tcarro *p, char marca[]) {
int cont = 0;

for(int i = 0; i < n; i++) {

if(!strcmp(p[i].marca, marca)){

cont++;

}

}


printf("A quantidade de veículos da marca %s é: %d\n", marca, cont);

}

void liberar(tcarro *p) {

free(p);
}
#include <stdio.h>
#include <string.h>
#include "tadpilha.h"

int main() {

    int cont = 0, i;
tpilha *p;
char palavra[21];

p = criapilha();
if(!p) {
    printf("Não foi possível alocar a pilha\n");
    return -1 ;
}

printf("Digite uma palavra com ate 20 letras: ");
scanf(" %[^\n]", palavra);
for(i = 0; i < strlen(palavra); i++) {

empilha(p, palavra[i]);

}

i = 0;
while(!pilhavazia(p)) {

if(desempilha(p) == palavra[i]) cont++;
i++;
}

if(cont == strlen(palavra)) {
    printf("A palavra e um palindromo!\n");
} else {
    printf("A palavra nao e um palindromo!\n");
}



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

int main () {

    tlista *l = crialista();

    int n, x; 

    printf("Digite quantos elementos você quer inserir: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
printf("Digite o elemento %d da lista: ", i+1);
scanf("%d", &x);
adicionano(l, x);
    }

    mostralista(l);

printf("Deseja remover algum elemento da lista?\n0 se não, 1 se sim");
scanf("%d", &n);

while(n != 0) {
printf("Digite o valor do nó a ser removido: ");
scanf("%d", &x);
removeno(l, x);
mostralista(l);

printf("Deseja remover algum elemento da lista?\n0 se não, 1 se sim");
scanf("%d", &n);


}

free(l);

    return 0; 
}
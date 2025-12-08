#include <stdio.h>
#include "tadlista.h"

int main() {

    tlista *l = crialista();

    char s;
    float valor;
    int n, cod;
    printf("Digite quantos produtos serao inseridos: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
printf("Digite o codigo, o valor e a periculosidade do produto %d: ", i+1);
scanf("%d %f %c", &cod, &valor, &s);

insereno(l, cod, valor, s);
    }

mostralista(l);

printf("Deseja remover algum elemento da lista?\n0 se não, 1 se sim: ");
scanf("%d", &n);

while(n != 0) {
printf("Digite o codigo do no a ser removido: ");
scanf("%d", &cod);
removeno(l, cod);
mostralista(l);

printf("Deseja remover algum elemento da lista?\n0 se não, 1 se sim");
scanf("%d", &n);

}

printf("Digite um codigo para mostrar suas informacoes: ");
scanf("%d", &cod);
imprimecod(l, cod);

printf("Digite uma periculosidade para calculo: ");
scanf(" %c", &s);

printf("O numero de produtos com essa periculosidade e: %d", retornaquant(l, s));


    return 0;
}

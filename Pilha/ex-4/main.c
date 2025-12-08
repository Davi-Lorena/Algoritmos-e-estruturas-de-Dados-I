#include <stdio.h>
#include "tadpilha.h"

int main() {

    int num;
    tpilha *naturais;
    tpilha *negativos;

    naturais = criapilha();
    negativos = criapilha();

for(int i = 0; i < 10; i++) {

printf("Digite um numero: ");
scanf("%d", &num);

if(num > 0) {
    empilha(naturais, num);
} else if (num < 0) {
    empilha(negativos, num);
} else {
if (pilhavazia(naturais) || pilhavazia(negativos))
{
    printf("Não há o que desempilhar!\n");
} else {
    desempilha(naturais);
    desempilha(negativos);
}

}


}

while(!pilhavazia(naturais)) 
    printf("Naturais: %d\n", desempilha(naturais));

while(!pilhavazia(negativos))
    printf("Negativos: %d\n", desempilha(negativos));





return 0;
}
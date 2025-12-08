#include <stdio.h>
#include "tadpilha.h"

int main() {

int numero, modulo = 0;

printf("Digite um numero para ser convertido em binario: ");
scanf("%d", &numero);

tpilha *p;

p = criapilha();
if(!p) return -1;

while(numero / 2 != 0) {

modulo = numero % 2;
numero = numero / 2;

empilha(p, modulo);


}

modulo = numero % 2;

empilha(p, modulo);

while(!pilhavazia(p)) {

printf("%d", desempilha(p));

}


    return 0;
}
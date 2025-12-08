#include <stdio.h>
#include "tadpessoa.h"

int main() {

    int n;
tpessoa *p;

printf("Digite quantas pessoas serão cadastradas: ");
scanf(" %d", &n);

p = criarPreencher(n);

imprimir(n, p);

liberar(p);


    return 0;
}
#include <stdio.h>
#include "tadabp.h"

int main () {

    tabp *arvore;
    tno *raiz;
    char nomeArq[20] = "entrada.txt";

arvore = criaArvore();

carregaNo(arvore, nomeArq);

raiz = retornaRaiz(arvore);

// percorreOrdem(raiz);
// printf("\n");
// percorreOrdem(raiz);
// printf("\n");
// percorrePosOrdem(raiz);

printf("%d\n", estritamenteBinaria(raiz));

    return 0;
}
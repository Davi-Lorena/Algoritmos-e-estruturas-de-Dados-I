#include <stdio.h>
#include "tadfila.h"

int main() {
    tfila *f = criarfila();

    if (f == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    enfileirar(f, 121, 'A');
    enfileirar(f, 123, 'B');

    printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 121 A

    desenfileirar(f);
    printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 123 B

    enfileirar(f, 245, 'C');
    enfileirar(f, 246, 'B');
    enfileirar(f, 252, 'B');
    printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 123 B
    desenfileirar(f);
        printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 245 C
    desenfileirar(f);
        printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 246 B
    desenfileirar(f);
        printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 252 B
    desenfileirar(f);
    desenfileirar(f);
    desenfileirar(f);
    desenfileirar(f);
    desenfileirar(f);   
    desenfileirar(f);
    

    enfileirar(f, 310, 'D');
    enfileirar(f, 342, 'D');
    printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 310 D
    esvaziar(f);
    liberarfila(f);
    printf("Inicio: %d %c\n", iniciofilaNum(f), iniciofilaTipo(f)); // 
    return 0;
}
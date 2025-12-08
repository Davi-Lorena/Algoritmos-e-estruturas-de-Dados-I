#include <stdio.h>
#include "tadfila.h"

int main() {
tfila *f;

f = criarfila();

enfileirar(f, 5);
enfileirar(f, 15);
enfileirar(f, 20);
enfileirar(f, 25);
enfileirar(f, 30);

desenfileirar(f);

printf("Primeiro elemento: %d\n", primeirofila(f));

enfileirar(f, 35);
enfileirar(f, 40);
enfileirar(f, 45);
enfileirar(f, 60);

desenfileirar(f);
desenfileirar(f);
desenfileirar(f);

printf("Primeiro elemento: %d\n", primeirofila(f));

enfileirar(f, 70);
enfileirar(f, 75);

printf("Primeiro elemento: %d\n", primeirofila(f));


esvaziarfila(f);
liberarfila(f);

// Espera-se um lixo de memória: 
printf("Primeiro elemento: %d\n", primeirofila(f));

return 0;
}
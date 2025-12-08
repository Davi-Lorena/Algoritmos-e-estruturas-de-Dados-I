#include <stdio.h>
#include "tadfila.h"

int main() {

    tfila *f = criarfila();

    enfileirar(f, 8);
    enfileirar(f, 9);
    enfileirar(f, 11);

    printf("Inicio nesse momento: %d\n", iniciofila(f)); //8

    desenfileirar(f);
    printf("Inicio nesse momento: %d\n", iniciofila(f)); //9
desenfileirar(f);
printf("Inicio nesse momento: %d\n", iniciofila(f)); //11

  enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);
      enfileirar(f, 40);
enfileirar(f, 50);

printf("Inicio nesse momento: %d\n", iniciofila(f)); //11

desenfileirar(f);

printf("Inicio nesse momento: %d\n", iniciofila(f)); //10

  enfileirar(f, 5);
    enfileirar(f, 15);
    enfileirar(f, 25);

printf("Inicio nesse momento: %d\n", iniciofila(f)); //10

    desenfileirar(f);
    printf("Inicio nesse momento: %d\n", iniciofila(f)); // 20
    desenfileirar(f);
    printf("Inicio nesse momento: %d\n", iniciofila(f)); //30
    desenfileirar(f);
    printf("Inicio nesse momento: %d\n", iniciofila(f)); //40
    desenfileirar(f);
printf("Inicio nesse momento: %d\n", iniciofila(f)); // 50

printf("EXERCICIO 3:: \n\n\n");

  enfileirar(f, 1);
    enfileirar(f, 2);
    enfileirar(f, 3);
      enfileirar(f, 4);
enfileirar(f, 5);
 enfileirar(f, 6);
enfileirar(f, 7);
printf("Inicio nesse momento: %d\n", iniciofila(f)); //50 

 desenfileirar(f);
 printf("Inicio nesse momento: %d\n", iniciofila(f)); // 5
  desenfileirar(f);
  printf("Inicio nesse momento: %d\n", iniciofila(f)); // 15

enfileirar(f, 45);
 enfileirar(f, 60);
enfileirar(f, 75);
printf("Inicio nesse momento: %d\n", iniciofila(f)); // 15 

esvaziar(f);
printf("Inicio nesse momento: %d\n", iniciofila(f)); // -1

liberarfila(f);

    return 0;
}
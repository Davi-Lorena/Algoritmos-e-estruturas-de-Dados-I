  #include "tadponto.h"
#include <stdio.h>

  int main() {

    int x, y;
    printf("Digite o valor de x: "); 
    scanf(" %d", &x);
    printf("Digite o valor de y: ");
    scanf(" %d", &y);

    tponto *p = criaPonto(x, y);
    imprimePonto(p);
    alteraPonto(p, 10, 20);
    imprimePonto(p);
    liberaPonto(p);

return 0;
  }
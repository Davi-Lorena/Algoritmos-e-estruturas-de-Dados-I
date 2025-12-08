#include <stdio.h>
#include "tadpilha.h"
#include <string.h>

int main() {

char cad[21], count = 0, i, comp;
tpilha *p;

p = criapilha();

printf("Digite a cadeia: ");
scanf(" %s", cad);

i = 0;
while(cad[i] != 'C') {
empilha(p, cad[i]);
i++;
}

i++;
comp = strlen(cad) - i;
while(!pilhavazia(p)) {
if(desempilha(p) == cad[i]) count++;
i++;
}

if(count == comp) printf("Eh na forma xCy\n");
else printf("Nao eh na forma xCy\n");


return 0;
}
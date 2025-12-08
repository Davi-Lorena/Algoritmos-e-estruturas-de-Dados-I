#include <stdio.h>
#include "tadcarros.h"

int main() {
int n; 
char placa[15], marca[51];

printf("Digite a quantidade de carros: ");
scanf(" %d", &n);

tcarro *p = alocaPreenche(n);

printf("Digite a placa para se alterar as informações: ");
scanf(" %[^\n]", placa);

alterar(n, placa, p);

imprimirPelaPlaca(n, placa, p);

printf("Digite a marca para retornar a quantidade: ");
scanf(" %[^\n]", marca);

retornaQuant(n, p, marca);

liberar(p);

return 0;
}
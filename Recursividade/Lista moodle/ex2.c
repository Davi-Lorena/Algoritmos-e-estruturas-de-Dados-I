#include <stdio.h> 

int maiorRecDiv(int vet[0], int inicio, int fim) {
int meio;
int m1, m2;

printf("%d\t%d\n", inicio, fim);

if(inicio == fim) return vet[inicio];

meio = (inicio + fim) / 2;

m1 = maiorRecDiv(vet, inicio, meio);
m2 = maiorRecDiv(vet, meio + 1, fim);

if(m1 > m2) return m1;
else return m2;

}



int main() {

int vet[10] = {0, 1, 2, 13, 4, 15, 6, 67, 98, 9};

printf("O maior elemento do vetor e: %d", maiorRecDiv(vet, 0, 9));

    return 0;
}
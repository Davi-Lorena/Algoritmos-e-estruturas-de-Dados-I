#include <stdio.h>

int maiorRecursivo(int vet[], int n) {
int aux;
if(n == 0) return vet[n];
aux = maiorRecursivo(vet, n - 1);
if(aux > vet[n]) {
    return aux;
} else {
    return vet[n];
}

}

int main() {

int vet[10] = {0, 1, 2, 13, 4, 15, 6, 67, 98, 9};

printf("O maior elemento do vetor e: %d", maiorRecursivo(vet, 9));

    return 0;
}
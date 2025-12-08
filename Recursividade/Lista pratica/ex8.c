#include <stdio.h>

int fatDuplo(int n) {
if(n == 1) return 1;
else return n * fatDuplo(n-2);
}


int main() { 

int n;
int fat = 1;

printf("Digite um numero impar para o fatorial: ");
scanf("%d", &n);

if(n % 2 == 0) {
    printf("O numero deve ser impar!");
    return 0;
}

for(int i = 1; i <= n; i+= 2) {

    fat *= i;

}

printf("O fatorial duplo de %d e: %d (recursivo) e %d (iterativo)", n, fatDuplo(n), fat);

    return 0;
}
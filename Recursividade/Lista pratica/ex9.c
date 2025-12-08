#include <stdio.h> 

int pell(int n) {
if(n == 0 || n == 1) return n;
else return 2 * pell(n-1) + pell( n -2 );
}

int main() {

    int n;

printf("Digite um numero: ");
scanf(" %d", &n);

printf("O numero de pell correspondente a este e: %d", pell(n));

    return 0;
}
#include <stdio.h>

int retorna_soma(int n) {
// int soma = n;
if(n == 1) return 1;
else { 
    return n + retorna_soma(n - 1); 
}
}


int main() {

    int n, sum;

    printf("Digite n: ");
    scanf("%d", &n); 

sum = retorna_soma(n);

printf("A soma de 1 ate %d e: %d\n", n, sum);


    return 0;
}
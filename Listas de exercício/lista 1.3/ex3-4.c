/*
3 - Desenvolva uma função com os parâmetros N (número de elementos do vetor) e V
(vetor de valores numéricos) e que retorna a soma dos valores do vetor. Use a função
para calcular a soma de um vetor de até 10 números inteiros digitados no teclado.

4 - Desenvolva uma função que receba um vetor de inteiro e substitua todo valor = 0 do
vetor por algum outro valor que deverá ser também informado à função. Utilize a
função no programa principal. O vetor deve ser alocado dinamicamente na “main”. O
tamanho do vetor e os valores devem ser determinados pelo usuário.


*/

#include <stdio.h>
#include <stdlib.h> 

int somaVet(int n, int *v) {
int soma = 0;

for(int i = 0; i < n; i++) {
    soma += v[i];
}

return soma; 

}

void substituiZero(int n, int *v, int novoValor) {
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) {
            v[i] = novoValor;
        }
    }
}

int main() {
 
int n, soma, novoValor; 
int *v;
printf("Digite o tamanho do vetor: ");
scanf("%d", &n);


v = (int *) malloc(n * sizeof(int));

if(!v) {
    printf("Erro de alocacao\n");
    return -1;
}


for(int i = 0; i < n; i++) {
    printf("Digite o valor do elemento %d: ", i + 1); 
    scanf("%d", &v[i]);
}

soma = somaVet(n, v);
printf("A soma dos elementos desse vetor: %d", soma);

printf("\nDigite o valor para substituir os zeros: ");
scanf("%d", &novoValor);
substituiZero(n, v, novoValor);

for(int i = 0; i < n; i++) {
    printf("Elemento %d: %d\n", i + 1, v[i]);
}

free(v);
    return 0;
}
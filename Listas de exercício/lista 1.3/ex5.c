/*
5. Elabore uma função que receba um vetor de inteiro e retorne o valor do maior e do
menor elemento do vetor. Utilize a função no programa principal. O vetor deve ser
alocado dinamicamente na “main”. O tamanho do vetor e os valores devem ser
determinados pelo usuário.
*/

#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *v, int n, int *maior, int *menor) {
*maior = v[0];
*menor = v[0];

for(int i = 1; i < n; i++) {
if(v[i] > *maior) {
    *maior = v[i];
}
if(v[i] < *menor) {
    *menor = v[i];
}
}


}


int main() {

    int n, maior, menor;
    int *v;

    printf("Digite o tamanho do vetor: "); 
    scanf(" %d", &n); 

    v = (int *)malloc(n * sizeof(int));

    if(!v) {
        printf("Erro de alocacao\n");
        return -1;
    }

    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf(" %d", &v[i]);
    }

    maiorMenor(v, n, &maior, &menor);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    free(v);
    return 0;
}
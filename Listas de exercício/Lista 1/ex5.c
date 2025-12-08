/*Elabore uma função para liberar um vetor de n posições. */


#include <stdio.h>
#include <stdlib.h>

void liberar_vetor(int* vetor) {
    free(vetor);
}

int main() {
    int n; 
int *vet;

    printf("Digite o tamanho de vetor: ");
    scanf(" %d", &n);

vet =(int *) malloc(n * sizeof(int));

if(!vet) {
    printf("Erro de alocação");
    return 1;
}

for(int i = 0; i < n; i++) {
printf("Digite o elemento %d do vetor: ", i + 1); 
scanf(" %d", &vet[i]);

}

printf("Vetor preenchido, agora ele será limpo!");

liberar_vetor(vet);

return 0;


}

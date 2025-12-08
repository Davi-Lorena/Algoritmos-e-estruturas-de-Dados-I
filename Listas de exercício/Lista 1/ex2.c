#include <stdio.h>
#include <stdlib.h>

void troca(int n ){
    float *vet;
    vet=(float *)malloc(sizeof(float)*n);

    if(!vet){
        printf("SEM ESPAÇO");
        return;
    }

    for(int i=0;i<n;i++){
        printf("Digite o elemento %d do vetor:", i+1);
        scanf("%f", &vet[i]);
    }

    for(int i = (n-1);i >=0; i--){
        printf("Elemento %d invertido: %0.2f\n ", i,vet[i]);
    }
    //para trocar os elementos usamos o for, nao esquecer do i-- e igualar o i a zero

    free(vet);

    return;
}

int main(){
    int n;
    printf("Digite a quantidade de numeros para serem invertidos:");
    scanf("%d",&n);

    troca(n);

    return 0;

}
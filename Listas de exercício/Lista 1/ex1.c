#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet;
    int n;

    printf("Digite a quantidade de casas que vai ter seu numero:");
    scanf("%d",&n);

    vet=(int *)malloc(sizeof(int)*n);

     if(!vet){
        printf("NAO TEM ESPAÇO");
        return -1;
    }

    for(int i=0;i<n;i++){
    printf("Digite o numero:");
    scanf("%d",&vet[i]);
    }

    for(int i=0;i<n;i++){
        printf("Espaco %d e igual %d", i+1,vet[i]);
    }

    free(vet);

    return 0;





}
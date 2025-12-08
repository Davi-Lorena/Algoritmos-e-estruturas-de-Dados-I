/*Crie uma estrutura para armazenar dados de um produto (código – inteiro/preço-float).
Elabore um tipo definido baseado na estrutura criada. Elabore funções para:
a. Alocar um vetor de tamanho n dinamicamente para armazenar uma lista de
produtos. O tamanho da lista deverá ser passado como parâmetro.
b. Preencher o vetor alocado na função a com dados fornecidos pelo usuário.
c. Verificar se o produto de código X (X deve ser digitado pelo usuário) foi
armazenado. Caso seja encontrado, imprima o preço do produto. Suponha que o
código dos produtos não repete. Caso contrário, retorne -1;
d. Ajustar preço de todos os produtos. O valor do ajuste em porcentagem deverá
ser fornecido pelo usuário.
e. Imprimir os dados dos produtos;*/
#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    int cod; 
    float preco;
} tproduto;

tproduto *aloca(int n) {

tproduto *vet; 

vet = (tproduto *) malloc(n * sizeof(tproduto));

for(int i = 0; i < n; i++) {
printf("Digite o codigo e o preco do produto: ");
scanf(" %d %f", &vet[i].cod, &vet[i].preco);

}

return vet;

}


int main() {

    tproduto *vet;
    int n, x;
    float ajuste;

printf("Digite o tamanho do vetor: ");
scanf("%d", &n);

printf("Digite o codigo para comparacao: ");
scanf("%d", &x);
    vet = aloca(n);


    for(int i = 0; i < n; i++) {
        if(vet[i].cod == x) {
            printf("Produto encontrado: %.2f\n", vet[i].preco);
            x = -1; 
        }
    }

    if(x != -1) {
        printf("Produto não encontrado.\n");
        return -1;
    }

printf("Digite o percentual de ajuste: ");
scanf("%f", &ajuste);

ajuste = ajuste / 100;

for(int i = 0; i < n; i++) {
    vet[i].preco += vet[i].preco * ajuste;

    printf("Codigo: %d Preco: %.2f\n", vet[i].cod, vet[i].preco);
}

free(vet);

return 0;
}
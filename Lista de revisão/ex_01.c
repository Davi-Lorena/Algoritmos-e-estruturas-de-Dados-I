#include <stdio.h>
#include <string.h>

typedef struct produto {
    char nome_produto[51];
    int codigo;
    float preco;
} Produto;

int carregarProdutos(Produto vetor[], char nomeArquivo[]) {
    
    FILE *arq = fopen(nomeArquivo, "r");
    int i = 0;

    while(!feof(arq)) {
        fscanf(arq, "%s %d %f", vetor[i].nome_produto, &vetor[i].codigo, &vetor[i].preco);
        i++;
    }
    return i;
}

int buscarPorNome(Produto vetor[], int tam, char nomeProduto[]) {
    for(int i = 0; i < tam; i++) {
        if(strcmp(vetor[i].nome_produto, nomeProduto) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    
    Produto vetor[100];
    char nomeArquivo[] = {"produtos.txt"};

    int tam = carregarProdutos(vetor, nomeArquivo);
    char nomeProduto[51];

    scanf("%s", nomeProduto);

    int pos = buscarPorNome(vetor, tam, nomeProduto);

    if(pos != -1) {
        printf("Produto Encontrado:\n"); 
        printf("Nome: %s\n", vetor[pos].nome_produto); 
        printf("Codigo: %d\n", vetor[pos].codigo);
        printf("Valor: %0.2f\n", vetor[pos].preco);
    }
    else printf("Produto não encontrado\n");
    return 0;
}
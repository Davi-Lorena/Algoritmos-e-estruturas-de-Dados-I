/*

Crie funções para:
a. Alocar uma matriz para guardar n nomes de tamanho máximo m.
b. Armazenar n nomes de tamanho máximo m em uma matriz. Os nomes deverão
ser fornecidos pelo usuário.
c. Retornar a posição (linha) de um determinado nome na matriz. O nome deve ser
passado como parâmetro. Caso o nome não esteja na matriz, retorne -1.
Use as funções no programa principal.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **alocaMatriz(int n, int m) {
    char **mat = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        mat[i] = (char *) malloc(m * sizeof(char));
    }
    return mat;
}

void preencherNomes(char **mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("Digite o nome %d: ", i + 1);
        scanf(" %[^\n]", mat[i]);

if(strlen(mat[i]) > m) {
        printf("Nome muito longo. Tente novamente.\n");
        i--;
    }

    }
}

int buscarNome (char **mat, int n, char nome[]) {
for(int i = 0; i < n; i++) {

    if(strcmp(mat[i], nome) == 0) {
        return i;
    }

}

return -1;

}

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, m, retorno; 
char **mat;
char *nome;

printf("Digite a quantidade de nomes a serem armazenados: ");
scanf(" %d", &n);
printf("Digite o tamanho maximo de cada nome: ");
scanf(" %d", &m);

nome = (char *) malloc(m * sizeof(char));

printf("Agora, digite um nome para comparação: "); 
scanf(" %[^\n]", nome);

mat = alocaMatriz(n, m);

preencherNomes(mat, n, m);

retorno = buscarNome(mat, n, nome);

if (retorno != -1) {
    printf("Nome encontrado na linha: %d\n", retorno + 1);
} else {
    printf("Nome não encontrado.\n");
}

free(nome);
for (int i = 0; i < n; i++) {
    free(mat[i]);
}
free(mat);

    return 0;
}
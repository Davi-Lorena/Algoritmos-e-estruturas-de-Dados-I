/*
2. Crie uma estrutura para armazenar informações sobre aluno contendo os seguintes
dados:
a. Nome (cadeia de caractere de tamanho máximo = 100)
b. Matrícula (inteiro)
Elabore um tipo baseado na estrutura criada. Crie um programa para facilitar o
gerenciamento das informações dos alunos de uma turma. A quantidade de alunos deve
ser fornecida pelo usuário. Crie funções para:
c. Preencher a lista de alunos;
d. Imprimir os dados de todos os alunos da lista;
e. Dado um número de matrícula, verificar se o aluno existe na lista. Se existir,
imprima o nome. Caso contrário, imprima uma mensagem de notificação;
f. Dado um nome, imprimir os dados de todos os alunos com o mesmo nome.
Considere que há alunos com nomes repetidos.
g. Dado um nome, retornar a quantidade de alunos com o nome fornecido.
Use alocação dinâmica para alocar o vetor de alunos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[100];
    int matricula;
} taluno;


void preencherMat (taluno *p, int n) {
for(int i = 0; i < n; i ++) {
    printf("Digite o nome do aluno: ");
    scanf("%s", p[i].nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &p[i].matricula);
}

}

void imprimirAlunos(taluno *p, int n) {
    for(int i = 0; i < n; i++) {
        printf("Nome: %s, Matricula: %d\n", p[i].nome, p[i].matricula);
    }
}

void buscarPorMatricula(taluno *p, int n, int matricula) {
    for(int i = 0; i < n; i++) {
        if(p[i].matricula == matricula) {
            printf("Aluno encontrado: %s\n", p[i].nome);
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void buscarPorNome (taluno *p, int n, char *nome, int *cont) {
  for(int i = 0; i< n ; i++) {
    if(!strcmp(p[i].nome, nome)) {
        printf("Nome: %s, Matricula: %d\n", p[i].nome, p[i].matricula);
        (*cont)++;
    }
  }
}

int main() {
 
    taluno *alunos;
int quantidadeAlunos, matCompara, cont = 0; 
char nomeCompara[100];

printf("Digite a quantidade de alunos: ");
scanf("%d", &quantidadeAlunos);

alunos = (taluno *) malloc(quantidadeAlunos * sizeof(taluno));

if (alunos == NULL) {
    printf("Erro ao alocar memoria.\n");
    return 1;
}

preencherMat(alunos, quantidadeAlunos);
imprimirAlunos(alunos, quantidadeAlunos);

printf("Digite a matrícula para buscar: ");
scanf(" %d", &matCompara);

buscarPorMatricula(alunos, quantidadeAlunos, matCompara);

printf("Digite o nome para comparacao: ");
scanf(" %[^\n]", nomeCompara);

buscarPorNome(alunos, quantidadeAlunos, nomeCompara, &cont);

printf("\nQuantidade de alunos com o nome %s: %d\n", nomeCompara, cont);
free(alunos);
    return 0;
}
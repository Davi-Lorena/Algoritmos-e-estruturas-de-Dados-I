/*Fazer um algoritmo que:
a. Leia o valor de n e aloque dinamicamente uma variável composta A de tamanho
n. A deve armazenar números inteiros.
b. Leia os n valores da variável A. Suponha que os valores foram digitados em
ordem crescente (não é necessário fazer esta validação).
c. Determine e imprima, para cada número que se repete no conjunto, a quantidade
de vezes em que ele se repete.
d. Elimine os elementos repetidos, formando um novo conjunto.
e. Imprima o conjunto obtido no item anterior.*/
#include <bits/stdc++.h>

using namespace std;

int main() {
int n;
int *A; 
set<int> sett;
set<int>::iterator setit;
multiset<int> mset;
multiset<int>::iterator multsetit;

printf("Digite o tamanho do vetor: ");
scanf(" %d", &n);

A = (int *) malloc(n * sizeof(int));

if(!A) {
    printf("Erro de alocacao de memoria!\n");
    return 1;
}

for(int i = 0; i < n; i++) {
    printf("Digite o elemento %d do vetor: ", i + 1); 
    scanf(" %d", &A[i]);

mset.insert(A[i]);
sett.insert(A[i]);
}


for(setit = sett.begin(); setit != sett.end(); setit++) {
printf("Elemento: %d Aparicoes: %d\n", *setit, mset.count(*setit));
}


free(A);
    return 0;
}
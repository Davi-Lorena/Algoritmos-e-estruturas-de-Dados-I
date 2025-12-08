#include <stdio.h> 
#include "tadpilha.h"

int main() {

tpilha *p1, *p2, *p3;
int n, x;

p1 = criapilha();
p2 = criapilha();
p3 = criapilha();

printf("Digite quantos elementos haverao nas pilhas: ");
scanf("%d", &n);

for(int i = 0; i < n; i++) {
    printf("Digite o elemento %d da pilha 1: ", i + 1);
    scanf("%d", &x);
    empilha(p1, x);

    printf("Digite o elemento %d da pilha 2: ", i + 1);
    scanf("%d", &x);
    empilha(p2, x);
}


while(!pilhavazia(p1) || !pilhavazia(p2)) {

if(pilhavazia(p1) && !pilhavazia(p2)) {
    empilha(p3, desempilha(p2));
} else if(!pilhavazia(p1) && pilhavazia(p2)) {
    empilha(p3, desempilha(p1));
} else {

if(topo(p1) < topo(p2)) {
    empilha(p3, desempilha(p1));
} else if (topo(p2) < topo(p1)) {
    empilha(p3, desempilha(p2));
} else if(topo(p1) == topo(p2)) {
empilha(p3, desempilha(p2));
desempilha(p1);

}


}

}

printf("Elemento da pilha resultante: \n");
while(!pilhavazia(p3)) {
    printf("%d\n", desempilha(p3));
}


return 0;
}
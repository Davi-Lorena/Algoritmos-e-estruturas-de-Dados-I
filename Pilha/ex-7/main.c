#include <stdio.h>
#include <string.h>
#include "tadpilha.h"

int avaliaExpressao(tpilha *p, char cad[]) {
int i;

for(i = 0; i < strlen(cad); i++) {

if(cad[i] == '(' || cad[i] == '[' || cad[i] == '{'){
empilha(p, cad[i]);
} else if(cad[i] == ')' || cad[i] == ']' || cad[i] == '}') {

if(pilhavazia(p)) {
    printf("Não está completo\n");
    return 0;
} else {

if(cad[i] == ')' && topo(p) == '(') {
desempilha(p);
} else if (cad[i] == ']' && topo(p) == '[') {
    desempilha(p);
} else if (cad[i] == '}' && topo(p) == '{') {
    desempilha(p);
} else {
    printf("Não está completo\n");
    return 0;
}


}


}

}

if(pilhavazia(p)) {
    printf("A cadeia está completa!\n");
    return 1;
} else {
    printf("Cadeia incompleta\n");
    return 0;
}


}


int main() {

char cad[21];
tpilha *p;
p = criapilha();

printf("Digite a cadeia de caracteres: ");
scanf(" %s", cad);

avaliaExpressao(p, cad);

    return 0;
}
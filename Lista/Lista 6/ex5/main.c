#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

int main() {

    tlista *l = crialista();

    int n;
    tcliente cliente;

    printf("Digite quantos clientes tera sua lista: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

       
printf("Digite o codigo: ");
scanf("%d", &cliente.cod); 

printf("Digite o nome: ");

scanf(" %[^\n]", cliente.nome);

printf("Digite o endereco: ");
scanf(" %[^\n]", cliente.endereco);

printf("Digite a data de ultima compra: ");
scanf(" %[^\n]", cliente.duc);

printf("Digite a data de nascimento: ");
scanf(" %[^\n]", cliente.dnsc);

insereno(l, cliente);

    }

    mostralista(l);


    return 0;
}
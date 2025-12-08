/*Elabore uma função que receba uma cadeia de caracter de tamanho N e substitua toda
ocorrência de uma vogal por *. Utilize a função no programa principal para
“criptografar” uma cadeia de caracter fornecida pelo usuário. O tamanho da cadeia
também deve ser informado em tempo de execução. Use alocação dinâmica.
*/

#include <stdio.h>
#include<stdlib.h>

void muda(char vet[],int n, char vogal){

    for(int i=0;i<n;i++){
        if(vet[i]==vogal){
            vet[i]='*';
        }
    }
    printf(" %s\n",vet);
}

int main(){
    char *cadeia;
    char vogal;
    int n;

    printf("Digite a quantidade de letras que vai ter a palavra:");
    scanf("%d",&n);

    cadeia=(char*)malloc(sizeof(char)*n);

    if(!cadeia){
        printf("SEM ESPACO");
        return -1;
    }
    printf("Digite a cadeia de caracteres:");
    scanf(" %[^\n]", cadeia);

    printf("Digite a vogal a ser criptografada:");
    scanf(" %c", &vogal);

    if(vogal!='a' || vogal!='e' || vogal!='i' || vogal!='o' || vogal!='u' || vogal!='A' || vogal!='E' || vogal!='I' || vogal!='O' || vogal!='U'){
        printf("Digite apenas vogais\n");
        return -1;
    }

    muda(cadeia,n,vogal);

    free(cadeia);

    return 0;
}
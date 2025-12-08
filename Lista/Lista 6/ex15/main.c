/*
) O problema de Josephus é um clássico na computação e já foi reescrito de várias
maneiras. Uma das versões é descrita a seguir: Um grupo de soldados está cercado e
não há esperança de vitória, porém existe somente um cavalo disponível para escapar e
buscar por reforços. Para determinar qual soldado deve escapar para encontrar ajuda,
eles formam um círculo e sorteiam um número. Começando por um soldado sorteado
aleatoriamente, uma contagem é realizada até o número sorteado. Quando a contagem
terminar, o soldado em que a contagem parou é removido do círculo, e a contagem
recomeça no soldado seguinte ao que foi eliminado. A cada rodada, portanto, o círculo
diminui em um, até que somente um soldado reste e seja escolhido para a tarefa.
Analise o problema e escolha uma estrutura de dados apropriada para a solução.
Observe que na estratégia de eliminação a lista de soldados pode ser percorrida várias
vezes de forma circular. Para simplificar o problema considere que o soldado sorteado
para iniciar a contagem foi o primeiro.
*/

#include <stdio.h> 
#include "tadlista.h"

int main() {

    int qntSoldados, i, n; 
    tlista *l = crialista();
    int soldado;

if(!l) {printf("Erro de alocação de lista\n"); return -1;}

    printf("Digite a quantidade de soldados: ");
    scanf(" %d", &qntSoldados); 

for(i = 0; i <= qntSoldados; i++) {
    insereno(l, i);
}

printf("Digite o número da contagem: ");
scanf("%d", &n); 

soldado = pulaSoldados(l, n);

printf("O soldado restante é o de número: %d!\n", soldado);

}
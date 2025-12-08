#include <stdio.h>
#include <string.h>

typedef struct animal{
	char nome[31];
	char categoria[16];
	float quantidade_kg_por_dia;
} Animal;

int carregarAnimais(Animal vetor[], char nomeArquivo[]) {
	FILE *arq = fopen(nomeArquivo, "r");
	if (arq == NULL) return 0;

	int animais = 0;
	while (!feof(arq)) {
        fscanf(arq, "%s %s %f", vetor[animais].nome, vetor[animais].categoria, &vetor[animais].quantidade_kg_por_dia);
		animais++;
	}
	fclose(arq);    
	return animais;
}

float calcularMediaPorCategoria(Animal vetor[], int tam, char categoria[]) {
	float alimento_por_dia = 0;
	int cont = 0;

	for (int i = 0; i < tam; i++) {
		if (strcmp(categoria, vetor[i].categoria) == 0) {
			alimento_por_dia += vetor[i].quantidade_kg_por_dia;
			cont++;
		}
	}
	if (cont > 0) return alimento_por_dia / cont;
	else return -1.0;
}

float calcularCustoAlimentacao(Animal vetor[], int tam, float valorKg) {
	float totalGasto = 0;

	for (int i = 0; i < tam; i++) {
		totalGasto += vetor[i].quantidade_kg_por_dia;
	}
	totalGasto = totalGasto * 30 * valorKg;

	return totalGasto;
}

int main() {
	Animal vetor[100];
	char nomeArquivo[20];

	scanf("%s", nomeArquivo);

	int tam = carregarAnimais(vetor, nomeArquivo);
	char categoria[16];

	scanf("%s", categoria);

	float valorMedio = calcularMediaPorCategoria(vetor, tam, categoria);
	printf("Consumo medio: %0.2f\n", valorMedio);

	float valorKg;
	scanf("%f", &valorKg);

	float custo = calcularCustoAlimentacao(vetor, tam, valorKg);
	printf("Gasto por mes: %0.2f", custo);
}

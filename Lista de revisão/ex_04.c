#include <stdio.h>
#include <string.h>

typedef struct Artista {
	char nome_do_artista[31];
	char genero[11];
	float total_deproducoes;
	float ouvintes_unicos;
} artista;

int carregaDados(artista vet[], char nomeArquivo[]) {

	FILE *arq = fopen(nomeArquivo, "r");

	int artistas = 0;
	while(!feof(arq)) {
		fscanf(arq, "%[^,],%[^,],%f,%f", vet[artistas].nome_do_artista, vet[artistas].genero, &vet[artistas].total_deproducoes, &vet[artistas].ouvintes_unicos);
		artistas++;
	}
	return artistas;
}

void imprimeArtistas(artista vet[], int tam) {

	for(int i = 0; i < tam; i++) {
		printf("%s\t%s\t%0.2f\t%0.2f", vet[i].nome_do_artista, vet[i].genero, vet[i].total_deproducoes, vet[i].ouvintes_unicos);
	}
}

artista * artistaMaisOuvido(artista vet[], int tam) {

	int maisOuvido = 0;
	for (int i = 1; i < tam; i++) {
		if (vet[i].total_deproducoes > vet[maisOuvido].total_deproducoes) {
    	maisOuvido = i;
		}
	}
	return &vet[maisOuvido];
}

void generoMaisOuvido(artista vet[], int tam) {
    char genero1[11];
    float ouvintes1 = 0;
    int i, j;

    strcpy(genero1, vet[0].genero);
    ouvintes1 = 0;

    for (i = 0; i < tam; i++) {
        char generoAtual[11];
        float somaAtual = 0;

        strcpy(generoAtual, vet[i].genero);
        for (j = 0; j < tam; j++) {
            if (strcmp(generoAtual, vet[j].genero) == 0) {
                somaAtual += vet[j].ouvintes_unicos;
            }
        }
        if (somaAtual > ouvintes1) {
            ouvintes1 = somaAtual;
            strcpy(genero1, generoAtual);
        }
    }

    printf("%s\t%0.2f", genero1, ouvintes1);
}


int main() {

	artista vet[100];
	char nomeArquivo[21];

	scanf("%s", nomeArquivo);

	int tam = carregaDados(vet, nomeArquivo);

	imprimeArtistas(vet, tam);

	artista *maisOuvido = artistaMaisOuvido(vet, tam);
	printf("\n%s\t%s\t%0.2f\t%0.2f\n", maisOuvido->nome_do_artista, maisOuvido->genero, maisOuvido->total_deproducoes, maisOuvido->ouvintes_unicos);

	generoMaisOuvido(vet, tam);

}
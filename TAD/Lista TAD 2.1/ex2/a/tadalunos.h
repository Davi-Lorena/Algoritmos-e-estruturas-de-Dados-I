typedef struct aluno {
    int cod;
    char nome[101];
    float notas[5];
} taluno;

// Struct teve que ficar aqui para que a alocação pudesse ser realizada pela MAIN

void preencher(int n, taluno *p);
void retornaMedia(int n, taluno *p, int matricula);
void mediaGeral(int n, taluno *p);
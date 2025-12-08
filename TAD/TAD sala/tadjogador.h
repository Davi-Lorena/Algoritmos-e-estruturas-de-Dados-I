typedef struct jogador tjogador;

tjogador *cria_jogador(int n);

void preenchelista(tjogador *j, int n);

void altera_pontuacao(tjogador *j, char *nome, float pontnova, int n);

void get_jogador (tjogador *j, char *nome, int n);

void imprime_lista(tjogador *j, int n);

void libera_jogador(tjogador *j);
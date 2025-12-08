typedef struct no tno;

typedef struct fila tfila;

tfila *criarfila();

int filavazia(tfila *f);

int enfileirar(tfila *f, int dado);

int desenfileirar(tfila *f);

int iniciofila(tfila *f);

void esvaziar(tfila *f);
void liberarfila(tfila *f);
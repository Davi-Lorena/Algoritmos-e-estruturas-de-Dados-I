typedef struct fila tfila;

typedef struct no tno;

tfila *criarfila();

int filavazia(tfila *f);

int enfileirar(tfila *f, int dado);

int desenfileirar(tfila *f);

int primeirofila(tfila *f);

void esvaziarfila(tfila *f);

void liberarfila(tfila *f);

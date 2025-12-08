typedef struct no tno;
typedef struct processo tprocesso;
typedef struct fila tfila;

tfila *criarfila();

int filavazia(tfila *f);

int enfileirar(tfila *f, int x, char y);

void desenfileirar(tfila *f);

int iniciofilaNum(tfila *f);
char iniciofilaTipo(tfila *f);

void esvaziar(tfila *f);
void liberarfila(tfila *f);
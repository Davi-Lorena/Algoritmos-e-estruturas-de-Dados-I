typedef struct cliente {
int cod;
char nome[100], endereco[200], duc[11], dnsc[11];
} tcliente;

typedef struct lista tlista;

typedef struct no tno;

tlista *crialista();

int insereno(tlista *l, tcliente cliente);

int removeno(tlista *l, tcliente cliente);

void mostralista(tlista *l);

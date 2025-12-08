typedef struct lista tlista;

typedef struct produto tproduto;

typedef struct no tno;

tlista *crialista();

int insereno(tlista *l, int cod, float valor, char pecu);

int removeno(tlista *l, int cod);

void mostralista(tlista *l);

int retornaquant(tlista *l, char s);

void imprimecod(tlista *l, int cod);
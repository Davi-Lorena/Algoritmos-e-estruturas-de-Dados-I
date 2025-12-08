typedef struct no tno;

typedef struct pilha tpilha;

tpilha *criapilha();

int pilhavazia(tpilha *p);

int empilha(tpilha *p, char dado);

char topo(tpilha *p);

char desempilha(tpilha *p);
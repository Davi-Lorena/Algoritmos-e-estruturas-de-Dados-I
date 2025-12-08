typedef struct pilha tpilha;

typedef struct no tno;

tpilha *criapilha();

int pilhavazia(tpilha *p);

int empilha(tpilha *p, char dado);

char topo(tpilha *p);

char desempilha(tpilha *p);
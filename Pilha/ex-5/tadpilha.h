typedef struct no tno;

typedef struct pilha tpilha;

tpilha *criapilha();

int pilhavazia(tpilha *p); // Retorna 1 se estiver vazia  

int empilha(tpilha *p, int dado); // Retorna 1 se empilhar, zero se não 

int topo(tpilha *p); // retorna -1 se pilha vazia, dado caso contrário

int desempilha(tpilha *p);  // retorna -1 se pilha vazia, dado caso contrário

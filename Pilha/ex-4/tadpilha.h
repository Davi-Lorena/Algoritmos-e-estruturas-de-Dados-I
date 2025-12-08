typedef struct no tno; 

typedef struct pilha tpilha;

tpilha *criapilha(); // Cria e retorna o endereço da pilha 

int pilhavazia(tpilha *p); // Retorna 1 se estiver vazia, 0 caso contrário 

int empilha(tpilha *p, int dado); // Retorna 1 se conseguir empilhar, 0 caso contrário  

int topo(tpilha *p); // Retorna -1 se a pilha estiver vazia, caso contrário retorna o dado 

int desempilha(tpilha *p); // Retorna -1 se a pilha estiver vazia, retorna o dado caso contrário
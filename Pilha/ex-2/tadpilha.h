typedef struct no tno;

typedef struct pilha tpilha; 

tpilha *criapilha(); //aloca memoria para pilha e inicializa o topo da pilha para null

int pilhavazia(tpilha *p); //retorna 1 se a pilha estiver vazia, 0 do contrário

int empilha (tpilha *p, int dado); //retorna 1, se foi possível empilhar, 0 caso contrário

int topo(tpilha *p); //retorna o valor do topo se a pilha nao estiver vazia, -1, caso contrário

int desempilha (tpilha *p); //desempilha o topo se a pilha nao estiver vazia, -1, caso contrário
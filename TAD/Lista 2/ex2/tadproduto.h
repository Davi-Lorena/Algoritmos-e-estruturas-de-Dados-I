typedef struct produto tproduto;

tproduto *criar(int n);

void preencher(int n, tproduto *p);

void imprimirMaior(int n, tproduto *p);

void aumentarPorcentagem(int n, int porc, tproduto *p);

void maiorQuantidade(int n, tproduto *p);

void liberar(tproduto *p);
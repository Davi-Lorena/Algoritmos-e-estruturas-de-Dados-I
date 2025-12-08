typedef struct arvore tabp;
typedef struct no tno;

tno *criaNo();
tabp *criaArvore();

void insereNo(tabp *arv, int dado);
void carregaNo(tabp *arv, char *nomeArquivo); 

void buscaPreOrdem(tabp *arv);
void buscaEmOrdem(tabp *arv); 
void buscaPosOrdem(tabp *arv);

tno *retornaRaiz(tabp *arv);

int alturaArvore(tabp *arv);

tno *buscaNo(tabp *arv, int dado);
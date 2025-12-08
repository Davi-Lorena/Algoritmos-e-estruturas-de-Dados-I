typedef struct no tno;
typedef struct abp tabp;

tabp *criaArvore();

tno *criaNo(int chave);

void insereNo(tno *no, tabp *arv);

int carregaNo(tabp *arv, char *nomeArquivo);

void percorrePreOrdem(tno *no);

void percorrePosOrdem(tno *no);

void percorreOrdem(tno *no);

tno *retornaRaiz(tabp *arv);

tno *sucessor(tabp *arv);

tno *buscaNo(tabp *arv, int dado);

int removeNo(tabp *arv, int chave);

tno *maiorNo(tabp *arv);

tno *menorNo(tabp *arv);
int arvIguais(tno *raiz1, tno *raiz2);
int NosFolhas(tno *no);
int totalNos(tno *no);
int valorTotal(tno *no);

int estritamenteBinaria(tno *no);
typedef struct carros tcarro;

tcarro *alocaPreenche(int n);

void alterar(int n, char placa[], tcarro *p);

void imprimirPelaPlaca (int n, char placa[], tcarro *p);

void retornaQuant(int n, tcarro *p, char marca[]) ;

void liberar(tcarro *p);
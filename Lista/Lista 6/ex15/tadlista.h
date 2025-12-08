typedef struct no tno;

typedef struct lista tlista; 

tlista* crialista();

int insereno(tlista *l, int dado);

int removeno(tlista *l, int dado);

void exibelista(tlista *l);

void exibetras(tlista *l);

int pulaSoldados(tlista *l, int n);
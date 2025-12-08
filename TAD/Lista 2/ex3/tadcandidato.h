typedef struct candidato tcandidato;



tcandidato *criaListaCandidato(int n);
void buscarCId (int n, char ident[], tcandidato *p);
void buscaCE(int n, char grau[], tcandidato *p);
void imprimeNomeProf(int n, char profissao[], tcandidato *p);
void liberaCandidato (tcandidato *p);
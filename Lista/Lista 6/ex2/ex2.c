#include <stdlib.h>

typedef struct lista tlista;
typedef struct no tno;

void incluiLista(tlista *l, int info) {
 tno *p, *aux, *ant;
 p = (tno*)malloc(sizeof(tno));
 if (!p) printf("\n Nao tem memoria \n");
 else {
 aux = l->com;
 ant = (tno *) NULL;
 while ((aux) && (aux->dado < info)) {
 ant = aux;
 aux = aux->prox;
 }
 p-> dado = info;
 if (!ant) {
 p->prox = l->com;
 l->com = p;
 }
 else {
 ant->prox = p;
 p->prox = aux;
 }
 }}

 // 1) Os parâmetros são passados por referência para que a "lista original" seja alterada, o que não ocorreria 
 // Se não fosse passado como um ponteiro

 // 2) Porque, nesse caso, temos que l é um ponteiro para uma lista e o operador -> estaria apontando para o campo referenciado por aquele endereço de memória 
 
 // 3) 
 /*
ant->dado = NULL 
aux->dado = 5

ant->dado = 5
aux->dado = 8

ant->dado = 8 
aux->dado = 12
 
ant->dado = 12 
aux->dado = 85

ant->dado = 85 
aux->dado = NULL

 */
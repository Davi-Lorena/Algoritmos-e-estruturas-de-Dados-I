//
// Created by Vanessa on 24/11/2025.
//

#ifndef TAD_HEAP_HEAP_H
#define TAD_HEAP_HEAP_H

typedef struct heap heap;


//Cria uma heap
//tam indica a quantidade máxima de elementos da heap
heap *criaHeap(int tam);

//Insere um novo elemento na heap
//Considera um heap de máximo
//Retorna -1 se não for possível inserir - heap cheia
//Retorna 1 se inseriu
int insereElemento(heap *h, int elemento);

//Lê os dados do arquivo e insere na heap
//Chama a função insereElemento
//Retorna -1 se não for possível inserir todos os elementos
//Retorna 1 se inseriu
int carregaElementos(char nomeArquivo[], heap *h);

//Retorna a quantidade de elementos na heap
int retornaOcupacao(heap *h);

// Retorna a raiz
int retornaMaiorPrioridade(heap *h);

//Remove um elemento da heap
//Retorna -1 caso a heap esteja vazia
//Retorna o elemento removido, caso contrário
//Chama a função MaxHeapify para corrigir a estrutura
int removeElemento(heap *h);

//Realiza a correção da heap após uma remoção ou alteração de prioridade
//Pseudocódigo no livro do Cormen - 2 edição - pag. 76
void MaxHeapify(heap *h, int pos);

//Altera a prioridade de um elemento na heap
//Chama a função MaxHeapify para corrigir a estrutura
void alteracaoPrioridade_pos(heap *h, int pos, int novaPrioridade);

void alteracaoPrioridade_valor(heap *h, int elemento, int novaPrioridade);

//Imprime na tela o vetor que contém a heap
//Função para fins de verificação, uma vez que não se percorre uma fila
void imprimeVetor(heap *h);

void destroiHeap(heap *h);


#endif //TAD_HEAP_HEAP_H

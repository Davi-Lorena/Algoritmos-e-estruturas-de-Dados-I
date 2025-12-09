# Algoritmos e Estruturas de Dados I 
[![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Estruturas de Dados](https://img.shields.io/badge/Tópicos-Estruturas%20de%20Dados%20%26%20Algoritmos-brightgreen)](https://en.wikipedia.org/wiki/Data_structure)
[![Status](https://img.shields.io/badge/Status-Aprendizado%20Concluído-success.svg)](https://github.com/davi-lorena/algoritmos-e-estruturas-de-dados-i)

## 💡 Sobre o Repositório

Este repositório é um **portfólio de aprendizado** da disciplina de **Algoritmos e Estruturas de Dados I** do curso **"Ciência da Computação"**. O foco é na implementação das estruturas de dados fundamentais e conceitos de programação em **C**.

O conteúdo reflete a jornada de aprendizado, desde a revisão de conceitos básicos até a implementação de estruturas de dados mais complexas, com ênfase no uso de **Tipos Abstratos de Dados (TADs)** e alocação dinâmica de memória.

***

## ⚙️ Conteúdo da Disciplina

O material está organizado em diretórios por tópicos principais, seguindo o cronograma da matéria:

### 1. Fundamentos e Modularização

| Diretório | Descrição |
| :--- | :--- |
| **Listas de exercício/** | Exercícios iniciais para revisão de lógica e sintaxe em C. |
| **TAD/** | Implementação de **Tipos Abstratos de Dados** (Ex: Ponto, Pessoa, Produto, Matriz), focando na modularização, separação de interface (`.h`) e implementação (`.c`). |
| **Recursividade/** | Listas de exercícios e problemas dedicados à solução utilizando funções recursivas. |

### 2. Estruturas de Dados Lineares

Implementações dos TADs lineares clássicos, utilizando principalmente o conceito de **listas encadeadas** para alocação dinâmica:

| Estrutura | Princípio | Diretórios Relacionados |
| :--- | :--- | :--- |
| **Pilha** (Stack) | **LIFO** (Last-In, First-Out) | `Pilha/`, `TADs AED/Pilha/` |
| **Fila** (Queue) | **FIFO** (First-In, First-Out) | `Fila/`, `TADs AED/Fila/` |
| **Listas Encadeadas** | Inserção e remoção dinâmica de nós. | `Lista/`, `TADs AED/Lista Duplamente Encadeada/` |
| &nbsp;&nbsp;*Tipos:* | Listas Simplesmente, Duplamente e Circularmente Encadeadas. | |

### 3. Estruturas de Dados Não Lineares

Estruturas mais avançadas, que introduzem conceitos de organização hierárquica e otimização de operações:

| Estrutura | Propriedade | Diretório |
| :--- | :--- | :--- |
| **Árvore Binária de Pesquisa (ABP)** | Estrutura otimizada para busca, inserção e remoção de dados (BST - Binary Search Tree). | `Árvore Binária de Pesquisa/` |
| **TAD Heap** | Estrutura de dados baseada em árvore que satisfaz a propriedade de Heap (Min/Max Heap). | `TAD Heap/` |
| **Árvore de Expressão** | Utilização de árvores para representar e avaliar expressões aritméticas complexas. | `Árvore de expressão aritmética/` |

***

## 💻 Como Compilar e Executar

Os projetos foram desenvolvidos na linguagem C. Para testar qualquer implementação:

1.  **Pré-requisito:** Certifique-se de ter um compilador C instalado.
2.  **Clonar o Repositório:**
    ```bash
    git clone [LINK REPOSITÓRIO]
    cd algoritmos-e-estruturas-de-dados-i
    ```
3.  **Compilação e Execução (Exemplo de TAD):**
    Para projetos que utilizam **TADs** (com arquivos `.c` e `.h` separados, como Pilhas e Listas), você deve compilar todos os arquivos `.c` juntos:

    ```bash
    # 1. Navegue até o diretório do projeto, por exemplo, um exercício de Pilha
    cd Pilha/ex-2

    # 2. Compile o arquivo principal (main.c) e o arquivo do TAD (tadpilha.c)
    gcc main.c tadpilha.c -o programa_exemplo

    # 3. Execute o programa
    ./programa_exemplo
    ```

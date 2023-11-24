//Aplicando guardas de inclusão, que evitam a inclusão duplicada do mesmo arquivo de cabeçalho em um programa.
#ifndef PILHA_H
#define PILHA_H
// Definição de um tipo abstrato de dados (TAD) chamado Pilha
typedef struct pilha Pilha;

// Protótipo da função para criar uma nova pilha
Pilha * criar();

// Protótipo da função para destruir uma pilha, liberando a memória alocada
void destruir(Pilha * p);

// Protótipo da função para desempilhar (remover e obter) o elemento do topo da pilha
int desempilhar(Pilha * p);

// Protótipo da função para empilhar (adicionar) um elemento no topo da pilha
void empilhar(Pilha * p, int x);

// Protótipo da função para obter o tamanho atual da pilha (número de elementos)
int tamanho(Pilha * p);

// Protótipo da função para obter o elemento do topo da pilha sem removê-lo
int topo(Pilha * p);

// Protótipo da função para imprimir os elementos da pilha
void imprimir(Pilha * p);

// Protótipo da função para inverter a ordem dos três primeiros elementos da pilha
void inverter3(Pilha * p);

#endif

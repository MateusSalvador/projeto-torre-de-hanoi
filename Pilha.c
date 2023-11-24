#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define TAM_MAX 100

// Definição da estrutura da pilha
struct pilha {
  int itens[TAM_MAX]; // Array para armazenar os elementos da pilha
  int tp;             // Índice do topo da pilha
};

// Função para criar uma nova pilha
Pilha *criar() {
  Pilha *p =
      (Pilha *)malloc(sizeof(Pilha)); // Aloca espaço para a estrutura da pilha
  p->tp = 0; // Inicializa o índice do topo como 0 (pilha vazia)
  return p;
}

// Função para destruir uma pilha, liberando a memória alocada
void destruir(Pilha *p) {
  if (p != NULL) {
    free(p); // Libera a memória alocada para a estrutura da pilha
  }
}

// Função para desempilhar (remover e obter) o elemento do topo da pilha
int desempilhar(Pilha *p) {
  if (p->tp == 0) {
    printf("Pilha vazia");
    return -1; // Retorna um valor indicando erro (pilha vazia)
  }
  return p->itens[--p->tp]; // Retorna o elemento do topo e decrementa o índice
                            // do topo
}

// Função para empilhar (adicionar) um elemento no topo da pilha
void empilhar(Pilha *p, int x) {
  if (p->tp == TAM_MAX) {
    printf("Estouro de pilha!"); // Indica que a pilha está cheia (não pode
                                 // adicionar mais elementos)
    return;
  }
  p->itens[p->tp++] =
      x; // Adiciona o elemento no topo e incrementa o índice do topo
}

// Função para obter o tamanho atual da pilha (número de elementos)
int tamanho(Pilha *p) {
  return p->tp; // Retorna o índice do topo, que é o tamanho da pilha
}

// Função para obter o elemento do topo da pilha sem removê-lo
int topo(Pilha *p) {
  if (p->tp == 0) {
    // printf("Pilha vazia");
    return -1; // Retorna um valor indicando erro (pilha vazia)
  }
  return p->itens[p->tp - 1]; // Retorna o elemento no topo da pilha
}

// Função para imprimir os elementos da pilha
void imprimir(Pilha *p) {
  int i;
  printf("[ ");
  for (i = 0; i < p->tp; i++) {
    printf("%d ", p->itens[i]); // Imprime cada elemento da pilha
  }
  printf("]\n");
}

// Função para inverter a ordem dos três primeiros elementos da pilha
void inverter3(Pilha *p) {
  int i, f, tmp;
  for (i = 0, f = p->tp - 1; i < f; i++, f--) {
    tmp = p->itens[i];
    p->itens[i] = p->itens[f];
    p->itens[f] = tmp;
  }
}

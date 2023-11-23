#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define TAM_MAX 100

struct pilha {
    int itens[TAM_MAX];  // Array para armazenar os elementos da pilha
    int tp;              // Índice do topo da pilha
};

Pilha * criar() {
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->tp = 0;  
    return p;
}

void destruir(Pilha * p) {
    if (p != NULL) {
        free(p); 
    }
}

int desempilhar(Pilha * p) {
    if (p->tp == 0) {
        printf("Pilha vazia");
        return -1;  
    }
    return p->itens[--p->tp];  
}

void empilhar(Pilha * p, int x) {
    if (p->tp == TAM_MAX) {
        printf("Estouro de pilha!"); 
        return;
    }
    p->itens[p->tp++] = x; 
}


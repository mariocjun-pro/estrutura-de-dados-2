#ifndef ESTRUTURA_DE_DADOS_2_HEAP_H
#define ESTRUTURA_DE_DADOS_2_HEAP_H

#include <stdio.h>

int pai(int i);

void trocar(int v[], int a, int b);

void imprimir(int v[], int size);

void max_heapify(int v[], int size, int i);

void build_max_heap(int v[], int size);

void heap_sort(int v[], int size);

#endif //ESTRUTURA_DE_DADOS_2_HEAP_H

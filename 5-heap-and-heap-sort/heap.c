#include "heap.h"

int pai(int i) { return (i - 1) / 2; }

void trocar(int v[], int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void imprimir(int v[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void max_heapify(int v[], int size, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maior = i;
    if (l < size && v[l] > v[maior]) {
        maior = l;
    }
    if (r < size && v[r] > v[maior]) {
        maior = r;
    }
    if (maior != i) {
        trocar(v, i, maior);
        max_heapify(v, size, maior);
    }
}

void build_max_heap(int v[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        max_heapify(v, size, i);
    }
}

void heap_sort(int v[], int size) {
    build_max_heap(v, size);
    for (int i = size - 1; i >= 0; i--) {
        trocar(v, 0, i);
        max_heapify(v, i, 0);
    }
}

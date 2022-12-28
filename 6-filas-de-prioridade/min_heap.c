#include <stdio.h>
#include <stdlib.h>

int pai (int i) {
    return (i - 1)/2;
}

int esquerda (int i) {
    return (i * 2) + 1;
}

int direita (int i) {
    return (i * 2) + 2;
}

void trocar (int *V, int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir (int *V, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void min_heapify (int *V, int size, int i) {
    int e = esquerda (i);
    int d = direita (i);
    int menor;
    if ( (e < size) && (V[e] < V[i]) ) {
        menor = e;
    }
    else {
        menor = i;
    }
    if ( (d < size) && (V[d] < V[menor]) ) {
        menor = d;
    }
    if (menor != i) {
        trocar (V, i, menor);
        min_heapify (V, size, menor);
    }
}

void build_min_heap (int *V, int size) {
    for (int i = size/2 - 1; i >= 0; i--) {
        min_heapify (V, size, i);
    }
}

int heap_extract_min (int *V, int *size) {
    int min;
    if (*size < 1) {
        printf("Erro: heap underflow\n");
        return -1;
    }
    min = V[0];
    V[0] = V[*size - 1];
    *size = *size - 1;
    min_heapify (V, *size, 0);
    return min;
}

void heap_decrease_key (int *V, int i, int chave, int size) {
    if (chave > V[i]) { printf("Erro: nova chave é maior que a chave atual\n"); }

    V[i] = chave;
    while ( (i > 0) && (V[pai(i)] > V[i]) ) {
        trocar (V, i, pai(i));
        i = pai(i);
    }
}

void min_heap_insert (int *V, int chave, int *size) {
    *size = *size + 1;
    V[*size - 1] = 999999;
    heap_decrease_key (V, *size - 1, chave, *size);
}

int main () {

    int size = 10;

    int v[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    printf("Vetor inicial : ");
    imprimir (v, size);

    build_min_heap (v, size);
    printf("Vetor build_min_heap: ");
    imprimir (v, size);

    printf("Vetor heap_extract_min: ");
    heap_extract_min (v, &size);
    imprimir (v, size);

    //Modificando a última chave {16} para o valor {1}!
    heap_decrease_key (v, size-1, 1, size);
    printf("Vetor heap_decrease_key: ");
    imprimir (v, size);

    //Inserindo uma nova chave com valor {0}!
    min_heap_insert (v, 0, &size);
    printf("Vetor min_heap_insert 0: ");
    imprimir (v, size);

    return 0;
}

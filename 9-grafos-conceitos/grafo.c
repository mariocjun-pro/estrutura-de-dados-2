#include "grafo.h"

/*Função para criar um grafo com lista de adjacências.*/
GrafoA *criar_grafo_adj(int tamanho) {
    int v;
    GrafoA *G = (GrafoA *) malloc(sizeof(GrafoA));
    G->E = 0;
    G->V = tamanho;
    G->Adj = (NoA **) malloc(tamanho * sizeof(NoA *));
    for (v = 0; v < G->V; v++) {
        G->Adj[v] = NULL;
    }
    return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM *criar_grafo_mat(int tamanho) {
    int v;
    GrafoM *G = (GrafoM *) malloc(sizeof(GrafoM));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int **) malloc(tamanho * sizeof(int *));
    for (v = 0; v < G->V; v++) {
        G->Mat[v] = (int *) malloc(tamanho * sizeof(int));
    }
    return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj(GrafoA *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        if (G->Adj[v] != NULL) {
            free(G->Adj[v]);
        }
    }
    free(G->Adj);
    free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat(GrafoM *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        if (G->Mat[v] != NULL) {
            free(G->Mat[v]);
        }
    }
    free(G->Mat);
    free(G);
}

/*Função para adicionar uma aresta em um grafo com matriz de adjacências.*/
void add_aresta_mat(GrafoM *G, int v, int w) {
    G->Mat[v][w] = 1;
    G->Mat[w][v] = 1;
    G->E++;
}

/*Função para adicionar uma aresta em um grafo com lista de adjacências.*/
void add_aresta_adj(GrafoA *G, int v, int w) {
    NoA *novo = (NoA *) malloc(sizeof(NoA));
    novo->id = w;
    novo->next = G->Adj[v];
    G->Adj[v] = novo;
    G->E++;
}

/*Função para imprimir um grafo com lista de adjacências.*/
void print_grafo_adj(GrafoA *G) {
    int v;
    NoA *aux;
    for (v = 0; v < G->V; v++) {
        printf("%d: ", v);
        aux = G->Adj[v];
        while (aux != NULL) {
            printf("%d ", aux->id);
            aux = aux->next;
        }
        printf("\n");
    }
}

/*Função para imprimir um grafo com matriz de adjacências.*/
void print_grafo_mat(GrafoM *G) {
    int v, w;
    // printar a linha acima da matriz
    printf("   ");
    for (int i = 0; i < G->V; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (v = 0; v < G->V; v++) {
        printf("%d: ", v);
        for (w = 0; w < G->V; w++) {
            if (G->Mat[v][w] == 1) {
                printf("1 ");
            }
            if (G->Mat[v][w] == 0) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

/*Função

/*Função para adicionar uma aresta em um grafo ponderado com lista de adjacências.*/
void add_aresta_peso_adj(GrafoA *G, int v, int w, int peso) {
    NoA *novo = (NoA *) malloc(sizeof(NoA));
    novo->id = w;
    novo->peso = peso;
    novo->next = G->Adj[v];
    G->Adj[v] = novo;
    G->E++;
}

/*Função para imprimir um grafo ponderado com lista de adjacências.*/
void print_grafo_peso_adj(GrafoA *G) {
    int v;
    NoA *aux;
    for (v = 0; v < G->V; v++) {
        printf("%d: ", v);
        aux = G->Adj[v];
        while (aux != NULL) {
            printf("%d(%d) ", aux->id, aux->peso);
            aux = aux->next;
        }
        printf("\n");
    }
}

/*Função para adicionar uma aresta em um grafo ponderado com matriz de adjacências.*/
void add_aresta_peso_mat(GrafoM *G, int v, int w, int peso) {
    G->Mat[v][w] = peso;
    G->Mat[w][v] = peso;
    G->E++;
}

/*Função para imprimir um grafo ponderado com matriz de adjacências.*/
void print_grafo_peso_mat(GrafoM *G) {
    int v, w;
    // printar a linha acima da matriz
    printf("   ");
    for (int i = 0; i < G->V; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (v = 0; v < G->V; v++) {
        printf("%d: ", v);
        for (w = 0; w < G->V; w++) {
            if (G->Mat[v][w] != 0) {
                printf("%d ", G->Mat[v][w]);
            }
            if (G->Mat[v][w] == 0) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}



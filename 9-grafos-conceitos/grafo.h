//
// Created by CIANDT\mariocj on 18/11/22.
//

#ifndef ESTRUTURA_DE_DADOS_2_GRAFO_H
#define ESTRUTURA_DE_DADOS_2_GRAFO_H

#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
    int id;          /*Identificador armazenado no nó. */
    struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
    int E; /* Quantidade de arestas. */
    int V; /* Quantidade de vértices. */
    NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
    int E; /* Quantidade de arestas. */
    int V; /* Quantidade de vértices. */
    int **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Estrutura de Grafo com lista de adjacências e orientação: */
typedef struct grafoAO {
    int E; /* Quantidade de arestas. */
    int V; /* Quantidade de vértices. */
    int orientado; /* Grafo orientado ou não. */
    NoA **Adj; /* Lista de adjacências. */
} GrafoAO;

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho);

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho);

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G);

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G);

/*Função para adicionar uma aresta em um grafo com matriz de adjacências.*/
void add_aresta_mat (GrafoM *G, int v, int w);

/*Função para adicionar uma aresta em um grafo com lista de adjacências.*/
void add_aresta_adj (GrafoA *G, int v, int w);

/*Função para imprimir um grafo construído com lista de adjacências.*/
void print_grafo_adj (GrafoA *G);

/*Função para imprimir um grafo construído com matriz de adjacências.*/
void print_grafo_mat (GrafoM *G);

/*Função para criar um grafo com lista de adjacências e orientação.*/
GrafoAO* criar_grafo_adj_orientado (int tamanho);

/*Função para adicionar uma aresta em um grafo com lista de adjacências e orientação.*/
void add_aresta_adj_orientado (GrafoAO *G, int v, int w);

/*Função para imprimir um grafo construído com lista de adjacências e orientação.*/
void print_grafo_adj_orientado (GrafoAO *G);

/*Função para destruir um grafo construído com lista de adjacências e orientação.*/
void liberar_grafo_adj_orientado (GrafoAO *G);

/*Função para criar um grafo com matriz de adjacências e orientação.*/
GrafoM* criar_grafo_mat_orientado (int tamanho);

/*Função para adicionar uma aresta em um grafo com matriz de adjacências e orientação.*/
void add_aresta_mat_orientado (GrafoM *G, int v, int w);

/*Função para imprimir um grafo construído com matriz de adjacências e orientação.*/
void print_grafo_mat_orientado (GrafoM *G);

/*Função para destruir um grafo construído com matriz de adjacências e orientação.*/
void liberar_grafo_mat_orientado (GrafoM *G);

/*Função para adicionar uma aresta em um grafo com lista de adjacências, orientação e peso.*/
void add_aresta_adj_orientado_peso (GrafoAO *G, int v, int w, int peso);

/*Função para imprimir um grafo construído com lista de adjacências, orientação e peso.*/
void print_grafo_adj_orientado_peso (GrafoAO *G);

/*Função para criar um grafo com matriz de adjacências, orientação e peso.*/
GrafoM* criar_grafo_mat_orientado_peso (int tamanho);

/*Função para adicionar uma aresta em um grafo com matriz de adjacências, orientação e peso.*/
void add_aresta_mat_orientado_peso (GrafoM *G, int v, int w, int peso);

/*Função para imprimir um grafo construído com matriz de adjacências, orientação e peso.*/
void print_grafo_mat_orientado_peso (GrafoM *G);


#endif //ESTRUTURA_DE_DADOS_2_GRAFO_H

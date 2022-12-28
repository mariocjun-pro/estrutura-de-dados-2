#include "grafo.h"

int main() {

    int Va = 6; /*Número de vértices*/

    GrafoA *Ga = criar_grafo_adj(Va);

    int Vm = 6; /*Número de vértices*/

    GrafoM *Gm = criar_grafo_mat(Vm);

    // Adicionando arestas no grafo com lista de adjacências
    add_aresta_adj(Ga, 0, 1);
    add_aresta_adj(Ga, 0, 2);
    add_aresta_adj(Ga, 0, 5);
    add_aresta_adj(Ga, 1, 0);
    add_aresta_adj(Ga, 1, 2);
    add_aresta_adj(Ga, 1, 3);
    add_aresta_adj(Ga, 2, 0);
    add_aresta_adj(Ga, 2, 1);
    add_aresta_adj(Ga, 2, 3);
    add_aresta_adj(Ga, 2, 4);
    add_aresta_adj(Ga, 3, 1);
    add_aresta_adj(Ga, 3, 2);
    add_aresta_adj(Ga, 3, 4);
    add_aresta_adj(Ga, 4, 2);
    add_aresta_adj(Ga, 4, 3);
    add_aresta_adj(Ga, 4, 5);
    add_aresta_adj(Ga, 5, 0);
    add_aresta_adj(Ga, 5, 4);

    print_grafo_adj(Ga);

    printf("\n");
    // Adicionando arestas no grafo com matriz de adjacências
    add_aresta_mat(Gm, 0, 1);
    add_aresta_mat(Gm, 0, 2);
    add_aresta_mat(Gm, 0, 5);
    add_aresta_mat(Gm, 1, 0);
    add_aresta_mat(Gm, 1, 2);
    add_aresta_mat(Gm, 1, 3);
    add_aresta_mat(Gm, 2, 0);
    add_aresta_mat(Gm, 2, 1);
    add_aresta_mat(Gm, 2, 3);
    add_aresta_mat(Gm, 2, 4);
    add_aresta_mat(Gm, 3, 1);
    add_aresta_mat(Gm, 3, 2);
    add_aresta_mat(Gm, 3, 4);
    add_aresta_mat(Gm, 4, 2);
    add_aresta_mat(Gm, 4, 3);
    add_aresta_mat(Gm, 4, 5);
    add_aresta_mat(Gm, 5, 0);
    add_aresta_mat(Gm, 5, 4);

    print_grafo_mat(Gm);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);

    return 0;
}

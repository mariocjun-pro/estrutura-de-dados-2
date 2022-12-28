#include "grafo.h"
#include <stdlib.h>

int main() {
    struct Graph *g = Graph_alloc();
    Graph_insertVertex(g, "A");
    Graph_insertVertex(g, "B");
    Graph_insertVertex(g, "C");
    Graph_insertVertex(g, "D");
    Graph_insertVertex(g, "E");

    Graph_insertEdge(g, 0, 1, "A-B");
    Graph_insertEdge(g, 0, 2, "A-C");
    Graph_insertEdge(g, 1, 3, "B-D");
    Graph_insertEdge(g, 2, 3, "C-D");
    Graph_insertEdge(g, 3, 4, "D-E");
    Graph_insertEdge(g, 4, 0, "E-A");

    Graph_dijkstra(g, 0);

    Graph_print(g, NULL);

    Graph_free(g);
}
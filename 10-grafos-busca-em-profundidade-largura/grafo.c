#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

Graph *Graph_alloc() {
    Graph *g = malloc(sizeof(Graph));

    if (g) {
        g->n = 0;
        g->first = NULL;
        g->last = NULL;
    }

    return g;
}

void Graph_free(Graph *g) {
    Edge *e = NULL, *eaux;
    Vertex *v = NULL, *vaux;

    if (g) {
        v = g->first;

        while (v) {
            vaux = v->next;

            e = v->first;
            while (e) {
                eaux = e->next;
                free(e);
                e = eaux;
            }

            free(v);
            v = vaux;
        }

        free(g);
    }
}

void Graph_insertVertex(Graph *g, void *value) {
    Vertex *new = NULL;

    if (g) {
        new = malloc(sizeof(Vertex));
        new->n = 0;
        new->visited = 0;
        new->label = g->n;
        new->value = value;
        new->first = NULL;
        new->last = NULL;
        new->next = NULL;

        if (g->n == 0) {
            g->first = new;
            g->last = new;
        } else {
            g->last->next = new;
            g->last = new;
        }

        g->n++;
    }
}

Vertex *Graph_findByLabel(Graph *g, int label) {
    Vertex *v = NULL;

    if (g) {
        v = g->first;

        while (v) {
            if (v->label == label)
                return v;
            v = v->next;
        }
    }

    return NULL;
}

void Graph_insertEdge(Graph *g, int label1, int label2, void *value) {
    Edge *new = NULL, *e = NULL;
    Vertex *tail, *head;

    if (g) {
        tail = Graph_findByLabel(g, label1);
        head = Graph_findByLabel(g, label2);

        if (tail && head) {
            new = malloc(sizeof(Edge));
            new->tail = tail;
            new->head = head;
            new->value = value;
            new->next = NULL;

            if (tail->n == 0) {
                tail->first = new;
                tail->last = new;
            } else {
                tail->last->next = new;
                tail->last = new;
            }

            tail->n++;
        }
    }
}

void Graph_print(Graph *g, void (*print)(void *value)) {
    Vertex *v = NULL;
    Edge *e = NULL;

    if (g) {
        printf("Graph(%d):\n", g->n);

        v = g->first;

        if (print) {
            while (v) {
                printf("\t[");
                print(v->value);
                printf(" /%d]->", v->n);

                e = v->first;
                while (e) {
                    printf("(");
                    print(e->head->value);
                    printf(")->");
                    e = e->next;
                }

                printf("\n");
                v = v->next;
            }
        } else {
            while (v) {
                printf("\t[%d /%d]->", v->label, v->n);

                e = v->first;
                while (e) {
                    printf("(%d)->", e->head->label);
                    e = e->next;
                }

                printf("\n");
                v = v->next;
            }
        }
    }
}

Graph *Graph_random(int n) {
    Graph *g = NULL;
    int i, j, k, m, *v;

    if (n > 0) {
        g = Graph_alloc();

        for (i = 0; i < n; i++) {
            v = malloc(sizeof(int));
            *v = i;
            Graph_insertVertex(g, v);
        }

        for (i = 0; i < n; i++) {
            m = rand() % n;

            for (j = 0; j < m; j++) {
                k = rand() % n;
                Graph_insertEdge(g, i, k, NULL);
            }
        }
    }

    return g;
}

void Graph_dijkstra(Graph *g, int labelStart) {
    Vertex *v = NULL, *u = NULL, *w = NULL;
    Edge *e = NULL;
    int i, min, *d, *p;

    if (g) {
        d = malloc(g->n * sizeof(int));
        p = malloc(g->n * sizeof(int));

        for (i = 0; i < g->n; i++) {
            d[i] = -1;
            p[i] = -1;
        }

        v = Graph_findByLabel(g, labelStart);
        d[v->label] = 0;

        while (v) {
            e = v->first;

            while (e) {
                w = e->head;

                if (d[w->label] == -1 || d[w->label] > d[v->label] + 1) {
                    d[w->label] = d[v->label] + 1;
                    p[w->label] = v->label;
                }

                e = e->next;
            }

            v->visited = 1;

            min = -1;
            u = NULL;

            for (i = 0; i < g->n; i++) {
                w = Graph_findByLabel(g, i);

                if (!w->visited && d[w->label] != -1) {
                    if (min == -1 || d[w->label] < min) {
                        min = d[w->label];
                        u = w;
                    }
                }
            }

            v = u;
        }

        for (i = 0; i < g->n; i++) {
            printf("d[%d] = %d, p[%d] = %d\n", i, d[i], i, p[i]);
        }

        free(d);
        free(p);
    }
}

typedef struct Graph Graph;
typedef struct Vertex Vertex;
typedef struct Edge Edge;

// estrutura da Aresta.
struct Edge {
    int label;
    void *value;
    // cauda do verticie.
    Vertex *tail;
    // cabeca do verticie.
    Vertex *head;
    // proxima aresta.
    Edge *next;
};

// estrutura do Verticie.
struct Vertex {
    int n;
    int label;
    int visited;
    void *value;
    // primeiro aresta.
    Edge *first;
    // ultimo aresta.
    Edge *last;
    // proximo verticie.
    Vertex *next;
};

// estrutura do Grafo.
struct Graph {
    int n;
    // primeiro verticie.
    Vertex *first;
    // ultimo vertcie.
    Vertex *last;
};

// aloca espaco de memoria para o grafo.
Graph *Graph_alloc();

// libera espaco de memoria do grafo.
void Graph_free(Graph *g);

// insere o verticie no grafo.
void Graph_insertVertex(Graph *g, void *value);

// insere a aresta no grafo.
void Graph_insertEdge(Graph *g, int label1, int label2, void *value);

// remove o verticie do grafo.
void Graph_removeVertex(Graph *g, int label);

// remove a aresta do grafo.
void Graph_removeEdge(Graph *g, int label1, int label2);

// pesquisa o rotulo no grafo.
Vertex *Graph_findByLabel(Graph *g, int label);

// pesquisa o valor no grafo.
Vertex *Graph_findByValue(Graph *g, void *value, int (*cmp)(void *, void *));

// exibe o grafo.
void Graph_print(Graph *g, void (*print)(void *value));

void Graph_dijkstra(Graph *g, int labelStart);

// cria um grafo aleatorio com n vertices, as arestas sao criadas aleatoriamente.
Graph *Graph_random(int n);
#include "grafo.h"

Vertex VertexInitialize(int value) {
    Vertex v = (Vertex)malloc(sizeof(Vertex));
    v->value = value;
    v->prox = NULL;
    return v;
}

Graph GraphInitialize(int V) {
    Graph G = (Graph)malloc(sizeof(Graph));
    G->V = V;
    G->E = 0;
    G->adj = (Vertex*)malloc(V * sizeof(Vertex));

    for(int v=0; v < V; v++)
        G->adj[v] = VertexInitialize(v); // cria apenas os pontos, ainda nao estao conectados
    
    return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) { // adicione uma nova ligacao
    Vertex v = G->adj[v1->value];

    while(v->prox != NULL) { // verifica se ja existe a correlacao
        if(v->value == v2->value)
            return;
        v = v->prox;
    }

    v->prox = VertexInitialize(v2->value);
    G->E++;
}

void ImprimeGraph(Graph G) {
    Vertex aux;

    for(int v=0; v < G->V; v++) {
        aux = G->adj[v];
        
        while(aux != NULL) {
            printf(" %d -> ", aux->value);
            aux = aux->prox;
        }
        printf("\n");
    }
}
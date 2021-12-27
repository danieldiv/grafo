#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TipoVertex *Vertex;
typedef struct graph *Graph;

struct TipoVertex {
    int value;
    Vertex prox;
};

struct graph {
    int V; // quantos vertices
    int E; // quantas arestas
    Vertex *adj; // vetor de quantos grafos utilizar com tamanho definido pelo malloc
};

Vertex VertexInitialize(int value);
Graph GraphInitialize(int V);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph(Graph G);

#endif
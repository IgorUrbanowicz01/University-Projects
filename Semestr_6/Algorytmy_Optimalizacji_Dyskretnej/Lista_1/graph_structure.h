#ifndef GRAPH_STRUCTURE_H
#define GRAPH_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

struct AdjListNode {
    int dest;
    int pred;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    bool dircted;
    int v;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int v, bool d);
void addEdge(struct Graph* graph, int src, int dest);
void addPred(struct Graph* graph, int node, int pred);

#endif
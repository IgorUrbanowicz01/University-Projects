/*This usses the concept of a Adjacency List*/

#include "graph_structure.h"


struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int v, bool d){
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->v = v;
    newGraph->dircted = d;

    newGraph->array= (struct AdjList*)malloc(v*sizeof(struct AdjList));

    for (int i = 0; i < v; i++){
        newGraph->array[i].head = NULL;
    }
    return newGraph;
    }

void addEdge(struct Graph* graph, int src, int dest){
    //printf("%d -- %d\n", src, dest);
    struct AdjListNode* crawl = NULL;
    struct AdjListNode* destNode = newAdjListNode(dest);

    if(graph->array[src].head == NULL){
        graph->array[src].head= destNode;
    }else{
        crawl = graph->array[src].head;
        while (crawl->next != NULL) {
            crawl = crawl->next;
        }

        crawl->next = destNode;
    }
if (graph->dircted == 0)
{
    printf("sex");
    struct AdjListNode* srcNode = newAdjListNode(src);
    if (graph->array[dest].head == NULL) {
        srcNode->next = graph->array[dest].head;
        graph->array[dest].head = srcNode;
    }
    else {
        crawl = graph->array[dest].head;
        while (crawl->next != NULL) {
            crawl = crawl->next;
        }
        crawl->next = srcNode;
    }
}
}

void addPred(struct Graph* graph, int node, int pred){
        if (graph->array[node].head == NULL) {
            struct AdjListNode* newNode = newAdjListNode(node);
            graph->array[node].head = newNode;
            newNode->pred = pred;
        }else
        graph->array[node].head->pred = pred;
        printf("%d -> %d || ", pred, node);
}





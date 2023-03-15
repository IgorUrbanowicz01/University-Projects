#include"graph_structure.h"

#include <stdbool.h>


struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};


/* QUEUE */

struct Node* newQueueNode(int data);
struct Queue* createQueue();
bool isQueueEmpty(struct Queue* q);
void pushQueue(struct Queue* q, int data);
int popSQueue(struct Queue* q);

/* BFS */

void BFS(struct Graph* graph, int s);
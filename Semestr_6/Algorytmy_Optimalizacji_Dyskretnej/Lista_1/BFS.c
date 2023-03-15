#include"BFS.h"

// Queue Section //


struct Node* newQueueNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

bool isQueueEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void pushQueue(struct Queue* q, int data) {
    struct Node* temp = newQueueNode(data);

    if (isQueueEmpty(q)) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int popQueue(struct Queue* q){

    struct Node* temp;
    int data;
    if (isQueueEmpty(q))
    {
        printf("The queue is empty!");
        return -1;
    }
    temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}


void BFS(struct Graph* graph, int s){
    int n = graph->v;
    int seen[n];
    int current, listlenght;
    bool found = 0;
    struct Queue *queue = createQueue();
    struct AdjListNode *crawl = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    if (s > n)
    {
        printf("%d is outside of the graph", s);
        return; 
    }
    seen[0] = s;
    listlenght = 1; // the lenght of the seen array
    addPred(graph, s, 0);
    pushQueue(queue, s);
    while(!isQueueEmpty(queue)){
        current = popQueue(queue);
        crawl = graph->array[current].head;
        while(crawl != NULL){
            for (int i = 0; i < listlenght; i++)
                if (seen[i] == crawl->dest)
                    found = 1;
            if (found == 0){
                seen[listlenght] = crawl->dest;
                listlenght++;
                addPred(graph, crawl->dest, current);
                pushQueue(queue, crawl->dest);
            }else
            found = 0;
            crawl = crawl->next;
        }
    }
}
#include"topological_sort.h"

bool topologicalSort(struct Graph *graph, int *order){
    int i, j;
    int indegree[graph->v];

    for(i = 0; i < graph->v; i++)
        indegree[i] = 0;

    for(i = 0; i < graph->v; i++){
        struct AdjListNode* crawl = graph->array[i].head;
        while (crawl != NULL){
            indegree[crawl->dest]++;
            crawl = crawl->next;
        }
    }

    int count = 0;
    struct Queue* queue = createQueue();

    for(i = 0; i < graph->v; i++){
        if(indegree[i] == 0)
            pushQueue(queue, i);
    }

    while(!isQueueEmpty(queue)){
        int current = popQueue(queue);
        order[count++] = current;

        struct AdjListNode* crawl = graph->array[current].head;
        while(crawl != NULL){
            if(--indegree[crawl->dest] == 0)
                pushQueue(queue, crawl->dest);
            crawl = crawl->next;
        }
    }

    if(count != graph->v){
        return false;
    }

    return true;
}


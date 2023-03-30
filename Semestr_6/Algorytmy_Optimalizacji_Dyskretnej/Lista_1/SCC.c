#include"SCC.h"

void DFS_SCC(struct Graph* graph, int s, bool visited[], struct Stack* stack) {
    // Mark the current node as visited
    visited[s] = true;

    struct AdjListNode* crawl = graph->array[s].head;

    while (crawl != NULL) {
        int v = crawl->dest;
        if (!visited[v]) {
            addPred(graph, v, s);
            DFS_SCC(graph, v, visited, stack);
        }
        crawl = crawl->next;
    }

    pushStack(stack, s);
}

void SCC(struct Graph* graph) {
    int n = graph->v;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    struct Stack* stack = createStack();

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS_SCC(graph, i, visited, stack);
        }
    }

    // Create a reversed graph
    struct Graph* reversedGraph = createGraph(n, true);
    for (int i = 0; i < n; i++) {
        struct AdjListNode* crawl = graph->array[i].head;
        while (crawl != NULL) {
            addEdge(reversedGraph, crawl->dest, i);
            crawl = crawl->next;
        }
    }
    printf("\n");

    // Run DFS on the reversed graph using the order in stack
    memset(visited, false, sizeof(visited));
    int sccCount = 0;
    while (!isStackEmpty(stack)) {
        int s = popStack(stack);
        if (!visited[s]) {
            struct Stack* componentStack = createStack();
            DFS_SCC(reversedGraph, s, visited, componentStack);
            printf("Strongly Connected Component %d: ", ++sccCount);
            int count = 0;
            while (!isStackEmpty(componentStack)) {
                int v = popStack(componentStack);
                printf("%d ", v);
                count++;
            }
            printf("(size: %d)\n", count);
            free(componentStack);
        }
    }

    free(reversedGraph);
    free(stack);
}

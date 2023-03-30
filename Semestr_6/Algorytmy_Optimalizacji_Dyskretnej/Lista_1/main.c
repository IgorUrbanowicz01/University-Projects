#include"read_file.h"
#include"topological_sort.h"
#include"SCC.h"

int main(int argc, char const *argv[])
{
    struct Graph* graph = getGraph(argv[1]);
    BFS(graph, 1);
    printf("\n\n");
    DFS(graph, 1);
    printf("\n\n");
    int order[graph->v];
    if(topologicalSort(graph, order)){
        printf("This grap is in topological order\n");
    }else{
        printf("This grap is not in topological order\n");
    }
    printf("\n\n\n\n");
    SCC(graph);
    return 0;
}
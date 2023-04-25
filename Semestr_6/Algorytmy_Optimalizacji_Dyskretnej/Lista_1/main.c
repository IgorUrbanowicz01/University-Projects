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
        printf("grafy bez skierowanego cyklu (DAG-i)\n");
    }else{
        printf("grafy ze skierowanym cyklem\n");
    }
    printf("\n\n\n\n");
    SCC(graph);
    return 0;
}
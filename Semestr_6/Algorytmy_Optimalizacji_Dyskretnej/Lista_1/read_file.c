#include "graph_structure.h"
#include "BFS.h"
#include "DFS.h"

struct Graph* getGraph(const char* fileName){
    FILE *file;
    int n, m, src, dest, directed;
    bool d;

    file = fopen(fileName, "r");

    if (file == NULL){
        printf("no file under %s", fileName);
        return NULL;
    }

    directed = fgetc(file);
    if (directed == 'D')
        d = 1;
        else if (directed == 'U')
            d = 0;
        else{
        printf("Wrong graph diretion");
        return NULL;
    }

    fscanf(file ,"%d", &n);
    fscanf(file ,"%d", &m);

    struct Graph* graph = createGraph(n, d);

    for (int i = 0; i < m; i++)
    {
        fscanf(file ,"%d", &src);
        fscanf(file ,"%d", &dest);
        addEdge(graph, src, dest);
        //printf("edge: %d , %d \n", src, dest);
    }
    return graph;
}

int main(int argc, char const *argv[])
{
    struct Graph* graph = getGraph(argv[1]);
    BFS(graph, 1);
    printf("\n\n");
    DFS(graph, 1);
    return 0;
}

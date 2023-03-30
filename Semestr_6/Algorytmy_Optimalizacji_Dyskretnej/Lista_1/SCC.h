#include"graph_structure.h"
#include"DFS.h"
#include <string.h>

void SCC(struct Graph* graph);
void DFS_SCC(struct Graph* graph, int s, bool visited[], struct Stack* stack);
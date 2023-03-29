int main(int argc, char const *argv[])
{
    struct Graph* graph = getGraph(argv[1]);
    BFS(graph, 1);
    printf("\n\n");
    DFS(graph, 1);
    return 0;
}
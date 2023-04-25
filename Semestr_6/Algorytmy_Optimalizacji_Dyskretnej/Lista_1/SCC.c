#include"SCC.h"

DFS_SCC(graph, s, visited, stack){}
    visited[s] = true
    for each neighbor v of s in graph:
        if visited[v] == false:
            addPred(graph, v, s)
            DFS_SCC(graph, v, visited, stack)
    push stack, s

SCC(graph):
    n = graph.v
    visited[n]
    stack = createStack()
    for i in 0 to n:
        if visited[i] == false:
            DFS_SCC(graph, i, visited, stack)
    R = createGraph(n, true)
    for i in 0 to n:
        for each neighbor v of i in graph:
            addEdge(R, v, i)
    visited[n]
    sccCount = 0
    while stack is not empty:
        s = pop(stack)
        if visited[s] == false:
            componentStack = createStack()
            DFS_SCC(R, s, visited, componentStack)
            print("Strongly Connected Component", sccCount + 1, ":", end=" ")
            count = 0
            while componentStack is not empty:
                v = pop(componentStack)
                print(v, end=" ")
                count = count + 1
            print("(size:", count, ")")
            sccCount = sccCount + 1
    free(stack)
    free(R)
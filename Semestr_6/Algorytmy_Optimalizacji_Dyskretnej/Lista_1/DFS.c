#include"DFS.h"

// sueue Section //


struct StackNode* newStackNode(int data) {
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->front = NULL;
    return s;
}

bool isStackEmpty(struct Stack* s) {
    return (s->front == NULL);
}

void pushStack(struct Stack* s, int data) {
    struct StackNode* temp = newStackNode(data);

    if (isStackEmpty(s)) {
        s->front = temp;
        return;
    }

    temp->next = s->front;
    s->front = temp;
}

int popStack(struct Stack* s){

    struct StackNode* temp;
    int data;
    if (isStackEmpty(s))
    {
        printf("The Stack is empty!");
        return -1;
    }
    temp = s->front;
    data = temp->data;
    s->front = s->front->next;
    free(temp);
    return data;
}

void printStack(struct Stack* s)
{
        printf("[");
        struct StackNode* temp = s->front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("]\n");
}

void DFS(struct Graph* graph, int s){
    int n = graph->v;
    int seen[n];
    int current,temp,listlenght;
    bool found = 0;
    struct Stack *stack = createStack();
    struct AdjListNode *crawl = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    if (s > n)
    {
        printf("%d is outside of the graph", s);
        return; 
    }
    seen[0] = s;
    listlenght = 1; // the lenght of the seen array
    pushStack(stack, s);
    //printStack(stack);
    addPred(graph, s, 0);
    while(!isStackEmpty(stack)){
        temp = current;
        current = popStack(stack);
        crawl = graph->array[current].head;
        while(crawl != NULL){
            for (int i = 0; i < listlenght; i++)
                if (seen[i] == crawl->dest){
                    found = 1;
                }
                if (found == 0)
                {
                    pushStack(stack, crawl->dest);
                    addPred(graph, crawl->dest, current);
                    seen[listlenght] = crawl->dest;
                    listlenght++;
                }else
                found = 0;
            crawl = crawl->next;
        }
    }
}

void DFScormen(struct Graph *graph, int start)
{
        /*
        int n = graph->v;
        for (int i = 0; i < n; i++)
        {
            
        }*/
            
}

void DFSvisit(struct Graph *graph, int u)
{

}


#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void push(Stack* stack, int value) {
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(Stack* stack) {
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

void dfsTraversal(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Stack stack;
    stack.top = -1;

    push(&stack, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&stack)) {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&stack, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    Graph graph;
    int numVertices, numEdges, sourceVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    initializeGraph(&graph, numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &sourceVertex);

    printf("DFS Traversal: ");
    dfsTraversal(&graph, sourceVertex);

    return 0;
}

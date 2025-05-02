#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6


struct Graph {
    int V;
    int **adjMatrix;
};


struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));

    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
    }

    return graph;
}


void addEdge(struct Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;  // Add directed edge u -> v
}


void DFS(int u, struct Graph* graph, int visited[], int stack[], int *top) {
    visited[u] = 1;  // Mark the node as visited

    
    for (int v = 0; v < graph->V; v++) {
        if (graph->adjMatrix[u][v] && !visited[v]) {
            DFS(v, graph, visited, stack, top);
        }
    }

    
    stack[*top] = u;
    (*top)++;  // Increment stack top
}


void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited nodes
    int stack[MAX_VERTICES];  // Stack to store the topological order
    int top = 0;

   
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            DFS(i, graph, visited, stack, &top);
        }
    }

    
    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
   
    struct Graph* graph = createGraph(MAX_VERTICES);

   
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

   
    topologicalSort(graph);

   
    for (int i = 0; i < MAX_VERTICES; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}

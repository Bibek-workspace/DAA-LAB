#include <stdio.h>
#include <limits.h>


#define V 5


int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}


void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}


void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Used to select the minimum weight edge
    int mstSet[V];  // To represent the set of vertices included in the MST


    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

 
    key[0] = 0;  // Starting from vertex 0
    parent[0] = -1;  // First node has no parent

    
    for (int count = 0; count < V - 1; count++) {
     

#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};


int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    return subsets[i].parent;
}


void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Union by rank to keep the tree flat
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // To store the MST
    int e = 0; 
    int i = 0; 

  
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

 
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }


    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

       
        if (x != y) {
            result[e++] = next;
            unionSets(subsets, x, y);
        }
    }

   
    printf("Minimum Spanning Tree (MST) edges:\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    
    kruskalMST(edges, V, E);

    return 0;
}

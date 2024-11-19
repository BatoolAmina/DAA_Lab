#include <stdio.h>
#include <limits.h>
#define MAX 100
int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void printMST(int parent[], int graph[MAX][MAX], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}
void primMST(int graph[MAX][MAX], int vertices) {
    int parent[MAX];  // Array to store the MST
    int key[MAX];     // Key values to pick the minimum weight edge
    int mstSet[MAX];  // To represent the set of vertices included in MST
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;      // First vertex included in MST
    parent[0] = -1;  // First node is always the root of the MST
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, vertices);
}
int main() {
    int vertices, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Minimum Spanning Tree (MST) using Prim's Algorithm:\n");
    primMST(graph, vertices);
    return 0;
}

Output:
Enter the number of vertices: 5
Enter the adjacency matrix (use 0 for no edge):
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Minimum Spanning Tree (MST) using Prim's Algorithm:
Edge 	Weight
0 - 1 	2
1 - 2 	3
0 - 3 	6
1 - 4 	5


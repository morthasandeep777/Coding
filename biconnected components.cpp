#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100 // Maximum number of vertices

// Stack to store visited edges
int stack[MAX][2];
int top = -1;

void push(int u, int v) {
    stack[++top][0] = u;
    stack[top][1] = v;
}

void pop(int *u, int *v) {
    *u = stack[top][0];
    *v = stack[top--][1];
}

// Graph structure
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX], parent[MAX], low[MAX], disc[MAX];
int timeCount = 0;

void findBCCUtil(int u, int n) {
    int children = 0; // Count of children in DFS Tree
    visited[u] = 1;
    disc[u] = low[u] = ++timeCount;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                push(u, v);
                
                findBCCUtil(v, n);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u])) {
                    printf("Biconnected component: ");
                    int x, y;
                    do {
                        pop(&x, &y);
                        printf("(%d - %d) ", x, y);
                    } while (x != u || y != v);
                    printf("\n");
                }
            } else if (v != parent[u] && disc[v] < low[u]) {
                low[u] = disc[v];
                push(u, v);
            }
        }
    }
}

// Function to find Biconnected Components
void findBCC(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        disc[i] = 0;
        low[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findBCCUtil(i, n);

            int x, y;
            if (top != -1) {
                printf("Biconnected component: ");
                while (top != -1) {
                    pop(&x, &y);
                    printf("(%d - %d) ", x, y);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Biconnected Components in the graph:\n");
    findBCC(n);

    return 0;
}

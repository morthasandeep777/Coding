#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}

// Breadth-First Traversal
void BFT(int n, int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    printf("Breadth-First Traversal: ");
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth-First Traversal
void DFT(int n, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFT(n, i);
        }
    }
}

void performDFT(int n, int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Depth-First Traversal: ");
    DFT(n, start);
    printf("\n");
}

int main() {
    int n, start;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &start);

    BFT(n, start);
    performDFT(n, start);

    return 0;
}

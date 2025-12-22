#include <stdio.h>

int graph[20][20], visited[20], n;

void BFS(int start) {
    int queue[20], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices (<=20): ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Invalid number of vertices\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex\n");
        return 0;
    }

    printf("BFS Traversal: ");
    BFS(start);
    printf("\n");

    return 0;
}

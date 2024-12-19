#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100 // Define a maximum queue size

int main() {
    int vertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    int visited[MAX_VERTICES] = {0}; // Initialize all vertices as not visited
    int queue[MAX_QUEUE_SIZE]; // Define a maximum size for the queue
    int front = 0, rear = 0;

    // Start BFS from vertex 2
    visited[2] = 1;
    queue[rear++] = 2;

    printf("Following is Breadth First Traversal (starting from vertex 2) \n");
    while (front != rear) {
        if (rear >= MAX_QUEUE_SIZE) { // Check for queue overflow
            printf("Queue overflow!\n");
            break; 
        }

        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");

    return 0;
}


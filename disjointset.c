#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int parent[MAX_SIZE];
int rank[MAX_SIZE];

// Function to initialize the disjoint set data structure
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the representative of the set containing x
int findSet(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = findSet(parent[x]); // Path compression
}

// Function to merge two sets using union-rank heuristic
void unionSets(int x, int y) {
    int xRoot = findSet(x);
    int yRoot = findSet(y);

    if (xRoot == yRoot) {
        return; // Already in the same set
    }

    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

int main() {
    int n, choice, x, y;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    while (1) {
        printf("\n1. Make Set\n2. Find Set\n3. Union\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to make a set: ");
                scanf("%d", &x);
                makeSet(x);
                break;
            case 2:
                printf("Enter the element to find its set: ");
                scanf("%d", &x);
                printf("Set of %d is %d\n", x, findSet(x));
                break;
            case 3:
                printf("Enter the two elements to union: ");
                scanf("%d %d", &x, &y);
                unionSets(x, y);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


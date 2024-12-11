#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* R;
    struct Node* L;
};

struct Node *header = NULL;

struct Node *createNode(int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->R = NULL;
    new_node->L = NULL;
    return new_node;
}

void insertAtFront(int data) {
    struct Node *new_node = createNode(data);

    if (header == NULL) {
        header = new_node;
    } else {
        new_node->R = header;
        header->L = new_node;
        header = new_node;
    }
}

void printList() {
    struct Node *ptr = header;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->R;
    }
    printf("\n");
}

int main() {
    insertAtFront(10);
    insertAtFront(20);

    printList();

    return 0;
}

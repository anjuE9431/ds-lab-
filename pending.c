
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning
void insertFront(int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

// Function to insert a node at the end
void insertEnd(int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
}

// Function to delete a node from the beginning
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) { // Only one node
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->prev->next = NULL;
    free(last);
}

// Function to print the list
void printList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at End\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                printList();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Define a node structure to represent each element in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int data, choice;

    do {
        printf("Enter data to insert at the end of the list: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);

        printf("Do you want to continue inserting? (1 - Yes, 0 - No): ");
        scanf("%d", &choice);
    } while (choice != 0);

    printf("Linked List: ");
    displayList(head);

    return 0;
}

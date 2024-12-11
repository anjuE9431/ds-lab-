#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}

// Function to delete the first node from the list
void deleteAtFront(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head_ref; // Store current head
    *head_ref = (*head_ref)->next; // Move head to next node
    free(temp); // Free memory of old head
}

// Function to print linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to drive the program
int main() {
    struct Node* head = NULL;
    
    int choice, value;

    do {
        printf("\nMenu:\n1. Insert at End\n2. Delete at Front\n3. Display List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 2:
                deleteAtFront(&head);
                break;

            case 3:
                printList(head);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
        
    } while (choice != 4);

    // Free remaining nodes before exiting
    while (head != NULL) {
        deleteAtFront(&head);
    }

    return 0;
}

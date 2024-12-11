#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node{data, head};
    head = newNode;
}

int main() {
    Node* head = NULL; // initialize an empty linked list
    insertAtBeginning(head, 10); // insert a node with data 10
    insertAtBeginning(head, 20); // insert a node with data 20
    insertAtBeginning(head, 30); // insert a node with data 30

    // print the linked list
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        std::cout << curr->data << " ";
    }
    // expected output: 30 20 10 

    return 0;
}

#include<stdio.h> 
#include <stdlib.h>


struct Node {
    int data;               
    struct Node* next;   
};


struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data;  
    new_node->next = NULL;      
    return new_node;           
}


void traverseList(struct Node* head) {
    while (head != NULL) {    
        printf("%d ", head->data); 
        head = head->next;      
    }
    printf("\n");               
}


int main() {
    
    struct Node* head = createNode(10);        
    head->next = createNode(20);             
    head->next->next = createNode(30);      
    head->next->next->next = createNode(40);    

    printf("Traversal of Singly Linked List:\n");
    traverseList(head);                           

    return 0;                                    
}

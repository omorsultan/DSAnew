#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to the next node
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = data;    // Assign data to the node
    newNode->next = NULL;    // Initialize the next pointer as NULL
    return newNode;
}
// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {    // If list is empty, make new node the head
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;    // Link last node to the new node
}
// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;   // Initialize head of the list

    // Insert nodes into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    // Display the linked list
    displayList(head);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int key;
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create a new list node
void create_list(int key, int data) {
    struct node *link;
    link = (struct node *)malloc(sizeof(struct node));

    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

// Function to print the linked list
void print_list() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("(%d %d)\n", ptr->key, ptr->data);
        ptr = ptr->next;
    }
}

// Function to delete the first node
void delete_first() {
    if (head == NULL) {
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);  // Free memory of deleted node
}

// Function to delete a node by its key
void delete_by_key(int key) {
    struct node *current = head;
    struct node *previous = NULL;

    if (head == NULL) {
        return;
    }

    // Traverse the list to find the node to delete
    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // Key not found in the list
        printf("Key %d not found.\n", key);
        return;
    }

    if (current == head) {
        // Deleting the head node
        head = head->next;
    } else {
        // Bypass the current node
        previous->next = current->next;
    }

    free(current);  // Free memory of deleted node
}

// Function to insert a node between nodes with a specific key
void insert_between_keys(int key, int new_key, int new_data) {
    struct node *current = head;

    // Traverse the list to find the node with the specified key
    while (current != NULL && current->key != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found for insertion.\n", key);
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = new_key;
    new_node->data = new_data;

    // Insert the new node after the current node
    new_node->next = current->next;
    current->next = new_node;
}

// Function to reverse the linked list
void reverse_list() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    create_list(1, 11);
    create_list(2, 21);
    create_list(3, 71);
    create_list(7, 55);
    create_list(9, 11);
    create_list(0, 73);

    printf("Original List:\n");
    print_list();

    delete_first();
    printf("After deleting the first node:\n");
    print_list();

    insert_between_keys(3, 5, 83);
    printf("After inserting node (5, 83) after key 3:\n");
    print_list();

    delete_by_key(3);
    printf("After deleting node with key 3:\n");
    print_list();

    reverse_list();
    printf("After reversing the list:\n");
    print_list();

    return 0;
}

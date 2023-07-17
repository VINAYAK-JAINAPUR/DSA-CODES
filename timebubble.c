#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insertSort(struct Node** head_ref) {
    struct Node* sorted = NULL;
    struct Node* current = *head_ref;
    while (current != NULL) {
        struct Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head_ref = sorted;
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int random_num = rand() % 100;
        insertNode(&head, random_num);
    }
    printf("Linked list before sorting:\n");
    printList(head);
    insertSort(&head);
    printf("Linked list after sorting:\n");
    printList(head);
    return 0;
}

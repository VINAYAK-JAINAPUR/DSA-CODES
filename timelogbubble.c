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

void saveList(struct Node* node, char* filename) {
    FILE* fp = fopen(filename, "w");
    while (node != NULL) {
        fprintf(fp, "%d\n", node->data);
        node = node->next;
    }
    fclose(fp);
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    struct Node* head = NULL;
    int numNodes = 100;
    srand(time(NULL));
    for (int i = 0; i < numNodes; i++) {
        int randNum = rand() % 10;
        insertNode(&head, randNum);
    }
    printf("Linked list before sorting:\n");
    printList(head);
    start = clock();
    insertSort(&head);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Linked list after sorting:\n");
    printList(head);
    printf("Time taken by insertion sort: %f seconds\n", cpu_time_used);
    saveList(head, "sorted_list.txt");
    return 0;
}

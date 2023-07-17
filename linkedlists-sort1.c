#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
int main() {
    struct node* head = NULL;
    int n, data;
    printf("Enter number of elements in linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the elements:- ", i+1);
        scanf("%d", &data);
        addNode(&head, data);
    }
    printList(head);
    bubbleSort(&head);
    printList(head);

    return 0;
}

void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}
void printList(struct node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void bubbleSort(struct node** head) {
    int swapped, i;
    struct node* ptr1;
    struct node* lptr = NULL;
    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


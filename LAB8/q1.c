// remove duplicate node from an  unsorted Linklist

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        struct Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                struct Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(20);

    printf("Original list:\n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}


// rotate ll k times  to right
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    r
    tail->next = head;

    k = k % length;
    int stepsToNewTail = length - k;
    Node* newTail = tail;
    while (stepsToNewTail--) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 2;

    printf("Original list:\n");
    printList(head);

    head = rotateRight(head, k);

    printf("List after rotating right by %d:\n", k);
    printList(head);

    return 0;
}
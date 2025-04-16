// IMPLEMENT QUEUE USING SINGLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
void init(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! (Empty queue)\n");
        return -1;
    }

    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}
void display(struct Queue* q) {
    struct Node* temp = q->front;
    if (!temp) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}

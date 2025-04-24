#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Define queue structure
typedef struct {
    int items[SIZE];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Enqueue element
void enqueue(Queue *q, int value) {
    if (q->rear < SIZE - 1) {
        q->items[++(q->rear)] = value;
    } else {
        printf("Queue overflow\n");
    }
}

// Dequeue element
int dequeue(Queue *q) {
    if (q->front <= q->rear) {
        return q->items[(q->front)++];
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

// Function to convert decimal to binary using queue
void decimalToBinary(int decimal) {
    Queue q;
    initQueue(&q);

    // Edge case for 0
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Store remainders in queue
    while (decimal > 0) {
        enqueue(&q, decimal % 2);
        decimal /= 2;
    }

    // Print in reverse order (using stack-like behavior)
    printf("Binary: ");
    for (int i = q.rear; i >= q.front; i--) {
        printf("%d", q.items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    return 0;
}

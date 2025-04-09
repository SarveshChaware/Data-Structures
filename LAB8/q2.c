#include <stdio.h>
#include <stdlib.h>

struct TwoStacks {
    int* arr;
    int top1;
    int top2;
    int size;
};

void init(struct TwoStacks* ts, int size) {
    ts->size = size;
    ts->arr = (int*)malloc(size * sizeof(int));
    ts->top1 = -1;
    ts->top2 = size;
}

// Push to Stack 1
void push1(struct TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = value;
    } else {
        printf("Stack Overflow in Stack 1!\n");
    }
}

// Push to Stack 2
void push2(struct TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = value;
    } else {
        printf("Stack Overflow in Stack 2!\n");
    }
}

int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        return ts->arr[ts->top1--];
    } else {
        printf("Stack Underflow in Stack 1!\n");
        return -1;
    }
}

int pop2(struct TwoStacks* ts) {
    if (ts->top2 < ts->size) {
        return ts->arr[ts->top2++];
    } else {
        printf("Stack Underflow in Stack 2!\n");
        return -1;
    }
}
void freeStacks(struct TwoStacks* ts) {
    free(ts->arr);
}

int main() {
    struct TwoStacks ts;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    init(&ts, size);

    push1(&ts, 10);
    push1(&ts, 20);
    push2(&ts, 100);
    push2(&ts, 200);

    printf("Pop from Stack 1: %d\n", pop1(&ts));  // 20
    printf("Pop from Stack 2: %d\n", pop2(&ts));  // 200
    printf("Pop from Stack 1: %d\n", pop1(&ts));  // 10
    printf("Pop from Stack 2: %d\n", pop2(&ts));  // 100

    freeStacks(&ts);
    return 0;
}

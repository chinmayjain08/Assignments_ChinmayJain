#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10001

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return -1;
    }
    return q->arr[q->front++];
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return -1;
    }
    return q->arr[q->front];
}


typedef struct {
    Queue q1, q2;
} Stack;


void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}


void push(Stack* s, int value) {
    enqueue(&s->q1, value);
}


void pop(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return;
    }

    while (s->q1.front < s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    dequeue(&s->q1);

    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int top(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }

    while (s->q1.front < s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    int topElement = front(&s->q1);
    enqueue(&s->q2, dequeue(&s->q1));

    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return topElement;
}

int size(Stack* s) {
    return (isEmpty(&s->q1)) ? 0 : (s->q1.rear - s->q1.front + 1);
}

void printStack(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = s->q1.rear; i >= s->q1.front; i--) {
        printf("%d ", s->q1.arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    int choice, value, n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("1. Push\n2. Pop\n3. Top\n4. Print stack\n5. Stack size\n");

    for (int i = 0; i < n; i++) {
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                printf("Top element: %d\n", top(&s));
                break;
            case 4:
                printStack(&s);
                break;
            case 5:
                printf("Stack size: %d\n", size(&s));
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
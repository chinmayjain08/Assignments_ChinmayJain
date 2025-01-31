#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack1[MAX_SIZE], stack2[MAX_SIZE];
int top1 = -1, top2 = -1;

void push(int stack[], int *top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = value;
}


int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return stack[(*top)--];
}


int peek(int stack[], int top) {
    if (top == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return stack[top];
}

// QUEUE OPERATIONS using stacks 

//enqueue (O(1))
void enqueue(int value) {
    printf("%d enqued\n", value);
    push(stack1, &top1, value);
}

//dequeue (O(n))
void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push(stack2, &top2, pop(stack1, &top1));
        }
    }
    
    printf("%d dequed\n", stack2[top2]);
    pop(stack2, &top2);
}

//front element of queue (O(n))
int front() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push(stack2, &top2, pop(stack1, &top1));
        }
    }

    return peek(stack2, top2);
}

//queue size (O(1))
int sizeQueue() {
    return (top1 + 1) + (top2 + 1);
}

//print queue elements (O(n))
void printQueue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    
    printf("\n");
}


int main() {
    int choice, value, n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Print queue\n5. Queue size\n");

    for (int i = 0; i < n; i++) {
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Front element: %d\n", front());
                break;
            case 4:
                printQueue();
                break;
            case 5:
                printf("Queue size: %d\n", sizeQueue());
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

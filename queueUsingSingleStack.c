#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum size of stack

int stack[MAX];  
int top = -1;    

//push
void push(int data) {
    if (top == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    stack[++top] = data;
}

//pop
int pop() {
    if (top == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return stack[top--];
}

//dequeue (removes front element)
int dequeueRecursive() {
    if (top == 0) {
        return pop();
    }
    
    int temp = pop();
    int frontElement = dequeueRecursive();
    push(temp);
    
    return frontElement;
}

//get front element (without removing)
int getFrontRecursive() {
    if (top == 0) {
        return stack[top];
    }
    
    int temp = pop();
    int frontElement = getFrontRecursive();
    push(temp);
    
    return frontElement;
}

//enqueue operation
void enqueue(int data) {
    printf("Enqueued %d\n", data);
    push(data);
}

//dequeue operation
void dequeue() {
    if (top == -1) {
        printf("Queue is empty\n");
        return;
    }
    int front = dequeueRecursive();
    printf("Dequeued: %d\n", front);
}

//front element
void getFront() {
    if (top == -1) {
        printf("Queue is empty\n");
        return;
    }
    int front = getFrontRecursive();
    printf("Front element: %d\n", front);
}

//size of queue
int size() {
    return top + 1;
}


void printQueue() {
    if (top == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main() {
    int choice, data, ops;

    printf("Enter number of operations: ");
    scanf("%d", &ops);

    printf("1. Enqueue\n2. Dequeue\n3. Get Front\n4. Print Queue\n5. Get Size\n");

    for (int i = 0; i < ops; i++) {
        printf("Choose an operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                getFront();
                break;
            case 4:
                printQueue();
                break;
            case 5:
                printf("Size of queue: %d\n", size());
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

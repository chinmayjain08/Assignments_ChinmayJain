#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

int stack1[MAX_SIZE], stack2[MAX_SIZE];
int top1 = -1, top2 = -1;

void push(int stack[], int data, int* top){
    if(*top == MAX_SIZE-1){
        printf("queue is full\n");
        return;
    }
    stack[++(*top)] = data;
    return;
}

int pop(int stack[], int* top){
    if(*top == -1){
        printf("queue empty\n");
        return -1;
    }
    return stack[(*top)--];
}

void enqueue(int data){
    if(top1 == -1){
        push(stack1,data, &top1);
        return;
    }
    while(top1 != -1){
        push(stack2, pop(stack1,&top1), &top2);
    }
    push(stack1,data,&top1);
    while(top2 != -1){
        push(stack1, pop(stack2,&top2), &top1);
    }
    return;
}

void dequeue(){
    if(top1 == -1){
        printf("queue empty\n");
        return;
    }
    pop(stack1, &top1);
    return;
}

void printQueue(){
    if(top1 == -1 && top2 == -1){
        printf("queue empty\n");
        return;
    }
    for(int i=top1; i>=0; i--){
        printf("%d ", stack1[i]);
    }
    printf("\n");
    return;
}

void getFront(){
    if(top1 == -1){
        printf("queue empty\n");
        return;
    }
    printf("front : %d\n", stack1[top1]);
    return;
}

void sizeQueue(){
    printf("size: %d\n", top1+1);
    return;
}

int main(){

    int choice, data, ops;

    printf("Enter number of operations: ");
    scanf("%d", &ops);

    printf("1. Enqueue\n2. Dequeue\n3. Front of Queue\n4. Size of Queue\n5. Print Queue\n");

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
                sizeQueue();
                break;
            case 5:
                printQueue();
                break;
            default:
                printf("Invalid choice\n");
        }
    }


    return 0;
}
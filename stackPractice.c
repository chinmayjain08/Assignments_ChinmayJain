#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int top;
    int capacity;
    int* array;
    int front;
}Stack;

void initStack(Stack* stack, int capacity){
    stack->top = -1;
    stack->front = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1 || stack->front > stack->top;
}

void push(Stack* stack, int data){
    if(isEmpty(stack)){
        stack->front++;
    }
    if(isFull(stack)){
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    int pop = stack->array[stack->top--];
    if(stack->top < stack->front){
        initStack(stack, stack->capacity);
    }
}

int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

int dequeue(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    int deleted = stack->array[stack->front++];
    if(stack->front > stack->top){
        initStack(stack, stack->capacity);
    }
}

void printStack(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    for(int i=stack->front; i<=stack->top; i++){
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack, 5);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    printStack(&stack);
    
    return 0;
}
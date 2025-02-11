#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int top;
    int arr[10001];
    int front;
}Stack;

Stack* createStack(){
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = -1;
    return newStack;
}

void push(Stack* stack, int data){
    if(stack->top == -1){
        stack->front = 0;
    }
    stack->arr[++stack->top] = data;
    return;
}

int pop(Stack* stack){
    if(stack->top == -1){
        printf("stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int dequeue(Stack* stack){
    if(stack->top == -1){
        printf("stack is empty\n");
        return -1;
    }
    if(stack->front > stack->top){
        stack = createStack();
        printf("stack is empty\n");
        return -1;
    }
    if(stack->front == stack->top){
        stack->top--;
    }
    return stack->arr[stack->front++];
}

void printStack(Stack* stack){
    if(stack->top == -1){
        printf("stack is empty\n");
        return;
    }
    for(int i=stack->front; i<=stack->top; i++){
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
    return;
}

int main(){

    Stack* stack = createStack();
    int ops;
    printf("Enter number of operations: ");
    scanf("%d", &ops);
    printf("1. push LIFO\n");
    printf("2. pop LIFO\n");
    printf("3. dequeue FIFO\n");
    int data, choice;
    for(int i=0; i<ops; i++){
        printf("enter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter data to push\n");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                int popped = pop(stack);
                if(popped != -1){
                    printf("%d popped from stack\n", popped);   
                }
                break;
            case 3:
                int deleted = dequeue(stack);
                if(deleted != -1){
                    printf("%d deleted from stack\n", deleted);
                }
                break;
            case 4:
                printStack(stack);
                break;
            default:
                printf("invaid choice\n");
                break;
        }
    }
    return 0;
}
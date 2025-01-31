#include<stdio.h>
#include<stdlib.h>

void push(int* stack, int* top, int data){
    stack[++(*top)] = data;
    return;
}

void pop(int *stack, int* top){
    if(*top == -1){
        return;
    }
    (*top)--;
    return;
}

int peek(int* stack, int top){
    if(top == -1){
        return -1;
    }
    return stack[top];
}


void printStack(int* stack, int top){
    printf("elements of stack : \n");
    for(int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void removeMiddleElement(int* stack, int* top, int* pos, int* mid){
    if(*pos == 1){
        pop(stack, top);
        return;
    }

    (*pos)--;
    int temp = peek(stack, *top);
    pop(stack, top);

    removeMiddleElement(stack, top, pos, mid);

    push(stack, top, temp);
}

void removeMid(int* stack, int* top, int size){
    if(size == 0){
        printf("empty stack");
        return;
    }
    int pos = size/2 + 1;
    int mid = -1;
    removeMiddleElement(stack, top, &pos, &mid);
    return;
}

int main(){

    int size;
    printf("enter size of stack : ");
    scanf("%d", &size);

    int stack[size];
    int top = -1;

    int data;
    printf("enter values to push in stack\n");
    for(int i=0; i<size; i++){
        scanf("%d", &data);
        push(stack, &top, data);
    }

    printStack(stack, top);
    printf("after removal of mid element : \n");
    removeMid(stack, &top, size);
    printStack(stack, top);

    return 0;
}
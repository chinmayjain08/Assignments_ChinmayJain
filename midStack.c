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

void middleElement(int* stack, int* top, int* pos, int* mid){
    if(*pos == 1){
        *mid = peek(stack, *top);
        return;
    }

    (*pos)--;
    int temp = peek(stack, *top);
    pop(stack, top);

    middleElement(stack, top, pos, mid);

    push(stack, top, temp);
}

int getMid(int* stack, int* top, int size){
    if(size == 0)return -1;
    int pos = size/2 + 1;
    int mid = -1;
    middleElement(stack, top, &pos, &mid);
    return mid;
}

int main(){

    int size;
    printf("enter size of stack\n");
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

    int ans = getMid(stack, &top, size);
    if(ans != -1){
        printf("mid element : %d\n", ans);
    }else{
        printf("no mid element\n");
    }    

    return 0;
}
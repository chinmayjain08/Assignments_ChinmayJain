#include<stdio.h>
#include<stdlib.h>


int stack[1000001];
int top = -1;

void push(int data){
    stack[++top] = data;
    printf("%d pushed to stack\n", data);
    return;
}

void pop(){
    if(top == -1){
        printf("stack empty\n");
        return;
    }
    printf("%d popped out from stack\n", stack[top]);
    top--;
    return;
}

void peek(){
    if(top == -1){
        printf("stack empty\n");
    }else{
        printf("top element of stack : %d", stack[top]);
    }
    return;
}


void printStack(){
    printf("elements of stack : \n");
    for(int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main(){

    printf("enter number of operations to perform : ");
    int operations;
    scanf("%d", &operations);

    printf("1. push data to stack\n");
    printf("2. pop value out of stack\n");
    printf("3. get top element of stack\n");
    printf("4. print elements of stack\n");
    int option, data;
    
    for(int i=0; i<operations; i++){
        printf("choose option for operation to perform on stack : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter value to push in stack : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printStack();
            break;
        default:
            break;
        }
    }

    return 0;
}
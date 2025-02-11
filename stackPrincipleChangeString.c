#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    char** names;
    int top;
    int front;
}Stack;

void initStack(Stack* stack){
    stack->names = (char**)malloc(1001 * sizeof(char*));
    stack->top = -1;
    stack->front = -1;
}

void push(Stack* stack, char name[]){
    if(stack->front == -1){
        stack->front++;
    }
    stack->names[++stack->top] = strdup(name);
    return;
}

void pop(Stack* stack){
    if(stack->top == -1 || stack->front > stack->top){
        printf("no names\n");
        return;
    }
    printf("%s popped from stack\n", stack->names[stack->top--]);
    if(stack->front > stack->top){
        initStack(stack);
    }
    return;
}

void deleteFIFO(Stack* stack){
    if(stack->top == -1 || stack->front > stack->top){
        printf("no names\n");
        return;
    }
    printf("%s deleted from stack\n", stack->names[stack->front++]);
    if(stack->front > stack->top){
        initStack(stack);
    }
    return;
}

void printStack(Stack* stack){
    if(stack->top == -1 || stack->front > stack->top){
        printf("no names\n");
        return;
    }
    for(int i=stack->top; i>=stack->front; i--){
        printf("%s\n", stack->names[i]);
    }
}

int main() {
    
    int ops;
    printf("operations : ");
    scanf("%d", &ops);
    
    Stack stack;
    initStack(&stack);
    
    int choice;
    char name[100];
    for(int i=0; i<ops; i++){
        printf("choice : ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
        case 1:
            printf("enter name : ");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = '\0';
            push(&stack, name);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            deleteFIFO(&stack);
            break;
        case 4:
            printStack(&stack);
            break;
        }
    }

    return 0;
}
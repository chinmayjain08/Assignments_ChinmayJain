#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    char** arr;
    int top;
}Stack;

void initStack(Stack* stack){
    stack->arr = (char**)malloc(1001 * (sizeof(char*)));
    stack->top = -1;
    return;
}

void push(Stack* stack, char url[]){
    stack->arr[++stack->top] = strdup(url);
    return;
}

char* pop(Stack* stack){
    if(stack->top == -1){
        printf("empty history\n");
        return "";
    }
    return stack->arr[stack->top--];
}

// void printStack(Stack* stack){
//     if(stack->top == -1){
//         printf("empty history\n");
//         return;
//     }
//     for(int i=stack->top; i>=0; i--){
//         printf("%s\n", stack->arr[i]);
//     }
//     return;
// }

void back(Stack* stack, Stack* auxStack){
    if(stack->top == -1){
        printf("no going back\n");
        return;
    }
    push(auxStack, pop(stack));
    printf("url : %s\n", stack->arr[stack->top]);
    return;
}

void forth(Stack* stack, Stack* auxStack){
    if(auxStack->top == -1){
        printf("no way forward\n");
        return;
    }
    push(stack, pop(auxStack));
    printf("url : %s\n", stack->arr[stack->top]);
    return;
}

void printUrls(Stack* stack, Stack* auxStack){
    if(stack->top == -1 && auxStack->top == -1){
        printf("no urls\n");
        return;
    }
    for(int i=0; i<=auxStack->top; i++){
        printf("%s\n", auxStack->arr[i]);
    }
    for(int i=stack->top; i>=0; i--){
        printf("%s\n", stack->arr[i]);
    }
    return;
}


int main() {
    
    int ops;
    printf("enter number of operations : ");
    scanf("%d", &ops);
    
    Stack stack;
    initStack(&stack);
    
    Stack auxStack;
    initStack(&auxStack);
    
    char url[100] = "";
    int choice;
    
    for(int i=0; i<ops; i++){
        printf("enter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter url\n");
                scanf("%s", url);
                push(&stack, url);
                break;
            case 2:
                printUrls(&stack, &auxStack);
                break;
            case 3:
                back(&stack, &auxStack);
                break;
            case 4:
                forth(&stack, &auxStack);
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    }

    return 0;
}
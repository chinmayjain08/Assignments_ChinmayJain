#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    char* states[100001];
    int top;
}Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* st, char* str){
    st->top++;
    st->states[st->top] = (char*)malloc(strlen(str) + 1);
    strcpy(st->states[st->top],str);
}

char* pop(Stack* st){
    char* prevState = st->states[st->top];
    st->top--;
    return prevState;
}

int main(){
    printf("enter number of operations: ");
    int ops;
    scanf("%d", &ops);
    int choice, k;
    Stack st;
    initStack(&st);
    push(&st, "");
    char s[10001] = "";
    char w[10001];
    char* prevState = "";

    for(int i=0; i<ops; i++){
        printf("enter choice : ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("enter string to append: ");
            //push curr state to stack
            push(&st, s);
            scanf("%s", w);
            strcat(s,w);
            printf("%s\n", s);
            break;
        case 2:
            printf("enter no. of char to remove: ");
            scanf("%d", &k);
            //push curr state to stack
            push(&st, s);
            s[strlen(s)-k] = '\0';
            printf("%s\n", s);
            break;
        case 3:
            printf("char to display: ");
            scanf("%d", &k);
            printf("%c\n", s[k - 1]);
            break;
        case 4:
            prevState = pop(&st);
            strcpy(s, prevState);
            printf("UNDO done\n%s\n", s);
            free(prevState);
        default:
            break;
        }
    }

    return 0;
}


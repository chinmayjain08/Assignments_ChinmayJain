#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// defining structure for stack implementation
typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

// function to initialize stack
void initialize(Stack *st)
{
    st->top = -1;
}

// function to push values to the stack
void push(Stack *st, int val)
{
    if (st->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow");
        return;
    }

    st->arr[++st->top] = val;
}

// function to pop values out of the stack
int pop(Stack *st)
{
    if (st->top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }

    int val = st->arr[st->top--];
    return val;
}

// function to check a char is an operator or not
int isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        return 1;
    }
    return 0;
}

int isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}

int operatorPrecedence(char op)
{
    if (op == '/' || op == '*')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}

void infixToPostfix(char *exp, char *postfix)
{
    Stack opStack;
    //operator stack
    initialize(&opStack);
    int k = 0;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == ' ')
            continue;

        //operand
        if (isDigit(exp[i]))
        {
            while (isDigit(exp[i]))
            {
                postfix[k++] = exp[i++];
            }
            postfix[k++] = ' ';
            i--;
        }

        //operator
        else if (isOperator(exp[i])){
            while (opStack.top != -1 && operatorPrecedence(opStack.arr[opStack.top]) >= operatorPrecedence(exp[i])){
                postfix[k++] = pop(&opStack);
                postfix[k++] = ' ';
            }
            push(&opStack, exp[i]);
        }
        else{
            printf("Invalid  Expression \n");
            exit(EXIT_FAILURE);
        }
    }

    // pop remaining operators out of stack
    while (opStack.top != -1)
    {
        postfix[k++] = pop(&opStack);
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
}

int evalPostfix(char *postfix)
{
    Stack opStack;
    initialize(&opStack);

    for (int i = 0; postfix[i]; i++)
    {
        if (isDigit(postfix[i])){
            int num = 0;
            while (isDigit(postfix[i])){
                num = num*10 + (postfix[i]-'0');
                i++;
            }
            i--;
            push(&opStack, num);
        }
        else if (isOperator(postfix[i])){
            if (opStack.top < 1){
                printf("Error: Invalid Postfix Expression \n");
                exit(EXIT_FAILURE);
            }
            int b = pop(&opStack);
            int a = pop(&opStack);

            switch (postfix[i])
            {
            case '+':
                push(&opStack, a+b);
                break;
            case '-':
                push(&opStack, a-b);
                break;
            case '*':
                push(&opStack, a*b);
                break;
            case '/':
                if (b == 0){
                    printf("Error: Division by ZERO \n");
                    exit(EXIT_FAILURE);
                }
                push(&opStack, a / b);
                break;
            }
        }
    }

    return pop(&opStack);
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("enter a mathematical expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("result of given expression : %d", evalPostfix(postfix));

    return 0;
}
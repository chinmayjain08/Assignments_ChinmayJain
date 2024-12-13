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
    int postIndex = 0;

    for (int index = 0; exp[index] != '\0'; index++)
    {
        if (exp[index] == ' ')
            continue;

        //operand
        if (isDigit(exp[index]))
        {
            while (isDigit(exp[index]))
            {
                postfix[postIndex++] = exp[index++];
            }
            postfix[postIndex++] = ' ';
            index--;
        }

        //operator
        else if (isOperator(exp[index])){
            while (opStack.top != -1 && operatorPrecedence(opStack.arr[opStack.top]) >= operatorPrecedence(exp[index])){
                postfix[postIndex++] = pop(&opStack);
                postfix[postIndex++] = ' ';
            }
            push(&opStack, exp[index]);
        }
        else{
            printf("Invalid  Expression \n");
            return;
        }
    }

    // pop remaining operators out of stack
    while (opStack.top != -1)
    {
        postfix[postIndex++] = pop(&opStack);
        postfix[postIndex++] = ' ';
    }

    postfix[postIndex] = '\0';
}

int evalPostfix(char *postfix)
{
    Stack opStack;
    initialize(&opStack);

    for (int index = 0; postfix[index]; index++)
    {
        if (isDigit(postfix[index])){
            int num = 0;
            while (isDigit(postfix[index])){
                num = num*10 + (postfix[index]-'0');
                index++;
            }
            index--;
            push(&opStack, num);
        }
        else if (isOperator(postfix[index])){
            if (opStack.top < 1){
                printf("Error: Invalid Postfix Expression \n");
                return -1;
                //signify error
            }
            int opr2 = pop(&opStack);
            int opr1 = pop(&opStack);

            switch (postfix[index])
            {
            case '+':
                push(&opStack, opr1+opr2);
                break;
            case '-':
                push(&opStack, opr1-opr2);
                break;
            case '*':
                push(&opStack, opr1*opr2);
                break;
            case '/':
                if (opr2 == 0){
                    printf("Error: Division by ZERO \n");
                    return -1;
                    //signify error
                }
                push(&opStack, opr1 / opr2);
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
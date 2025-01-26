#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void pop(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("%d popped out of stack\n", temp->data);
    free(temp);
    return;
}

void peek(){
    if(head == NULL){
        printf("no elements in stack\n");
        return;
    }
    printf("top element : %d\n", head->data);
    return;
}

void printStack(){
    if(head == NULL){
        printf("no elements in stack\n");
        return;
    }
    struct Node* temp = head;
    printf("stack : \n");
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return;
}

void isEmpty(){
    if(head == NULL){
        printf("stack empty\n");
        return;
    }
    printf("stack not empty\n");
    return;
}

int main(){

    printf("number of operations over stack : ");
    int opsNum;
    scanf("%d", &opsNum);

    for(int i=0; i<opsNum; i++){
        printf("\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. print Stack\n");
        printf("5. isEmpty\n");
        int op;
        printf("enter operation to perform : ");
        scanf("%d", &op);
        int data;
        switch(op){
            case 1:
                printf("enter data to push into stack : ");
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
            case 5:
                isEmpty();
                break;
            default:
                printf("invalid option\n");
                break;
        }
    }

    printf("end of program \n");

    return 0;
}
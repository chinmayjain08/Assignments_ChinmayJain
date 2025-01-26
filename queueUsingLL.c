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

void pull(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    if(head->next == NULL){
        struct Node* temp = head;
        printf("%d pulled out of queue\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("%d pulled out of queue\n", temp->data);
    free(temp);
    return;
}

void front(){
    if(head == NULL){
        printf("no elements in queue\n");
        return;
    }
    printf("front element : %d\n", head->data);
    return;
}

void printQueue(){
    if(head == NULL){
        printf("no elements in queue\n");
        return;
    }
    struct Node* temp = head;
    printf("queue : ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void isEmpty(){
    if(head == NULL){
        printf("queue empty\n");
        return;
    }
    printf("queue not empty\n");
    return;
}

int main(){

    printf("number of operations over queue : ");
    int opsNum;
    scanf("%d", &opsNum);
    printf("operations to perform : \n");
    printf("1. push\n");
    printf("2. pull\n");
    printf("3. front\n");
    printf("4. print queue\n");
    printf("5. isEmpty\n");
    for(int i=0; i<opsNum; i++){
        int op;
        printf("enter operation number to perform : ");
        scanf("%d", &op);
        int data;
        switch(op){
            case 1:
                printf("enter data to push into queue : ");
                scanf("%d", &data);
                push(data);
                printf("\n");
                break;
            case 2:
                pull();
                printf("\n");
                break;
            case 3:
                front();
                printf("\n");
                break;
            case 4:
                printQueue();
                printf("\n");
                break;
            case 5:
                isEmpty();
                printf("\n");
                break;
            default:
                printf("invalid option\n");
                printf("\n");
                break;
        }
    }

    printf("end of program\n");

    return 0;
}
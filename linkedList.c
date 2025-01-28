#include<stdio.h>
#include<stdlib.h>


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


int lengthLL(){
    struct Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


void insertAtEnd(int num){
    struct Node* newNode = createNode(num);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return;
}

void insertAtBeginning(int num){
    struct Node* newNode = createNode(num);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}


void insertAtPosition(int pos, int num){
    struct Node* newNode = createNode(num);
    int len = lengthLL();
    if(head == NULL && pos != 1){
        printf("invalid position\n");
        return;
    }else if(pos == 1){
        insertAtBeginning(num);
        return;
    }else if(pos == len+1){
        insertAtEnd(num);
        return;
    }else if(pos > len+1 || pos < 1){
        printf("invalid position\n");
        return;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    while(pos != 1){
        prev = curr;
        curr = curr->next;
        pos--;
    }
    prev->next = newNode;
    newNode->next = curr;
    return;
}

void display(){
    if(head == NULL){
        printf("no elements\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void updateAtPosition(int pos, int num){
    int len = lengthLL();
    if(head == NULL){
        printf("no elements to update\n");
        return;
    }
    if(pos == 1){
        head->data = num;
        return;
    }else if(pos > len || pos < 1){
        printf("invalid position\n");
        return;
    }
    struct Node* temp = head;
    while(pos != 1){
        temp = temp->next;
        pos--;
    }
    temp->data = num;
    return;
}

void deleteAtBeginning(){
    if(head == NULL){
        printf("no elements for deletion\n");
        return;
    }
    struct Node* temp = head->next;
    free(head);
    head = temp;
    return;
}

void deleteAtEnd(){
    if(head == NULL){
        printf("no elements to delete");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return;
}

void deleteAtPosition(int pos){
    int len = lengthLL();
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    if(pos == 1){
        deleteAtBeginning();
        return;
    }else if(pos == len){
        deleteAtEnd();
        return;
    }else if(pos > len || pos < 1){
        printf("invalid position\n");
        return;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    while(pos != 1){
        prev = curr;
        curr = curr->next;
        pos--;
    }
    prev->next = curr->next;
    free(curr);
    return;
}

void freeList(){
    struct Node* temp = head;
    while(temp != NULL){
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    return;
}

int main(){

    int noOfOperations;
    scanf("%d", &noOfOperations);
    int choice,num,pos;
    for(int i=0; i<noOfOperations; i++){
        scanf("%d", &choice);
        switch (choice){
        case 1:
            scanf("%d", &num);
            insertAtEnd(num);
            break;

        case 2:
            scanf("%d", &num);
            insertAtBeginning(num);
            break;

        case 3:
            scanf("%d %d", &pos, &num);
            insertAtPosition(pos, num);
            break;

        case 4:
            display();
            break;

        case 5:
            scanf("%d %d", &pos, &num);
            updateAtPosition(pos, num);
            break;

        case 6:
            deleteAtBeginning();
            break;

        case 7:
            deleteAtEnd();
            break;

        case 8:
            scanf("%d", &pos);
            deleteAtPosition(pos);  
            break;
  
        default:
            printf("invalid choice \n");
            break;
        }
    }
    freeList();
    return 0;
}

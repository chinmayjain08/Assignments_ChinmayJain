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

void printLL(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void addLast(int data){
    struct Node* newNode = createNode(data);
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

int lengthLL(struct Node* head){
    struct Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void deleteKthNodeFromEnd(struct Node** headRef, int k){
    struct Node* head = *headRef;
    int len = lengthLL(head);

    if(head == NULL){
        return;
    }
    
    if(head->next == NULL){
        head = NULL;
        return;
    }
    
    if(k == 0)return;
    if(k == len){
        struct Node* temp = head;
        *headRef = head->next;
        temp->next = NULL;
        free(temp);
        return;
    }
    int index = len-k+1;
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(index != 1){
        prev = temp;
        temp = temp->next;
        index--;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

int main() {
    
    int nums;
    printf("no. of elements: ");
    scanf("%d", &nums);
    
    int input;
    for(int i=0; i<nums; i++){
        scanf("%d", &input);
        addLast(input);
    }
    
    int k;
    printf("enter value for k: ");
    scanf("%d", &k);
    
    deleteKthNodeFromEnd(&head, k);
    printLL(head);

    return 0;
}
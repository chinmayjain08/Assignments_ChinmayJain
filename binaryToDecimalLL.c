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


int binaryToDecimal(struct Node* head){
    if(head == NULL)return 0;
    if(head->next == NULL)return head->data;
    int length = lengthLL(head);
    int decimalAns = 0;
    struct Node* temp = head;
    while(length != 0){
        if(temp->data != 0){
            for(int i=1; i<=length-1; i++){
                temp->data *= 2;
            }
            decimalAns += temp->data;
            
        }
        length--;
         temp = temp->next;
    }
    return decimalAns;
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
    
    int decimal = binaryToDecimal(head);
    printf("%d\n", decimal);

    return 0;
}
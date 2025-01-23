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

struct Node* getMid(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast!= NULL && fast->next != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    struct Node* midNode = slow;
    return midNode;
}

int main() {
    
    int elements;
    printf("enter no. of elements in linkedlist : ");
    scanf("%d", &elements);
    
    int num;
    for(int i=0; i<elements; i++){
        scanf("%d", &num);
        addLast(num);
    }
    
    printLL(head);
    
    struct Node* midNode = getMid(head);
    int middleElement = midNode->data;
    printf("middle element : %d\n", middleElement);

    return 0;
}
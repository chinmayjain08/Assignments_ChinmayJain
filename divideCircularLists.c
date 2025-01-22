#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* head = NULL;

void printCircularLL(struct Node* head){
    struct Node* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
}

struct Node* getMidNode(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        if(fast != NULL & fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

void printLL(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void giveTwoCircLists(struct Node* head, struct Node** head1, struct Node** head2){
    struct Node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next != head);
    temp->next = NULL;
    // printLL(head);
    *head1 = head;
    struct Node* midNode = getMidNode(head);
    *head2 = midNode->next;
    midNode->next = NULL;
    return;
}

int main(){
    
    head = createNode(1);
    struct Node* sec = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);
    struct Node* fifth = createNode(5);
    // struct Node* sixth = createNode(6);
    
    head->next = sec;
    sec->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;
    // sixth->next = head;
    
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    printCircularLL(head);
    printf("\n");
    giveTwoCircLists(head, &head1, &head2);
    
    printLL(head1);
    printLL(head2);
    
    return 0;
}
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
        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    struct Node* midNode = slow;
    return midNode;
}

struct Node* reverseLL(struct Node* head){
    if(head == NULL || head->next == NULL)return head;
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* nextNode = NULL;
    while(curr != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    return head;
}

struct Node* reorderLL(struct Node* head){
    struct Node* midNode = getMid(head);
    struct Node* head1 = head;
    struct Node* head2 = midNode->next;
    midNode->next = NULL;
    
    head2 = reverseLL(head2);
    
    struct Node* temp = head1;
    
    while(head1 != NULL && head2 != NULL){
        head1 = head1->next;
        temp->next = head2;
        temp = head2;
        head2 = head2->next;
        temp->next = head1;
        temp = head1;
    }
    
    return head;
}

int main(){
    
    int elements;
    printf("enter no. of elements in linkedlist : ");
    scanf("%d", &elements);
    
    int num;
    for(int i=0; i<elements; i++){
        scanf("%d", &num);
        addLast(num);
    }
    
    head = reorderLL(head);
    printLL(head);
    
    return 0;
}
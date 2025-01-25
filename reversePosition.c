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



struct Node* reverseLL(struct Node* head, int st, int end){
    if(head == NULL || head->next == NULL)
        return head;
        
    int diff = end - st + 1;
    
    struct Node* breakPoint = NULL;
    struct Node* start = head;
    while(st != 1){
        breakPoint = start;
        start = start->next;
        st--;
    }
    
    struct Node* curr = start;
    struct Node* prev = NULL;
    struct Node* nextNode = NULL;
    while(diff && curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        diff--;
    }
    
    start->next = curr;
    
    if(breakPoint != NULL){
        breakPoint->next = prev;
    }else{
        head = prev;
    }
    
    return head;
}

int main(){
    
    int elements;
    printf("enter no. of elements in linkedlist : ");
    scanf("%d", &elements);
    
    int start, end;
    printf("enter start and end index to reverse : ");
    scanf("%d %d", &start, &end);
    
    int num;
    for(int i=0; i<elements; i++){
        scanf("%d", &num);
        addLast(num);
    }
    
    head = reverseLL(head, start, end);
    printLL(head);
    
    return 0;
}
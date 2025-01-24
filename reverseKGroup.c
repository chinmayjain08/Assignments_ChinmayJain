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


struct Node* reverseKGroup(struct Node* head, int k){
    if(k==0)return head;
    int length = lengthLL(head);
    if(k > length)return head;
    
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* nextNode = NULL;
    int position = 0;
    while(curr != NULL && position < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        position++;
    }
    
    struct Node* recAns = NULL;
    if(nextNode != NULL){
        recAns = reverseKGroup(nextNode, k);
        head->next = recAns;
    }
    
    return prev;
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
    
    head = reverseKGroup(head, k);
    printLL(head);

    return 0;
}
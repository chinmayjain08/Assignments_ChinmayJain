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


struct Node* reverseInBetween(struct Node* head, int st, int en){
    if(head == NULL || st>=en){
        return head;
    }
    struct Node* dummy = createNode(0);
    struct Node* prevN = dummy;
    prevN->next = head;

    struct Node* temp = head;
    int diff = en-st+1;
    
    while(st != 1){
        if (!temp) {
            free(dummy);
            return head;
        }
        prevN = temp;
        temp = temp->next;
        st--;
    }
    struct Node* curr = temp;
    struct Node* prev = NULL;
    struct Node* nextNode = NULL;

    while(diff > 0){
        if(!curr) break;
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        diff--;
    }
    
    prevN->next = prev;
    temp->next = curr;
    struct Node* result = dummy->next;
    free(dummy);
    return result;
}


void printLL(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    int num;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        int data;
        scanf("%d", &data);
        addLast(data);
    }

    printf("enter indices for reversal : ");
    int st, en;
    scanf("%d %d", &st, &en);
    head = reverseInBetween(head, st, en);

    printLL(head);

    return 0;
}
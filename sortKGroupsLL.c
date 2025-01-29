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

int lengthLL(){
    struct Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
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

struct Node* sortLLDesc(struct Node* head){
    if(head == NULL || head->next == NULL) return head;
    struct Node* i = head;
    while(i != NULL){
        struct Node* j = head;
        while(j->next != NULL){
            if(j->data < j->next->data){
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}

void sortDescInKGroups(int k){
    if(head == NULL || head->next == NULL) return;
    if(k == 1) return;
    if(k == lengthLL()){
        head  = sortLLDesc(head);
        return;
    }
    if(k > lengthLL()){
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    struct Node* prevNode = NULL;
    while(temp != NULL){
        prevNode = temp;
        for(int i=0; i<k && temp != NULL; i++){
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL) return;

        struct Node* nextNode = temp;
        prev->next = NULL;

        prevNode = sortLLDesc(prevNode);

        while(prevNode->next != NULL){
            prevNode = prevNode->next;
        }

        prevNode->next = nextNode;
        temp = nextNode;
    }
    return;
}

int main(){

    int nums;
    printf("no. of elements: ");
    scanf("%d", &nums);
    
    int input;
    for(int i=0; i<nums; i++){
        scanf("%d", &input);
        addLast(input);
    }

    printf("enter value for k : ");
    int k;
    scanf("%d", &k);

    sortDescInKGroups(k);

    printLL(head);

    return 0;
}
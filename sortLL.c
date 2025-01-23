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

struct Node* sortLL(struct Node* head){
    if(head == NULL || head->next == NULL) return head;
    struct Node* i = head;
    while(i != NULL){
        struct Node* j = head;
        while(j->next != NULL){
            if(j->data > j->next->data){
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

int main() {
    
    int nums;
    printf("no. of elements: ");
    scanf("%d", &nums);
    
    int input;
    for(int i=0; i<nums; i++){
        scanf("%d", &input);
        addLast(input);
    }

    head = sortLL(head);
    printLL(head);

    return 0;
}
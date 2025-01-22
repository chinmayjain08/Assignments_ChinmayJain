#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

int lengthLL(struct Node* head){
    struct Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
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

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* addLast(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}

struct Node* reverse(struct Node* head){
    if(head->next == NULL){
        return head;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    
    while(curr!=NULL){
        struct Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

struct Node* addLL(struct Node* head1, struct Node* head2){
    int carry = 0;
    struct Node* result = createNode(0);
    struct Node* temp = result;
    while(head1 != NULL || head2 != NULL || carry != 0){
        int sum = 0;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        int digit = sum%10;
        carry = sum/10;
        struct Node* newNode = createNode(digit);
        temp->next = newNode;
        temp = temp->next;
    }
    return result->next;
}

int main(){
    
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    char num1[100];
    char num2[100];
    
    printf("first num : ");
    fgets(num1, 100, stdin);
    num1[strcspn(num1, "\n")] = '\0';
    
    printf("second num : ");
    fgets(num2, 100, stdin);
    num2[strcspn(num2, "\n")] = '\0';
    
    for(int i=0; i<strlen(num1); i++){
        head1 = addLast(head1, num1[i] - '0');
    }
    
    for(int i=0; i<strlen(num2); i++){
        head2 = addLast(head2, num2[i] - '0');
    }
    
    
    printLL(head1);
    printLL(head2);
    
    head1 = reverse(head1);
    head2 = reverse(head2);
    
    struct Node* result = addLL(head1, head2);
    result = reverse(result);
    printLL(result);
    
}
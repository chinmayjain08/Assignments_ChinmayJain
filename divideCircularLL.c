#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void printCircularLL(struct Node* head){
    struct Node* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("%d ", temp->data);
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

// void printLL(struct Node* head){
//     struct Node* temp = head;
//     while(temp!=NULL){
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
//     return;
// }

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
    
    char list[100];
    printf("enter list : ");
    fgets(list, 100, stdin);
    list[strcspn(list, "\n")] = '\0';

    struct Node* head = NULL;
    
    for(int i=0; i<strlen(list); i++){
        if(list[i] != ' '){
            head = addLast(head, list[i] - '0');
        }
    }

    struct Node* front = head;
    while(front->next != NULL){
        front = front->next;
    }
    front->next = head;
    
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    printf("entered circular linked list : \n");
    printCircularLL(head);
    printf("\n");
    giveTwoCircLists(head, &head1, &head2);
    
    struct Node* temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head1;
    
    temp = head2;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    
    printf("resultant circular lists : \n");
    printCircularLL(head1);
    printf("\n");
    printCircularLL(head2);
    
    return 0;
}
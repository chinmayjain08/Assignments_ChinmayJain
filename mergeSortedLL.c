#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

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

struct Node* mergeTwoSorted(struct Node* head1, struct Node* head2){
    struct Node* result = createNode(0);
    struct Node* temp = result;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }

    if(head1 != NULL){
        temp->next = head1;
    }
    if(head2 != NULL){
        temp->next = head2;
    }

    result = result->next;

    return result;
}

int main(){

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    char list1[100];
    char list2[100];

    printf("first list : ");
    fgets(list1, 100, stdin);
    list1[strcspn(list1, "\n")] = '\0';
    
    printf("second list : ");
    fgets(list2, 100, stdin);
    list2[strcspn(list2, "\n")] = '\0';
    
    for(int i=0; i<strlen(list1); i++){
        if(list1[i] != ' '){
            head1 = addLast(head1, list1[i] - '0');
        }
    }
    
    for(int i=0; i<strlen(list2); i++){
        if(list2[i] != ' '){
            head2 = addLast(head2, list2[i] - '0');
        }
    }

    // printLL(head1);
    // printLL(head2);

    printf("merged and sorted linked list : \n");
    struct Node* mergedSorted = mergeTwoSorted(head1, head2);
    printLL(mergedSorted);

    return 0;
}
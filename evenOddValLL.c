#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addLast(int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void evenOddLL(){
    if(head == NULL || head->next == NULL){
        printLL(head);
        return;
    }
    Node* oddHead = NULL;
    Node* evenHead = NULL;
    Node* temp = head;
    Node* even = evenHead;
    Node* odd = oddHead;
    while(temp != NULL){
        if(temp->data % 2 == 0){
            if(!evenHead){
                evenHead = temp;
                even = evenHead;
            }
            else{
                even->next = temp;
                even = temp;
            }
        }else{
            if(!oddHead){
                oddHead = temp;
                odd = oddHead;
            }
            else{
                odd->next = temp;
                odd = temp;
            }
        }
        temp = temp->next;
    }
    
    odd->next = NULL;
    
    if(even){
        even->next = oddHead;
        printLL(evenHead);
    }else{
        printLL(oddHead);
    }
    
    return;
}

int main() {
    
    int size;
    printf("enter size of LL : ");
    scanf("%d", &size);

    printf("enter elements : ");
    int data;
    for(int i=0; i<size; i++){
        scanf("%d", &data);
        addLast(data);
    }

    evenOddLL();

    return 0;
}
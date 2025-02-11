#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int id;
    char* severity;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int id, char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->severity = (char*)malloc(100*sizeof(char));
    strcpy(newNode->severity, data);
    newNode->next = NULL;
    return newNode;
}

void addLast(int id, char* data){
    Node* newNode = createNode(id, data);
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
        printf("%d %s -> ", temp->id, temp->severity);
        temp = temp->next;
    }
    printf("\n");
}

void sortSeverity(){
    Node* normalHead = NULL;
    Node* criticalHead = NULL;
    Node* normal = normalHead;
    Node* critical = criticalHead;
    Node* temp = head;
    while(temp != NULL){
        if(strcmp(temp->severity, "normal") == 0){
            if(!normalHead){
                normalHead = temp;
                normal = normalHead;
            }else{
                normal->next = temp;
                normal = temp;
            }
        }else{
            if(!criticalHead){
                criticalHead = temp;
                critical = criticalHead;
            }else{
                critical->next = temp;
                critical = temp;
            }
        }
        temp = temp->next;
    }
    if(normalHead){
        normal->next = criticalHead;
        critical->next = NULL;
        printLL(normalHead);
    }else{
        printLL(criticalHead);
    }
    
}

int main(){

    int n;
    printf("enter number of patients: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int id;
        char* severity = (char*)malloc(100*sizeof(char));
        printf("enter patient id: ");
        scanf("%d", &id);
        // if(!isDigit(id)){
        //     while(!isDigit(id)){
        //         printf("enter correct id : ");
        //         scanf("%d", &id);
        //     }
        // }
        printf("enter patient severity: ");
        scanf("%s", severity);
        while(strcmp(severity, "normal") != 0 && strcmp(severity, "critical") != 0){
            printf("enter correct severity : ");
            scanf("%s", severity);
        }
        addLast(id, severity);
    }

    sortSeverity();

    return 0;
}
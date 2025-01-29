#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char* id;
    struct Node* next;
};

struct Node* createNode(char* data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->id, data);
    newNode->next = NULL;
    return newNode;
}

int lengthLL(struct Node* head) {
    struct Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void printLL(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%s ", temp->id);
        temp = temp->next;
    }
    printf("\n");
    return;
}

struct Node* addLast(struct Node* head, char* data){
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

int searchLL(struct Node* head, char* target){
    struct Node* temp = head;
    while(temp != NULL){
        if(strcmp(temp->id, target) == 0){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printCommonIDs(struct Node* head1, struct Node* head2){
    struct Node* smallerLL = lengthLL(head1) > lengthLL(head2) ? head2 : head1;
    struct Node* largerLL = head1;
    if(head1 == smallerLL){
        largerLL = head2;
    }else{
        largerLL = head1;
    }
    while(smallerLL != NULL){
        if(searchLL(largerLL, smallerLL->id) == 1){
            printf("%s ", smallerLL->id);
        }
        smallerLL = smallerLL->next;
    }
}

int main(){
    
    struct Node* tennisList = NULL;
    struct Node* foosballList = NULL;
    
    char* tennis = (char*)malloc(10001 * sizeof(char));
    char* foosball = (char*)malloc(10001 * sizeof(char)); 
    
    printf("enter ids of tennis players : \n");
    fgets(tennis, 10000, stdin);
    if(tennis[strlen(tennis)-1] == '\n'){
        tennis[strlen(tennis)-1] = '\0';
    }
    
    printf("enter ids of foosball players : \n");
    fgets(foosball, 10000, stdin);
    if(foosball[strlen(foosball)-1] == '\n'){
        foosball[strlen(foosball)-1] = '\0';
    }
    
    char* tennisPlayer = strtok(tennis, " ");
    while (tennisPlayer != NULL) {
        tennisList = addLast(tennisList, tennisPlayer);
        tennisPlayer = strtok(NULL, " ");
    }
    
    char* foosballPlayer = strtok(foosball, " ");
    while (foosballPlayer != NULL) {
        foosballList = addLast(foosballList, foosballPlayer);
        foosballPlayer = strtok(NULL, " ");
    }

    printLL(tennisList);
    printLL(foosballList);
    
    printCommonIDs(tennisList, foosballList);

    return 0;
}
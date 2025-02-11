#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char* fileName;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->fileName = (char*)malloc(100*sizeof(char));
    strcpy(newNode->fileName, data);
    newNode->next = NULL;
    return newNode;
}

void addLast(char* data){
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
        printf("%s ", temp->fileName);
        temp = temp->next;
    }
    printf("\n");
}

int filePresent(Node* head, char* data){
    Node* temp = head;
    while(temp != NULL){
        if(strcmp(temp->fileName, data) == 0){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void removeDuplicateFiles(){
    Node* temp = head;
    Node* newHead = NULL;
    Node* newTemp = NULL;
    while(temp != NULL){
        if(!newHead){
            newHead = createNode(temp->fileName);
            newTemp = newHead;
        }else{
            if(filePresent(newHead, temp->fileName) == 0){
                newTemp->next = createNode(temp->fileName);
                newTemp = newTemp->next;
            }
        }
        temp = temp->next;
    }
    printLL(newHead);
}

int main() {
    
    char* files = (char*)malloc(10001 * sizeof(char));
    printf("enter filenames : \n");
    fgets(files, 10000, stdin);
    if(files[strlen(files)-1] == '\n'){
        files[strlen(files)-1] = '\0';
    }
    
    char* file = strtok(files, " ");
    while (file != NULL) {
        addLast(file);
        file = strtok(NULL, " ");
    }

    removeDuplicateFiles();

    return 0;
}
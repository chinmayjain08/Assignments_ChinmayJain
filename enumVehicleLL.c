#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Priority{
    EMERGENCY,
    PUBLIC,
    PRIVATE
}Priority;

typedef struct Vehicle{
    int id;
    Priority type;
    char driver[25];
    struct Vehicle* next;
}Vehicle;

Vehicle* head = NULL;

Vehicle* createNode(int id, Priority type, char driverName[]){
    Vehicle* newNode = (Vehicle*)malloc(sizeof(Vehicle));
    newNode->id = id;
    newNode->type = type;
    strcpy(newNode->driver, driverName);
    newNode->next = NULL;
    return newNode;
}

void insertAtCorrectPosition(int id, Priority type, char driver[]){
    Vehicle* newVehicle = createNode(id, type, driver);
    if(head == NULL || head->type > type){
        newVehicle->next = head;
        head = newVehicle;
        return;
    }
    Vehicle* temp = head;
    while(temp->next != NULL && temp->next->type <= type){
        temp = temp->next;
    }
    newVehicle->next = temp->next;
    temp->next = newVehicle;
    return;
}

void printLL(){
    Vehicle* temp = head;
    printf("waiting vehicles : \n");
    while(temp != NULL){
        printf("%d %s ", temp->id, temp->driver);
        if(temp->type == EMERGENCY)printf("EMERGENCY\n");
        else if(temp->type == PUBLIC)printf("PUBLIC TRANSPORT\n");
        else printf("PRIVATE\n");
        temp = temp->next;
    }
    return;
}

void passVehicle(){
    if(head == NULL){
        printf("no vehicles to pass\n");
        return;
    }
    Vehicle* temp = head;
    printf("vehicle with id %d passed\n", temp->id);
    head = head->next;
    free(temp);
    return;
}

Priority getPriority(char priority[]){
    if(strcmp(priority, "EMERGENCY") == 0)return EMERGENCY;
    else if(strcmp(priority, "PUBLIC") == 0)return PUBLIC;
    else return PRIVATE;
}

int main() {
    
    int ops;
    printf("enter no. of operations : ");
    scanf("%d", &ops);
    int id, choice;
    char driverName[25];
    char priority[15];
    for(int i=0; i<ops; i++){
        printf("enter choice of operation : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter id : ");
                scanf("%d", &id);
                printf("enter type of vehicle : ");
                scanf("%s", priority);
                getchar();
                printf("enter driver name : ");
                fgets(driverName, 25, stdin);
                driverName[strcspn(driverName, "\n")] = '\0';
                insertAtCorrectPosition(id, getPriority(priority), driverName);
                break;
            case 2:
                passVehicle();
                break;
            case 3:
                printLL();
                break;
        }
    }
    
    return 0;
}
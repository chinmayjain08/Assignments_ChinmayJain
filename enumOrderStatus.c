// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Status{
    PENDING,
    SHIPPED,
    DELIVERED,
    CANCELLED
}Status;

typedef struct Order{
    int id;
    char name[50];
    Status status;
    struct Order* next;
}Order;

Order* head = NULL;

Order* createOrder(int id, char name[], Status status){
    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->id = id;
    newOrder->status = status;
    newOrder->next = NULL;
    strcpy(newOrder->name, name);
    return newOrder;
}

void insertAtCorrectPosition(int id, char name[], Status status){
    Order* newOrder = createOrder(id, name, status);
    if(head == NULL || head->status > status){
        newOrder->next = head;
        head = newOrder;
        return;
    }
    Order* temp = head;
    while(temp->next != NULL && temp->next->status <= status){
        temp = temp->next;
    }
    newOrder->next = temp->next;
    temp->next = newOrder;
    return;
}

void sortStatusById(){
    if(head == NULL || head->next == NULL)return;
    int tempId;
    char tempName[50];
    Status tempStatus;
    Order* temp = head;
    while(temp->next != NULL){
        while(temp->next != NULL && temp->status == temp->next->status && temp->id > temp->next->id){
            tempId = temp->id;
            temp->id = temp->next->id;
            temp->next->id = tempId;
                
            tempStatus = temp->status;
            temp->status = temp->next->status;
            temp->next->status = tempStatus;
                
            strcpy(tempName, temp->name);
            strcpy(temp->name, temp->next->name);
            strcpy(temp->next->name, tempName);
            temp = temp->next;
        }
        temp = temp->next;
    }
}

void removeFromQueue(){
    if(head == NULL){
        printf("khaali\n");
        return;
    }
    Order* temp = head;
    printf("id %d removed with name %s\n", temp->id, temp->name);
    head = head->next;
    free(temp);
    return;
}

void deleteByID(int id){
    if(head == NULL){
        printf("khaali\n");
        return;
    }
    Order* temp = head;
    if(head->id == id){
        printf("id %d removed with name %s\n", temp->id, temp->name);
    head = head->next;
    free(temp);
    return;
    }
    Order* prev = NULL;
    while(temp!=NULL && temp->id != id){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("id not present\n");
        return;
    }
    printf("id %d removed with name %s\n", temp->id, temp->name);
    prev->next = temp->next;
    temp->next = NULL;
    free(temp);
    return;
}

void printWaiting(){
    if(head == NULL){
        printf("khaali\n");
        return;
    }
    Order* temp = head;
    while(temp != NULL){
        printf("id : %d name : %s status : ", temp->id, temp->name);
        if(temp->status == 0)printf("PENDING");
        if(temp->status == 1)printf("SHIPPED");
        if(temp->status == 2)printf("DELIVERED");
        if(temp->status == 3)printf("CANCELLED");
        printf("\n");
        temp = temp->next;
    }
}

Status getStatus(char status[]){
    if(strcmp(status, "PENDING") == 0)return 0;
    if(strcmp(status, "SHIPPED") == 0)return 1;
    if(strcmp(status, "DELIVERED") == 0)return 2;
    if(strcmp(status, "CANCELLED") == 0)return 3;
}

void sortByStatus(){
    Order* i = NULL;
    Order* j = NULL;
    int tempId;
    char tempName[50];
    Status tempStatus;
    int swapped = 1;
    for(i=head; i!=NULL; i=i->next){
        swapped = 0;
        for(j=head; j->next!=NULL; j=j->next){
            if(j->status > j->next->status){
                tempId = j->id;
                j->id = j->next->id;
                j->next->id = tempId;
                
                tempStatus = j->status;
                j->status = j->next->status;
                j->next->status = tempStatus;
                
                strcpy(tempName, j->name);
                strcpy(j->name, j->next->name);
                strcpy(j->next->name, tempName);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
    return;
}

void updateStatus(int id, char* status){
    if(head == NULL){
        printf("khaali\n");
        return;
    }
    Order* temp = head;
    while(temp != NULL && temp->id != id){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("id not found\n");
        return;
    }
    temp->status = getStatus(status);
    sortByStatus();
    return;
}

int main() {
    int ops;
    printf("operations : ");
    scanf("%d", &ops);
    
    int choice, id;
    char name[50];
    char status[15];
    
    for(int i=0; i<ops; i++){
        printf("enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter id : ");
                scanf("%d", &id);
                getchar();
                printf("enter name : ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("enter status : ");
                scanf("%s", status);
                insertAtCorrectPosition(id, name, getStatus(status));
                break;
            case 2:
                removeFromQueue();
                break;
            case 3:
                sortStatusById();
                printWaiting();
                break;
            case 4:
                printf("enter id to delete: ");
                scanf("%d", &id);
                deleteByID(id);
                break;
            case 5:
                printf("enter id to update status : ");
                scanf("%d", &id);
                printf("enter updated status: ");
                scanf("%s", status);
                updateStatus(id, status);
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    }
    
    return 0;
}
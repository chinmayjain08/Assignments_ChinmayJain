#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Flag{
    GREEN,
    SHAYAD_GREEN,
    YELLOW,
    RED,
    PAKKA_RED
}Flag;

typedef struct Trainee{
    int id;
    char* name;
    Flag rating;
    struct Trainee* next;
}Trainee;

Trainee* createTrainee(int id, char* name, Flag rating){
    Trainee* newTrainee = (Trainee*)malloc(sizeof(Trainee));
    newTrainee->id = id;
    newTrainee->name = strdup(name);
    newTrainee->rating = rating;
    newTrainee->next = NULL;
    return newTrainee;
}

Trainee* head = NULL;

void insertAtRightPlace(int id, char* name, Flag rating){
    Trainee* newTrainee = createTrainee(id, name, rating);
    if(head == NULL || head->rating > rating){
        newTrainee->next = head;
        head = newTrainee;
        return;
    }
    Trainee* temp = head;
    while(temp->next != NULL && temp->next->rating <= rating){
        temp = temp->next;
    }
    newTrainee->next = temp->next;
    temp->next = newTrainee;
    return;
}

void printSorted(){
    Trainee* temp = head;
    while(temp != NULL){
        printf("id: %d name: %s ", temp->id, temp->name);
        if(temp->rating == 0)printf("GREEN");
        else if(temp->rating == 2)printf("YELLOW");
        else if(temp->rating == 1)printf("SHAYAD GREEN");
        else if(temp->rating == 3)printf("RED");
        else printf("PAKKA RED");
        printf("\n");
        temp = temp->next;
    }
}

Flag getRating(char* rating){
    if(strcmp(rating, "GREEN") == 0)return 0;
    else if(strcmp(rating, "SHAYAD_GREEN") == 0)return 1;
    else if(strcmp(rating, "YELLOW") == 0)return 2;
    else if(strcmp(rating, "RED") == 0)return 3;
    else if(strcmp(rating, "PAKKA_RED") == 0)return 4;
}

int main() {
    
    int ops;
    printf("enter number of operations : ");
    scanf("%d", &ops);
    
    int choice, id;
    char* name = (char*)malloc(25 * sizeof(char));
    char* rating = (char*)malloc(25 * sizeof(char));
    
    for(int i=0; i<ops; i++){
        printf("enter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter id: ");
                scanf("%d", &id);
                printf("enter rating : ");
                scanf("%s", rating);
                getchar();
                printf("enter name : ");
                fgets(name, 25, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertAtRightPlace(id, name, getRating(rating));
                break;
            case 2:
                printSorted();
                break;
            default:
                printf("invalid choice\n");
                break;
        }    
    }
    return 0;
}
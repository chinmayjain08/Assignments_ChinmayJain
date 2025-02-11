#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum Rating{
    PRO,
    EXPERIENCED,
    BEGINNER
}Rating;

typedef struct Player{
    char* name;
    int id;
    Rating rating;
    struct Player* next;
}Player;

Player* head = NULL;

Player* createPlayer(int id, char* name, Rating rating){
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    newPlayer->id = id;
    newPlayer->rating = rating;
    newPlayer->name = strdup(name);
    return newPlayer;
}

void insertAtCorrectPosition(int id, char* name, Rating rating){
    Player* newPlayer = createPlayer(id, name, rating);
    if(head == NULL || head->rating > rating){
        newPlayer->next = head;
        head = newPlayer;
        return;
    }
    Player* temp = head;
    while(temp->next != NULL && temp->next->rating <= rating){
        temp = temp->next;
    }
    newPlayer->next = temp->next;
    temp->next = newPlayer;
    return;
}

void getPlayer(){
    if(head == NULL){
        printf("no players in queue\n");
        return;
    }
    Player* temp = head;
    head = head->next;
    printf("player with id %d and name %s is playing now\n", temp->id, temp->name);
    free(temp);
    return;
}

void displayWaiting(){
    if(head == NULL){
        printf("no players in queue\n");
        return;
    }
    Player* temp = head;
    while(temp != NULL){
        printf("player id : %d, name : %s ", temp->id, temp->name);
        if(temp->rating == PRO)printf("PRO");
        else if(temp->rating == 1)printf("EXPERIENCED");
        else printf("BEGINNER");
        printf("\n");
        temp = temp->next;
    }
    return;
}

Rating getRating(char* rating){
    if(strcmp(rating, "PRO") == 0)return PRO;
    else if(strcmp(rating, "EXPERIENCED") == 0)return EXPERIENCED;
    else return BEGINNER;
}

int main(){
    int ops;
    printf("operations : ");
    scanf("%d", &ops);
    
    char* name = (char*)malloc(100 * sizeof(char));
    char* rating = (char*)malloc(100 * sizeof(char));
    int id, choice;
    
    for(int i=0; i<ops; i++){
        printf("1. register player\n");
        printf("2. get playing player\n");
        printf("3. get waiting players\n");
        printf("enter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter details : ");
                scanf("%d %s", &id, rating);
                getchar();
                fgets(name, 99, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertAtCorrectPosition(id, name, getRating(rating));
                break;
            case 2:
                getPlayer();
                break;
            case 3:
                displayWaiting();
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    }
    
    return 0;
}
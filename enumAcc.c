#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum AccType{
    PREMIUM,
    REGULAR,
    SAVINGS
}AccType;

typedef struct Account{
    int id;
    char name[25];
    AccType type;
    struct Account* next;
}Account;

Account* head = NULL;

Account* createAccount(int id, char name[], AccType type){
    Account* newAccount = (Account*)malloc(sizeof(Account));
    newAccount->id = id;
    strcpy(newAccount->name, name);
    newAccount->type = type;
    return newAccount;
}

void insertAtCorrectPosition(int id, char name[], AccType type){
    Account* newAccount = createAccount(id, name, type);
    if(head == NULL || type < head->type){
        newAccount->next = head;
        head = newAccount;
        return;
    }
    Account* temp = head;
    while(temp->next!=NULL && temp->next->type <= type){
        temp = temp->next;
    }
    newAccount->next = temp->next;
    temp->next = newAccount;
    return;
}

void serveAccount(){
    if(head == NULL){
        printf("no account\n");
        return;
    }
    printf("account with id %d and name %s served\n", head->id, head->name);
    Account* temp = head;
    head = head->next;
    free(temp);
    return;
}

void printLL(){
    Account* temp = head;
    while(temp != NULL){
        printf("%d %s ", temp->id, temp->name);
        if(temp->type == 0)printf("PREMIUM");
        else if(temp->type == 1)printf("REGULAR");
        else printf("SAVINGS");
        printf("\n");
        temp = temp->next;
    }
}

AccType getType(char type[]){
    if(strcmp(type, "PREMIUM") == 0)return PREMIUM;
    else if(strcmp(type, "REGULAR") == 0)return REGULAR;
    else return SAVINGS;
}

int main() {
    
    int ops;
    printf("enter number of operations : ");
    scanf("%d", &ops);
    
    int choice, id;
    char name[25];
    char type[15];
    
    for(int i=0; i<ops; i++){
        printf("enter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter details : ");
                scanf("%d %s", &id, type);
                getchar();
                fgets(name, 25, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertAtCorrectPosition(id, name, getType(type));
                break;
            case 2:
                serveAccount();
                break;
            case 3:
                printLL();
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef enum AccType{
//     PREMIUM,
//     REGULAR,
//     SAVINGS
// }AccType;

// typedef struct Account{
//     int id;
//     char name[25];
//     AccType type;
//     struct Account* next;
// }Account;

// Account* head = NULL;

// Account* createAccount(int id, char name[], AccType type){
//     Account* newAccount = (Account*)malloc(sizeof(Account));
//     newAccount->id = id;
//     strcpy(newAccount->name, name);
//     newAccount->type = type;
//     return newAccount;
// }

// void insertAtCorrectPosition(int id, char name[], AccType type){
//     Account* newAccount = createAccount(id, name, type);
//     if(head == NULL || type < head->type){
//         newAccount->next = head;
//         head = newAccount;
//         return;
//     }
//     Account* temp = head;
//     while(temp->next!=NULL && temp->next->type <= type){
//         temp = temp->next;
//     }
//     newAccount->next = temp->next;
//     temp->next = newAccount;
//     return;
// }

// void serveAccount(){
//     if(head == NULL){
//         printf("no account\n");
//         return;
//     }
//     printf("account with id %d and name %s served\n", head->id, head->name);
//     Account* temp = head;
//     head = head->next;
//     free(temp);
//     return;
// }

// void printLL(){
//     Account* temp = head;
//     if(head == NULL){
//         printf("no accounts\n");
//         return;
//     }
//     while(temp != NULL){
//         printf("%d %s ", temp->id, temp->name);
//         if(temp->type == 0)printf("PREMIUM");
//         else if(temp->type == 1)printf("REGULAR");
//         else printf("SAVINGS");
//         printf("\n");
//         temp = temp->next;
//     }
// }

// // AccType getType(char type[]){
// //     if(strcmp(type, "PREMIUM") == 0)return PREMIUM;
// //     else if(strcmp(type, "REGULAR") == 0)return REGULAR;
// //     else return SAVINGS;
// // }

// int main() {
    
//     int ops;
//     printf("enter number of operations : ");
//     scanf("%d", &ops);
    
//     int choice, id, type;
//     char name[25];
    
//     for(int i=0; i<ops; i++){
//         printf("enter choice : ");
//         scanf("%d", &choice);
//         switch(choice){
//             case 1:
//                 printf("enter details : ");
//                 scanf("%d %d", &id, &type);
//                 getchar();
//                 fgets(name, 25, stdin);
//                 name[strcspn(name, "\n")] = '\0';
//                 insertAtCorrectPosition(id, name, type);
//                 break;
//             case 2:
//                 serveAccount();
//                 break;
//             case 3:
//                 printLL();
//                 break;
//             default:
//                 printf("inavlid choice\n");
//                 break;
//         }
//     }

//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME "users.txt"

typedef struct {
    int id;
    char name[25];
    int age;
} User;


// function to create a file if it doesn't already exists
void createFile(){
    FILE *fptr = fopen(FILE_NAME, "a");
    if(fptr) fclose(fptr); 
}


// function to add user to file
void addUser(){
    FILE *fptr = fopen(FILE_NAME, "a");

    if(!fptr){
        printf("Error opening file \n");
        return;
    }

    User user;
    printf("enter user id : ");
    scanf("%d", &user.id);
    getchar();
    printf("enter name of user : ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = 0;
    printf("enter age of user : ");
    scanf("%d", &user.age);
    
    fprintf(fptr, "%d, %s, %d\n", user.id, user.name, user.age);
    fclose(fptr);
    printf("User added successfull \n");
}


// function to display existing users
void displayUsers(){
    FILE *fptr = fopen(FILE_NAME, "r");
    if(!fptr){
        printf("Error opening file");
        return;
    }

    User user;
    while(fscanf(fptr, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF){
        printf("%d\t%-25s%d\n", user.id, user.name, user.age);
    }

    fclose(fptr);
}


// function to update user data
void updateUser(){
    FILE *fptr = fopen(FILE_NAME, "r");
    if(!fptr){
        printf("Error opening file");
        return;
    }

    int id, found = 0;
    printf("enter id of user to update: ");
    scanf("%d", &id);
    getchar();

    User user;
    FILE *temp = fopen("temp.txt", "w");
    if(!temp){
        printf("Error in creating temporary file");
        fclose(fptr);
        return;
    }

    while(fscanf(fptr, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF){
        if(user.id == id){
            found = 1;
            printf("enter new name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = 0;
            printf("enter new age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(fptr);
    fclose(temp);

    if(found){
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("user updated successfully\n");
    }else{
        remove("temp.txt");
        printf("user with id %d not found\n", id);
    }
}


// function to delete user
void deleteUser(){
    FILE *fptr = fopen(FILE_NAME, "r");
    if(!fptr){
        printf("Error opening file\n");
        return;
    }

    int id, found = 0;
    printf("enter the id of user to delete: ");
    scanf("%d", &id);

    User user;
    FILE *tempFile = fopen("temp.txt", "w");
    if(!tempFile){
        printf("Error creating temporary file \n");
        fclose(fptr);
        return;
    }

    while(fscanf(fptr, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF){
        if(user.id != id){
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        }else{
            found = 1;
        }
    }

    fclose(fptr);
    fclose(tempFile);

    if(found){
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("user deleted successfully. \n");
    }else{
        remove("temp.txt");
        printf("user with id %d not found. \n", id);
    }
}


int main(){

    int choice;

    createFile();
    
    do{
        printf("\n\n Choose Operation to perform: \n");
        printf("1. Add User\n");
        printf("2. Display User\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. EXIT\n\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 5);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findString(char* str, char* toFind){
    for(int i=0; i<strlen(str)-strlen(toFind); i++){
        int j=0;
        while(toFind[j] != '\0' && str[i+j] == toFind[j]){
            j++;
        }
        if(j == strlen(toFind))return i;
    }

    return -1;
}

int main(){

    char str[100] = "";
    char toFind[100] = "";

    printf("enter the string : ");
    scanf("%[^\n]%*c", &str);

    printf("enter the string to find : ");
    scanf("%[^\n]%*c", &toFind);

    int index = findString(str, toFind);
    printf("string present at index : %d", index);

    return 0;
}
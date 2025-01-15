#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int toFindStr(char* str, char*toFind){
    for(int i=0; i<(strlen(str)-strlen(toFind)); i++){
        int j = 0;
        while(j<strlen(toFind) && str[i+j]==toFind[j]){
            j++;
        }
        if(j==strlen(toFind))return 1;
    }
    return 0;
}

void strconcat(char* str, char* str2, char* result){
    int index = 0;
    for(int i=0; i<strlen(str); i++){
        result[index++] = str[i];
    }
    for(int i=0; i<strlen(str2); i++){
        result[index++] = str2[i];
    }
    result[index] = '\0';
}

void checkRotation(char str[100], char str2[100]){
    int len = strlen(str);
    int len2 = strlen(str2);
    if(len != len2){
        printf("not a rotation\n");
        return;
    }

    char result[100] = "";

    strconcat(str,str,result);

    if(toFindStr(result, str2)){
        printf("rotation\n");
    }else{
        printf("not rotation\n");
    }
}

int main(){

    printf("enter string : ");
    char str[100] = "";
    scanf("%s", &str);
    
    printf("enter string to check rotation : ");
    char str2[100] = "";
    scanf("%s", &str2);

    checkRotation(str, str2);

    return 0;
}
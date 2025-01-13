#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int startIndex(char* str1, char* str2, int offset){
    int first = *str1;
    for(int i=offset; i<strlen(str2); i++){
        if(first == str2[i]) return i;
    }
    return -1;
}

int findIfRotation(char* str1, char* str2){
    if(strlen(str1) != strlen(str2)) return 0;
    int secIndex = startIndex(str1, str2, 0);
    int index = 0;
    if(secIndex==-1) return 0;

    while(index < strlen(str1)){
        if(str1[index] != str2[secIndex]){
            index = 0;
            secIndex = startIndex(str1, str2, secIndex + 1);
            if(secIndex == -1) return 0;
            continue;
        }
        index++;
        secIndex = (secIndex+1) % strlen(str2);
    }

    return 1;
}

int main(){

    char str1[100] = "";
    char str2[100] = "";

    fgets(str1, 100, stdin);
    if(str1[strlen(str1)-1] == '\n'){
        str1[strlen(str1)-1] = '\0';
    }

    fgets(str2, 100, stdin);
    if(str2[strlen(str2)-1] == '\n'){
        str2[strlen(str2)-1] = '\0';
    }

    int result = findIfRotation(str1, str2);
    if(result){
        printf("str2 is rotation of str1\n");
    }else{
        printf("str2 is not rotation of str1\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int strlength(char* str){
    char* s = str;
    int len = 0;
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}

void eliminateGivenLetter(char* str, char* newStr, char ch){
    int j = 0;
    for(int i=0; i<strlength(str); i++){
        if(str[i] == ch){
            continue;
        }
        newStr[j] = str[i];
        j++;
    }
    newStr[j] = '\0';
}

int main(){

    char str[100] = "";
    printf("enter the string : ");
    scanf("%[^\n]%*c", &str);

    char ch = '0';
    printf("enter the character to remove : ");
    scanf("%c", &ch);

    char newStr[100] = "";

    eliminateGivenLetter(str, newStr, ch);

    printf("new string : ");
    printf("%s", newStr);

    return 0;
}
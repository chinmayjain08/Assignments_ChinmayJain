#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char str[101] = "";
    fgets(str, 100, stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    int wordCount = 0;

    for(int i=0; i<strlen(str); i++){
        if(str[i] == ' '){
            continue;
        }else if(str[i] != ' '){
            while(str[i] != ' ' && str[i] != '\0'){
                i++;
            }
            wordCount++;
        }
    }

    printf("words : %d\n", wordCount);

    return 0;
}
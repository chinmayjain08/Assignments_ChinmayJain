#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int isAnagram(char str[], char str2[]){

    if(strlen(str) != strlen(str2)){
        return 0;
    }

    int freq[123] = {0};
    for(int i=0; i<strlen(str); i++){
        freq[str[i]]++;
    }

    for(int i=0; i<strlen(str); i++){
        freq[str2[i]]--;
    }

    for(int i=0; i<123; i++){
        if(freq[i] != 0){
            return 0;
        }
    }

    return 1;
}

int main(){

    char str[100];
    char str2[100];

    scanf("%s", &str);
    scanf("%s", &str2);

    int result = isAnagram(str, str2);

    if(result){
        printf("strings are anagrams\n");
    }else{
        printf("strings not anagrams\n");
    }

    return 0;
}
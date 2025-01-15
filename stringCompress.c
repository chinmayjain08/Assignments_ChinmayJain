#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char* nums, int stIdx, int endIdx){
    while(stIdx < endIdx){
        char temp = nums[stIdx];
        nums[stIdx] = nums[endIdx];
        nums[endIdx] = temp;
        stIdx++;
        endIdx--;
    }
}

void getCompressedString(char* str){
    char compressed[100];

    int index = 0;
    for(int i=0; i<strlen(str); i++){
        int count = 0;
        char ch = str[i];
        while(i<strlen(str) && str[i] == ch){
            count++;
            i++;
        }
        compressed[index++] = ch;
        if(count > 1){
            int countIdx = index;
            while(count){
                compressed[index++] = (count % 10) + '0';
                count = count/10;
            }
            reverse(compressed, countIdx, index-1);
        }
        i--;
    } 

    printf("%s\n", compressed);
}

int main(){

    char str[100];
    printf("enter the string : ");
    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    getCompressedString(str);

    return 0;
}
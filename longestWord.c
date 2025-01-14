#include<stdio.h>
#include<stdlib.h>

int main(){

    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%[^\n]%*c", str);

    printf("%s\n", str);

    int maxCount = 0;
    int count = 0;
    int wordCount = 0;

    int index = 0;
    int longest = 0;
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            index = i;
            while(str[i] != ' ' && str[i] != '\0'){
                count++;
                i++;
            }
            i--;
            if(count >= maxCount){
                longest = index;
                maxCount = count;
            }
            wordCount++;
        }else{
            count = 0;
        }
    }

    // printf("maxCount : %d\n", maxCount);
    // printf("wordCount : %d\n", wordCount);
    printf("longest word : ");
    while(str[longest] != ' ' && str[longest] != '\0')
        printf("%c", str[longest++]);
    printf("\n");

    return 0;
}
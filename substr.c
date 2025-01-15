#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getSubstring(char* str, int index, int length, char*substr){
    int subIdx = 0;
    for(int i=index; length != 0 && str[i] != '\0'; i++){
        substr[subIdx++] = str[i];
        length--;
    }
    substr[subIdx] = '\0';
}

int main(){
    
    char *str = (char*)malloc(100 * sizeof(char));
    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    
    int index;
    printf("enter index to get substring from : ");
    scanf("%d", &index);
    int len;
    printf("enter len of substring to get : ");
    scanf("%d", &len);
    
    char *substr = (char*)malloc(100 * sizeof(char));
    getSubstring(str, index, len, substr);
    
    printf("resultant substring : %s\n", substr);
    return 0;
}
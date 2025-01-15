#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char str[100] = "";
    scanf("%s", &str);

    char result[100] = "";
    int index = 0;

    result[index++] = str[0];

    for(int i=1; str[i] != '\0'; i++){
        if(str[i] != result[index-1]){
            result[index++] = str[i];
        }else{
            result[index-1] = '\0';
            if(index>0)
                index--;
        }
    }

    index++;
    result[index] = '\0';
    
    printf("%s\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dupCheckRemove(char *str){
    int freq[123] = {0};
    for(int i=0; i<strlen(str); i++){
        freq[str[i]]++;
    }
    for(int i=0; i<strlen(str); i++){
        if(freq[str[i]]){
            printf("%c",str[i]);
            freq[str[i]] = 0;
        }
    }
}

int main(){
    
    char str[100] = "";
    scanf("%s", &str);
    getchar();
    
    dupCheckRemove(str);
    
    return 0;
}
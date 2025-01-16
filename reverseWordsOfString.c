#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str, int st, int en){
    while(st < en){
        char temp = str[st];
        str[st] = str[en];
        str[en] = temp;
        st++; en--;
    }
    return;
}

void reverseWords(char* str){
    int len = strlen(str);
    reverse(str, 0, len-1);
    for(int i=0; i<len; i++){
        int index = 0;
        if(str[i] != ' '){
            index = i;
            while(str[i] != ' ' && i<len){
                i++;
            }
            reverse(str, index, i-1);
        }
    }
    
    printf("%s\n", str);
}

int main() {
    
    char* str = (char*)malloc(1001 * sizeof(char));
    fgets(str, 1001, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    reverseWords(str);

    return 0;
}
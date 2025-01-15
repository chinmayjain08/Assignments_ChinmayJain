#include <stdio.h>
#include <string.h>

void strcopy(char* str, char*copyTo, int st, int len){
    for(int i=0; i<len; i++){
        copyTo[i] = str[st];
        st++;
    }
    copyTo[st] = '\0';
}

int palindromicSubstr(char* str, int i, int j, char longest[100]){
    int len = 0;
    int maxLen = 0;
    while(i>=0 && j<strlen(str) && str[i]==str[j]){
        len = j-i+1;
        if(len > maxLen){
            maxLen = len;
            strcopy(str, longest, i, maxLen);
        }
        i--;
        j++;
    }
    return maxLen;
}

int main() {
    
    char str[100];
    printf("enter string to find longest palindromic substring : ");
    scanf("%s", str);
    int oddMaxLen = 0;
    int evenMaxLen  = 0;
    char longest[100]="";
    char templongest[100]="";

    for(int center = 0; center < strlen(str); center++){
        int oddLen = palindromicSubstr(str, center, center, templongest);
        if(oddLen > oddMaxLen){
            oddMaxLen = oddLen;
            if(oddMaxLen > evenMaxLen){
                strcopy(templongest, longest,0, oddLen);
            }
        }
        int evenLen = palindromicSubstr(str, center, center + 1, templongest);
        if(evenLen > evenMaxLen){
            evenMaxLen = evenLen;
            if (evenMaxLen > oddMaxLen){
                strcopy(templongest, longest,0, evenLen);
            }
        }
    }
    
    printf("longest palindromic substring : %s\n", longest);

    return 0;
}
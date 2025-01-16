#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isDigit(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    return 0;
}

int main(){
    
    char* str = (char*)malloc(1001 * sizeof(char));
    fgets(str, 1001, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    if(*str == '\0'){
        printf("null\n");
        return 0;
    }
    
    if(*str == ':'){
        printf("colon\n");
        return 0;
    }
    int colCount = 0;
    while(*str != '\0'){
        
        if(*str != ':'){
            int num = 0;
            int digitCount = 0;
            while(isDigit(*str) && *str != ':'){
                num = num*10 + (*str-'0');
                digitCount++;
                str++;
            }
            if(colCount == 0 && (num < 0 || digitCount > 2 || num > 23 || digitCount < 1)){
                printf("invalid hour\n");
                return 0;
            }
            if(colCount == 1 && (num < 0 || digitCount > 2 || num > 59 || digitCount < 1)){
                printf("invalid mins\n");
                return 0;
            }
            if(colCount == 2 && (num < 0 || digitCount > 2 || num > 59 || digitCount < 1)){
                printf("invalid secs\n");
                return 0;
            }
        }else if(*str == ':'){
            colCount++;
            str++;
            if(*str+1 == ':' || *str+1 == '\0'){
                printf("invalid colon");
                return 0;
            }
        }else{
            printf("invalid\n");
            return 0;
        }
    }
    
    printf("valid\n");
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strlength(char* input){
    char* ch = input;
    int len = 0;
    while(*ch != '\0'){
        len++;
        ch++;
    }
    return len;
}

int isDigit(char num){
    if(num >= '0' && num <= '9') return 1;
    else return 0;
}

int validIPAdress(char* input){
    int digitCount = 0;
    int dotCount = 0;
    char* str = input;

    if(str == NULL) return 0;
    //empty

    if(*str == '.') return 0;

    while(*str != '\0'){

        int num = 0;
        digitCount = 0;

        // for numbers
        if(isDigit(*str)){
            while(isDigit(*str)){
                num = num * 10 + (*str - '0');
                if(num == 0){
                    if(*(str+1) != '\0' && *(str+1) != '.') {
                        // printf("zero case");
                        return 0;
                    }
                }
                str++;
                digitCount++;
            }

            if(digitCount == 0 || digitCount > 3 || num > 255 || num < 0){
                // printf("number check");
                return 0;
            }

            // fordot(.)
        }else if(*str == '.'){
            dotCount++;
            if(*(str+1) == '.' || *(str+1) == '\0'){
                // printf("dot case\n");
                return 0;
            }
            str++;

            // for other characters
        }else if(*str != '\0'){
            // printf("invalid character\n");
            return 0;
        }
    }

    if(dotCount != 3) return 0;

    return 1;
}

int main(){

    char* inputString = (char*)malloc(16 * sizeof(char));
    scanf("%s", inputString);

    if(validIPAdress(inputString)){
        printf("Valid\n");
    }else{
        printf("Invalid\n");
    }

    return 0;
}

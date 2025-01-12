#include<stdio.h>
#include<stdlib.h>

int isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int atoiFunc(char* number){
    char sign = '+';
    int validNum = 1;
    int ans = 0;

    int index = 0;

    if(number[index]=='-'){
        sign = '-';
        index++;
    }

    if(isDigit(number[index])){
        while(isDigit(number[index])){
            ans = ans * 10 + (number[index] - '0');
            index++;
        }
        if(sign == '-'){
            ans *= -1;
        }
    }else{
        validNum = 0;
    }

    if(!validNum) return -1;

    return ans;
}

int strlength(char* str){
    char* ptr = str;
    int len = 0;
    while(*ptr != '\0'){
        ptr++;
        len++;
    }
    return len;
}

int main(){

    char number[10];
    printf("enter number in string format: ");
    scanf("%s", &number);

    printf("length : %d\n", strlength(number));

    int ans = atoiFunc(number);

    if(ans != -1){
        printf("integer: %d\n", ans);
    }else{
        printf("not a valid number");
    }

    return 0;
}
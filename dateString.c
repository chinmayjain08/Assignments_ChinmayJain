#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        return 1;
    }
    return 0;
}

int checkDateMonth(int date, int month, int year){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 10 || month == 12){
        if(date > 0 && date <= 31) return 1;
    }else if(month == 4 || month == 6 || month == 8 || month == 9 || month == 11){
        if(date > 0 && date <= 30) return 1;
    }else{
        if(isLeapYear(year)){
            if(date > 0 && date <= 29){
                printf("leap year\n");
                return 1;
            }
        }else{
            if(date > 0 && date <= 28) return 1;
        }
    }
    return 0;
}

int main(){

    char str[100];
    printf("enter date in DD/MM/YYYY format: ");
    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    if(strlen(str) != 10){
        printf("invalid\n");
        return 0;    
    }

    int slashCount = 0;
    int isValid = 1;

    if(str[0] == '/'){
        printf("invalid string entered\n");
        printf("enter date in DD/MM/YYYY format");
    }

    int date, month, year;

    for(int index = 0; index < strlen(str); index++){
        if(isDigit(str[index])){
            int num = 0;
            int digits = 0;
            while(isDigit(str[index])){
                num = num*10 + (str[index] - '0');
                index++;
                digits++;
            }
            index--;
            if(slashCount == 0 && (digits != 2 || num < 0 || num > 31)){
                printf("invalid date\n");
                isValid = 0;
                break;
            }else if(slashCount == 1 && (digits != 2 || num < 0 || num > 12)){
                printf("invalid month\n");
                isValid = 0;
                break;
            }else if(slashCount == 2 && (digits != 4 || num < 1800 || num > 2025)){
                printf("invalid year\n");
                break;
            }
            if(slashCount == 0) date = num;
            if(slashCount == 1) month = num;
            if(slashCount == 2) year = num;
        }else if(str[index] == '/'){
            slashCount++;
        }else{
            printf("invalid character\n");
            isValid = 0;
            break;
        }
    }

    if(isValid && slashCount == 2){
        if(checkDateMonth(date, month, year)){
            printf("valid date string entered!\n");
        }else{
            printf("invalid date entered for the month\n");
        }
    }else{
        printf("not a valid format date string\n");
    }

    return 0;
}
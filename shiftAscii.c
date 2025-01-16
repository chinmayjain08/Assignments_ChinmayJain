#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPrime(int num){
    if(num < 2)return 0;
    for(int i=2; i<num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[100];
    fgets(str, 100, stdin);
    int len = strlen(str);
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
    }

    int shift;
    scanf("%d", &shift);

    for(int i=0; i<len; i++){
        if(isPrime(i) && str[i] != ' '){
            int val = str[i] + shift;
            if(val > 122){
                int diff = val - 123;
                str[i] = 'a'+ (char)diff;
            }else{
                str[i] = (char)val;
            }
        }
    }

    printf("%s\n", str);

    return 0;
}